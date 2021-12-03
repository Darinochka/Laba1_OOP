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
#include <QtWidgets>
#include <QMessageBox>
#include <QFileDialog>
#include "Student.h"
#include "HashTable.cpp"
#include "HashTable.h"
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

map<string, HashTable<Student>> tables;

//void MainWindow::test_import(const HashTable<Student>& table, const string& file_name, const string& table_name) {
//    ui->radioButton_import->setChecked(true);
//    ui->lineEdit_name_file->setText(QString::fromStdString(file_name));
//    ui->lineEdit_name_map->setText(QString::fromStdString(table_name));
//    on_pushButton_result_clicked();

//    assert(tables.count(table_name) == 1);
//    assert(tables[table_name] == table);
//}

//void MainWindow::test_insert(const HashTable<Student>& table,
//                             const Student& student,
//                             const int& value,
//                             const string& table_name) {
//    ui->lineEdit_student->setText(QString::fromStdString(student.get_name()));
//    ui->lineEdit_value->setText(QString::fromStdString(to_string(value)));
//    ui->lineEdit_name_map_add->setText(QString::fromStdString(table_name));
//    on_pushButton_add_clicked();

//    assert(tables[table_name] == table);
//}

//void MainWindow::test_erase(const HashTable<Student>& table, const Student& student, const string& table_name) {
//    ui->lineEdit_name_map_del->setText(QString::fromStdString(table_name));
//    ui->lineEdit_student_2->setText(QString::fromStdString(student.get_name()));
//    on_pushButton_delete_clicked();

//    assert(tables[table_name] == table);
//}

//void MainWindow::test_saving(const HashTable<Student>& table, const string& table_name) {
//    ui->radioButton_save->setChecked(true);
//    ui->lineEdit_name_file->setText(QString::fromStdString("output.txt"));
//    ui->lineEdit_name_map->setText(QString::fromStdString(table_name));
//    on_pushButton_result_clicked();

//    ifstream input("output.txt");

//    HashTable<Student> table2;
//    table2.load_file(input);

//    assert(table == table2);
//}

//void MainWindow::test_best(const vector<Student> best_students, const string& table_name) {
//    ui->lineEdit_name_map_best->setText(QString::fromStdString(table_name));
//    on_pushButton_result_best_clicked();

//    string best = ui->textBrowser_console->toPlainText().toStdString();
//    string best_correct = "Лучшие студенты:\n" +
//            best_students[0].get_name() + "\n" +
//            best_students[1].get_name() + "\n" +
//            best_students[2].get_name();
//    cout << best << best_correct;
//    assert(best == best_correct);
//}

//void MainWindow::test() {
//    // загрузка очереди из файла
//    ifstream input("input.txt");
//    HashTable<Student> table1;

//    table1.load_file(input);
//    test_import(table1, "input.txt", "1");

//    // добавление
//    Student dasha("dasha");
//    int result = 3;

//    table1.insert(dasha, 3);
//    test_insert(table1, dasha, result, "1");

//    // удаление
//    table1.erase(dasha);
//    test_erase(table1, dasha, "1");

//    // проверка сохранения
//    test_saving(table1, "1");

//    // проверка 3 лучших
//    vector<Student> best_students = table1.get_max_values();
//    test_best(best_students, "1");
//}

void MainWindow::show_tables() {                    // print queues in textBrowser_all_map
    ui->textBrowser_all_map->setText("");
    for (auto const& [key, value]: tables){
        string table_name = key;

        ui->textBrowser_all_map->append(QString::fromStdString(table_name));
        if (value.get_size() != 0) {
            for (auto const& key : value.get_keys()) {
                cout << key.get_name() << endl;
                auto name = key.get_name();
                auto result = std::to_string(value[key]);
                ui->textBrowser_all_map->append(QString::fromStdString("student: " + name + " value: " + result));
            };
        }
        else {
            ui->textBrowser_all_map->append(QString::fromStdString("Ведомость пуста"));
        }

    }
}

void show_error(const string& text_error) {
    QMessageBox msg;
    msg.setIcon(QMessageBox::Critical);
    msg.setText(QString::fromStdString(text_error));
    msg.exec();
};

void MainWindow::on_pushButton_save_clicked() {
    QString file_name = QFileDialog::getSaveFileName(this,
           tr("Сохранить ведомость"), "",
           tr("Text File (*.txt);;All Files (*)"));

    auto table_name = ui->lineEdit_name_map->text();

    if (file_name.size() != 0) {
        if (table_name.size() != 0) {
            int a = tables.count(table_name.toStdString());
            if (a == 0) {
                ifstream input(file_name.toStdString());
                tables[table_name.toStdString()].load_file(input);
                ui->textBrowser_console->setText("Готово");
                show_tables();
            }
            else {
                show_error("Такая ведомость уже существует!");
            };
        }
        else {
            show_error("Введите название ведомости");
        };
    }
    else {
        show_error("Введите название файла");
    };
}

void MainWindow::on_pushButton_load_clicked() {
    QString file_name = QFileDialog::getOpenFileName(this,
           ("Загрузить ведомость"), "",
           ("Text File (*.txt)"));

    auto table_name = ui->lineEdit_name_map->text();
    cout << file_name.toStdString();
    if (file_name.size() != 0) {
        if (table_name.size() != 0) {
            if (tables.count(table_name.toStdString())!=0) {
                ui->textBrowser_console->setText("Готово");
                ofstream output(file_name.toStdString());
                tables[table_name.toStdString()].save_file(output);
                show_tables();
            };
        }
        else {
            show_error("Введите название ведомости");
        };
    }
    else {
        show_error("Введите название файла");
    };
}
void MainWindow::on_pushButton_result_clicked() {   // button "Показать результат"
    auto table_name = ui->lineEdit_name_map->text();

    if (table_name.size() != 0){
        if (tables.count(table_name.toStdString()) != 0) {
            HashTable<Student> h_(tables[table_name.toStdString()]);
            ui->textBrowser_console->setText("");

            if (h_.get_size() != 0) {
                for (auto key : h_.get_keys()) {
                    auto name = key.get_name();
                    auto value = std::to_string(h_[key]);
                    ui->textBrowser_console->append(QString::fromStdString("key: " + name + " value: " + value));
                };
            }
            else {
                ui->textBrowser_console->append(QString::fromStdString("Ведомость пуста"));
            };
        };
    }
    else {
      show_error("Введите название ведомости");
    };
};

void MainWindow::on_pushButton_add_clicked() {      // enqueue
    auto table_name = ui->lineEdit_name_map_add->text();
    string key = ui->lineEdit_student->text().toStdString();
    int value = ui->lineEdit_value->text().toInt();
    Student st(key);

    if (table_name.size() != 0) {
        if (tables.count(table_name.toStdString()) != 0) {
            tables[table_name.toStdString()].insert(st, value);
            show_tables();
        }
        else {
            show_error("Введите существующее название ведомости");
        };
    }
    else {
        show_error("Введите название ведомости");
    };
};

void MainWindow::on_pushButton_delete_clicked() {   // dequeue
    auto table_name = ui->lineEdit_name_map_del->text().toStdString();
    Student student(ui->lineEdit_student_2->text().toStdString());

    if (table_name.size() != 0) {
        if (tables.count(table_name) != 0 && tables[table_name].get_size() != 0) {
            tables[table_name].erase(student);
            show_tables();
        }
        else {
            show_error("Введите существующее название ведомости или в ведомости не осталось элементов");
        };
    }
    else {
        show_error("Введите название ведомости");
    };
};

void MainWindow::on_pushButton_result_best_clicked() {
    ui->textBrowser_console->setText("");
    auto table_name = ui->lineEdit_name_map_best->text().toStdString();

    if (table_name.size() != 0) {
        if (tables[table_name].get_size() != 0) {
            vector<Student> best_students(tables[table_name].get_max_values());
            ui->textBrowser_console->append(QString::fromStdString(("Лучшие студенты:")));
            for (const Student& student: best_students) {
                ui->textBrowser_console->append(QString::fromStdString(student.get_name()));
            }
        }
        else {
             show_error("Ведомость пустая");
        };
    }
    else {
        show_error("Введите название ведомости");
    }

};
