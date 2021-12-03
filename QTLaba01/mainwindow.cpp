// var 5
// Rustamova Darina
/*Студенты с кафедры робототехники запускают радиоуправляемый автомобиль.На автомобиль ещё не успели поставить GPS - модуль,
поэтому его местоположение приходится вычислять по переданным с пульта командам.Напишите программу, позволяющую определить
координаты автомобиля на основании переданных с пульта команд.
1. Команда движения : Шаг с параметрами текущее время, скорость
2. Последовательность команд(очередь команд движения и поворота) : расчёт координат автомобиля в заданное время
3. Команда поворота : текущее время, радиус поворота(положительный - против часовой стрелки, отрицательный - по часовой) */

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Queue.h"
#include "CommandsMoving.h"
#include <QtWidgets>
#include <QMessageBox>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <map>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void print(const Queue& queue) {                    // print queue
    Queue::Iterator iter;

    for (iter = queue.begin(); iter != queue.end(); iter++) {
        cout << iter << ": " << *iter << endl;
    }
}

map<string, Queue> queues;

void MainWindow::test_reading(const Queue& queue, const string& file_name, const string& queue_name){
    ui->radioButton_read->setChecked(true);
    ui->file_name->setText(QString::fromStdString(file_name));
    ui->queue_name_get->setText(QString::fromStdString(queue_name));
    on_get_result_clicked();

    assert(queues.count(queue_name) == 1);
    assert(queues[queue_name] == queue);
}

void MainWindow::test_saving(const string& file_name, const string& queue_name) {
    ui->radioButton_write->setChecked(true);
    ui->file_name->setText(QString::fromStdString(file_name));
    ui->queue_name_get->setText(QString::fromStdString(queue_name));
    on_get_result_clicked();
}

void MainWindow::test_enqueue(const Queue& queue, const string& data, const string& queue_name) {
    ui->data_for_add->setText(QString::fromStdString(data));
    ui->queue_name_change->setText(QString::fromStdString(queue_name));
    on_add_command_clicked();

    assert(queues[queue_name] == queue);
}

void MainWindow::test_dequeue(const Queue& queue, const string& queue_name) {
    ui->queue_name_change->setText(QString::fromStdString(queue_name));
    on_delete_first_clicked();

    assert(queues[queue_name] == queue);
}

void MainWindow::test_comparing(const bool& true_res, const string& q_name_1, const string& q_name_2) {
    ui->queue_name_1->setText(QString::fromStdString(q_name_1));
    ui->queue_name_2->setText(QString::fromStdString(q_name_2));
    on_compare_clicked();

    bool r;
    string result = ui->textBrowser->toPlainText().toStdString();
    r = (result == "Они равны");

    assert(true_res == r);
}

void MainWindow::test_coord(const string& queue_name, const vector<int>& true_coord) {
    ui->queue_name_coord->setText(QString::fromStdString(queue_name));
    on_get_coord_clicked();

    string coord = ui->textBrowser->toPlainText().toStdString();
    string text_true_coord = "x = " + std::to_string(true_coord[0]) + " y = " + std::to_string(true_coord[1]);

    assert(text_true_coord == coord);
}

void MainWindow::test() {
    // загрузка очереди из файла
    ifstream input("input.txt");
    Queue queue1;
    queue1.load_file(input);

    test_reading(queue1, "input.txt", "1");

    // добавление
    MoveCommand m(10, 2);
    queue1.enqueue(m);
    test_enqueue(queue1, "10 speed 2", "1");

    // удаление первого элемента из очереди
    queue1.dequeue();
    test_dequeue(queue1, "1");

    // сохранение очереди "1" в output
    test_saving("output.txt", "1");

    // чтение с output.txt в очередь "2"
    ifstream input1("output.txt");
    Queue queue2;
    queue2.load_file(input1);

    test_reading(queue2, "output.txt", "2");

    // сравнение
    bool true_res = (queue1 == queue2);
    test_comparing(true_res, "1", "2");

    // получение координат
    vector <int> coord = queue1.get_coord();
    test_coord("1", coord);
}

void MainWindow::show_queues() {                    // print queues in textBrowser_2
    ui->textBrowser_2->setText("");
    for (auto const& [key, value]: queues){
        auto queue_name = key;
        ui->textBrowser_2->append(QString::fromStdString(queue_name));
        Queue q_(queues[queue_name]);
        Queue::Iterator iter;

        if (!q_.empty()){
            for (iter = q_.begin(); iter != q_.end(); iter++) {
                auto time = std::to_string(iter->get_time());
                if (iter->is_rotation()) {
                    auto radius = std::to_string(iter->get_radius());
                    ui->textBrowser_2->append(QString::fromStdString("time: " + time + " radius: " + radius));
                }
                else {
                    auto speed = std::to_string(iter->get_speed());
                    ui->textBrowser_2->append(QString::fromStdString("time: " + time + " speed: " + speed));
                };
            };
        }
        else {
            ui->textBrowser_2->append(QString::fromStdString("Очередь пуста"));
        }

    }
}

void show_error(const string& text_error) {
    QMessageBox msg;
    msg.setIcon(QMessageBox::Critical);
    msg.setText(QString::fromStdString(text_error));
    msg.exec();
}

void MainWindow::on_get_result_clicked() {       // button "Показать результат"
    if (ui->radioButton_read->isChecked()) {             // loading
        auto file_name = ui->file_name->text();
        auto queue_name = ui->queue_name_get->text();

        if (file_name.size() != 0) {
            if (queue_name.size() != 0) {
                int a = queues.count(queue_name.toStdString());
                if (a == 0) {
                    ifstream input(file_name.toStdString());
                    queues[queue_name.toStdString()].load_file(input);
                    print(queues[queue_name.toStdString()]);
                    ui->textBrowser->setText("Готово");
                    show_queues();
                }
                else {
                    show_error("Такая очередь уже существует!");
                };
            }
            else {
                show_error("Введите название очереди");
            };
        }
        else {
            show_error("Введите название файла");
        };
    };

    if (ui->radioButton_write->isChecked()) {           // saving
        auto file_name = ui->file_name->text();
        auto queue_name = ui->queue_name_get->text();

        if (file_name.size() != 0) {
            if (queue_name.size() != 0) {
                if (queues.count(queue_name.toStdString())!=0) {
                    ui->textBrowser->setText("Готово");
                    ofstream output(file_name.toStdString());
                    queues[queue_name.toStdString()].save_file(output);
                };
            }
            else {
                show_error("Введите название очереди");
            };
        }
        else {
            show_error("Введите название файла");
        };
    };

    if (ui->radioButton_show->isChecked()) {           // showing
        auto queue_name = ui->queue_name_get->text();

        if (queue_name.size() != 0){
            if (queues.count(queue_name.toStdString()) != 0) {
                Queue q_(queues[queue_name.toStdString()]);
                ui->textBrowser->setText("");
                Queue::Iterator iter;

                for (iter = q_.begin(); iter != q_.end(); iter++) {
                    auto time = std::to_string(iter->get_time());
                    if (iter->is_rotation()) {
                        auto radius = std::to_string(iter->get_radius());
                        ui->textBrowser->append(QString::fromStdString("time: " + time + " radius: " + radius));
                    }
                    else {
                        auto speed = std::to_string(iter->get_speed());
                        ui->textBrowser->append(QString::fromStdString("time: " + time + " speed: " + speed));
                    };
                };
            };
        }
        else {
          show_error("Введите название очереди");
        };
     };
};

void MainWindow::on_add_command_clicked() {      // enqueue
    int time, move;
    string type_move;

    auto queue_name = ui->queue_name_change->text();
    auto data = stringstream((ui->data_for_add->text()).toStdString());

    data >> time >> type_move >> move;

    if (queue_name.size() != 0) {
        if (queues.count(queue_name.toStdString()) != 0) {
            if (type_move == "rotation") {
                Rotation m(time, move);
                queues[queue_name.toStdString()].enqueue(m);
                show_queues();
            }
            else  if (type_move == "speed"){
                MoveCommand m(time, move);
                queues[queue_name.toStdString()].enqueue(m);
                show_queues();
            }
            else {
                show_error("Введите существующую команду");
            };
        }
        else {
            show_error("Введите существующее название очереди");
        };
    }
    else {
        show_error("Введите название очереди");
    };
};

void MainWindow::on_delete_first_clicked() {     // dequeue
    auto queue_name = ui->queue_name_change->text();

    if (queue_name.size() != 0) {
        if (queues.count(queue_name.toStdString()) != 0 && !queues[queue_name.toStdString()].empty()) {
            queues[queue_name.toStdString()].dequeue();
            show_queues();
        }
        else {
            show_error("Введите существующее название очереди или в очереди не осталось элементов");
        };
    }
    else {
        show_error("Введите название очереди");
    }
}

void MainWindow::on_compare_clicked() {          // comparing
    auto first_queue = ui->queue_name_1->text();
    auto second_queue = ui->queue_name_2->text();

    if (first_queue.size() != 0 and second_queue.size() != 0) {
        if (queues.count(first_queue.toStdString()) != 0 and queues.count(second_queue.toStdString()) != 0) {
            if (queues[first_queue.toStdString()] == queues[second_queue.toStdString()]) {
                ui->textBrowser->setText("Они равны");
            }
            else {
                ui->textBrowser->setText("Они различны");
            };
        }
        else {
            show_error("Введите существующие очереди");
        }
    }
    else {
        show_error("Введите название очереди");
    }
};

void MainWindow::on_get_coord_clicked() {        // get coordinates
    auto queue_name = ui->queue_name_coord->text();

    if (queue_name.size() != 0){
        if (queues.count(queue_name.toStdString()) != 0) {
            int x, y;
            vector<int> coord = queues[queue_name.toStdString()].get_coord();
            x = coord[0];
            y = coord[1];
            ui->textBrowser->setText(QString::fromStdString("x = " + std::to_string(x) + " y = " + std::to_string(y)));
        }
        else {
            show_error("Введите существующее название очереди или в очереди не осталось элементов");
        };
    }
    else {
        show_error("Введите название очереди");
    };
};
