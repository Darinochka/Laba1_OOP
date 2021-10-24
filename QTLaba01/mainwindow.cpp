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

void print(const Queue& queue) {
    Queue::Iterator iter;

    for (iter = queue.begin(); iter != queue.end(); iter++) {
        cout << iter << ": " << *iter << endl;
    }
}

map<string, Queue> queues;

void MainWindow::show_queues() {
    ui->textBrowser_2->setText("");
    for (auto const& [key, value]: queues){
        auto queue_name = key;
        ui->textBrowser_2->append(QString::fromStdString(queue_name));
        Queue q_(queues[queue_name]);
        Queue::Iterator iter;

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
}

void show_error(const string& text_error){
    QMessageBox msg;
    msg.setIcon(QMessageBox::Critical);
    msg.setText(QString::fromStdString(text_error));
    msg.exec();
}

void MainWindow::on_pushButton_clicked() {
    if (ui->radioButton->isChecked()) {             // loading
        auto file_name = ui->lineEdit->text();
        auto queue_name = ui->lineEdit_2->text();

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

    if (ui->radioButton_2->isChecked()) {           // saving
        auto file_name = ui->lineEdit->text();
        auto queue_name = ui->lineEdit_2->text();

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

    if (ui->radioButton_3->isChecked()) {           // showing
        auto queue_name = ui->lineEdit_2->text();

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

void MainWindow::on_pushButton_2_clicked() {        // enqueue
    int time, move;
    string type_move;

    auto queue_name = ui->lineEdit_3->text();
    auto data = stringstream((ui->lineEdit_4->text()).toStdString());

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

void MainWindow::on_pushButton_3_clicked() {        // dequeue
    auto queue_name = ui->lineEdit_3->text();
    auto data = (ui->lineEdit_4->text()).toStdString();

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

void MainWindow::on_pushButton_4_clicked() {        // comparing
    auto first_queue = ui->lineEdit_9->text();
    auto second_queue = ui->lineEdit_8->text();

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

void MainWindow::on_pushButton_5_clicked() {        // get coordinates
    auto queue_name = ui->lineEdit_6->text();

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
