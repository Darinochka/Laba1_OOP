#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QMessageBox>
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
    connect(ui->lineEdit_name_map_add, SIGNAL(textChanged(const QString &)), this, SLOT(button_add_is_enabled(const QString &)));
    connect(ui->lineEdit_student, SIGNAL(textChanged(const QString &)), this, SLOT(button_add_is_enabled(const QString &)));
    connect(ui->lineEdit_value, SIGNAL(textChanged(const QString &)), this, SLOT(button_add_is_enabled(const QString &)));

    connect(ui->lineEdit_name_map_best, SIGNAL(textChanged(const QString &)), this, SLOT(button_best_is_enabled(const QString &)));

    connect(ui->lineEdit_name_file, SIGNAL(textChanged(const QString &)), this, SLOT(button_result_is_enabled(const QString &)));
    connect(ui->lineEdit_name_map, SIGNAL(textChanged(const QString &)), this, SLOT(button_result_is_enabled(const QString &)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

map<string, HashTable<Student>> tables;

void MainWindow::button_add_is_enabled(const QString &text) {
    if (ui->lineEdit_name_map_add->text() != "" &&
            ui->lineEdit_student->text() != "" &&
            ui->lineEdit_value->text() != "") {
        ui->pushButton_add->setEnabled(true);
    }
    else {
        ui->pushButton_add->setEnabled(false);
    }
}

void MainWindow::button_best_is_enabled(const QString &text) {
    ui->pushButton_result_best->setEnabled(!text.isEmpty());
    ui->pushButton_delete_map->setEnabled(!text.isEmpty());
    ui->pushButton_add_map->setEnabled(!text.isEmpty());
}

void MainWindow::button_result_is_enabled(const QString &text) {
    if (ui->lineEdit_name_file->text() != "" &&
            ui->lineEdit_name_map->text() != "") {
        ui->pushButton_result->setEnabled(true);
    }
    else {
        ui->pushButton_result->setEnabled(false);
    }
}

void MainWindow::test_import(const HashTable<Student>& table, const string& file_name, const string& table_name) {
    ui->radioButton_import->setChecked(true);
    ui->lineEdit_name_file->setText(QString::fromStdString(file_name));
    ui->lineEdit_name_map->setText(QString::fromStdString(table_name));
    on_pushButton_result_clicked();

    assert(tables.count(table_name) == 1);
    assert(tables[table_name] == table);
}

void MainWindow::test_insert(const HashTable<Student>& table,
                             const Student& student,
                             const int& value,
                             const string& table_name) {
    ui->lineEdit_student->setText(QString::fromStdString(student.get_name()));
    ui->lineEdit_value->setText(QString::fromStdString(to_string(value)));
    ui->lineEdit_name_map_add->setText(QString::fromStdString(table_name));
    on_pushButton_add_clicked();

    assert(tables[table_name] == table);
}

void MainWindow::test_saving(const HashTable<Student>& table, const string& table_name) {
    ui->radioButton_save->setChecked(true);
    ui->lineEdit_name_file->setText(QString::fromStdString("output.txt"));
    ui->lineEdit_name_map->setText(QString::fromStdString(table_name));
    on_pushButton_result_clicked();

    ifstream input("output.txt");

    HashTable<Student> table2;
    table2.load_file(input);

    assert(table == table2);
}

void MainWindow::test_best(const vector<Student> best_students, const string& table_name) {
    ui->lineEdit_name_map_best->setText(QString::fromStdString(table_name));
    on_pushButton_result_best_clicked();

    string best = ui->textBrowser_console->toPlainText().toStdString();
    string best_correct = "Лучшие студенты:\n" +
            best_students[0].get_name() + "\n" +
            best_students[1].get_name() + "\n" +
            best_students[2].get_name();
    cout << best << best_correct;
    assert(best == best_correct);
}

void MainWindow::test() {
    // загрузка очереди из файла
    ifstream input("input.txt");
    HashTable<Student> table1;

    table1.load_file(input);
    test_import(table1, "input.txt", "1");

    // добавление
    Student dasha("dasha");
    int result = 3;

    table1.insert(dasha, 3);
    test_insert(table1, dasha, result, "1");

    // удаление
    table1.erase(dasha);

    // проверка сохранения
    test_saving(table1, "1");

    // проверка 3 лучших
    vector<Student> best_students = table1.get_max_values();
    test_best(best_students, "1");
}

void MainWindow::show_tables() {                    // print queues in textBrowser_all_map
    ui->tableWidget->setShowGrid(true);
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setEditTriggers(QTableWidget::NoEditTriggers);
    int n = 0;
    for (auto const& [key, value]: tables){
        string table_name = key;

        if (value.get_size() != 0) {
            for (auto const& key : value.get_keys()) {

                auto name = key.get_name();
                auto result = std::to_string(value[key]);
                ui->tableWidget->insertRow(n);
                ui->tableWidget->setItem(n,0, new QTableWidgetItem(QString::fromStdString(name)));
                ui->tableWidget->setItem(n,1, new QTableWidgetItem(QString::fromStdString(result)));
                ui->tableWidget->setItem(n,2, new QTableWidgetItem(QString::fromStdString(table_name)));
            };
        }
        else {
            ui->tableWidget->insertRow(n);
            ui->tableWidget->setItem(n,0, new QTableWidgetItem("Ведомость пуста"));
            ui->tableWidget->setItem(n,1, new QTableWidgetItem("Ведомость пуста"));
            ui->tableWidget->setItem(n,2, new QTableWidgetItem(QString::fromStdString(table_name)));
        }
        n += 1;
    }
}

void MainWindow::update_button() {
    ui->lineEdit_name_map_add->setEnabled(1);
    ui->lineEdit_student->setEnabled(1);
    ui->lineEdit_value->setEnabled(1);

    ui->pushButton_delete->setEnabled(1);
    ui->pushButton_delete_map->setEnabled(1);

}

void show_error(const string& text_error) {
    QMessageBox msg;
    msg.setIcon(QMessageBox::Critical);
    msg.setText(QString::fromStdString(text_error));
    msg.exec();
};

void MainWindow::on_pushButton_result_clicked() {   // button "Показать результат"
    if (ui->radioButton_import->isChecked()) {             // loading
        auto file_name = ui->lineEdit_name_file->text();
        auto table_name = ui->lineEdit_name_map->text();

        if (file_name.size() != 0) {
            if (table_name.size() != 0) {
                int a = tables.count(table_name.toStdString());
                if (a == 0) {
                    ifstream input(file_name.toStdString());
                    tables[table_name.toStdString()].load_file(input);
                    ui->textBrowser_console->setText("Готово");
                    show_tables();
                    ui->lineEdit_name_file->setText("");
                    ui->lineEdit_name_map->setText("");
                    update_button();
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
    };

    if (ui->radioButton_save->isChecked()) {           // saving
        auto file_name = ui->lineEdit_name_file->text();
        auto table_name = ui->lineEdit_name_map->text();

        if (file_name.size() != 0) {
            if (table_name.size() != 0) {
                if (tables.count(table_name.toStdString())!=0) {
                    ui->textBrowser_console->setText("Готово");
                    ofstream output(file_name.toStdString());
                    tables[table_name.toStdString()].save_file(output);
                    ui->lineEdit_name_file->setText("");
                    ui->lineEdit_name_map->setText("");
                };
            }
            else {
                show_error("Введите название ведомости");
            };
        }
        else {
            show_error("Введите название файла");
        };
    };

    if (ui->radioButton_show->isChecked()) {           // showing
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
                    ui->lineEdit_name_map->setText("");
                }
                else {
                    ui->textBrowser_console->append(QString::fromStdString("Ведомость пуста"));
                };
            }
            else {
                show_error("Такой ведомости не существует");
            }
        }
        else {
          show_error("Введите название ведомости");
        };
     };
};

void MainWindow::on_pushButton_add_clicked() {      // enqueue
    auto table_name = ui->lineEdit_name_map_add->text();
    string key = ui->lineEdit_student->text().toStdString();
    int value = ui->lineEdit_value->text().toInt();
    Student st(key);
    cout << value;
    if (table_name.size() != 0 && key.size() != 0 && value != 0) {
        if (tables.count(table_name.toStdString()) != 0) {
            tables[table_name.toStdString()].insert(st, value);
            ui->lineEdit_name_map_add->setText("");
            ui->lineEdit_student->setText("");
            ui->lineEdit_value->setText("");
            show_tables();
        }
        else {
            show_error("Введите существующее название ведомости");
        };
    }
    else {
        show_error("Вы не ввели название ведомости или имя студента с его результатом");
    };
};

void MainWindow::on_pushButton_delete_clicked() {   // dequeue

    QItemSelectionModel *select = ui->tableWidget->selectionModel();

    for (int i = 0; i < select->selectedRows().count(); i++) {
        string stud_name = select->selectedRows(0).at(i).data().toString().toStdString();
        Student student(stud_name);
        string table_name = select->selectedRows(2).at(i).data().toString().toStdString();
        tables[table_name].erase(student);
        show_tables();
    }
};

void MainWindow::on_pushButton_result_best_clicked() {
    ui->textBrowser_console->setText("");
    auto table_name = ui->lineEdit_name_map_best->text().toStdString();

    if (table_name.size() != 0) {
        if (tables.count(table_name) != 0) {
            if (tables[table_name].get_size() != 0) {
                vector<Student> best_students(tables[table_name].get_max_values());
                ui->textBrowser_console->append(QString::fromStdString(("Лучшие студенты:")));
                for (const Student& student: best_students) {
                    ui->textBrowser_console->append(QString::fromStdString(student.get_name()));
                }
                ui->lineEdit_name_map_best->setText("");
            }
            else {
                 show_error("Ведомость пустая");
            };
        }
        else {
            show_error("Такой ведомости не существует!");
        };
    }
    else {
        show_error("Введите название ведомости");
    }

};

void MainWindow::on_pushButton_add_map_clicked() {
    ui->textBrowser_console->setText("");
    auto table_name = ui->lineEdit_name_map_best->text().toStdString();
    if (table_name.size() != 0) {
        if (tables.count(table_name) == 0) {
            tables[table_name] = HashTable<Student>();
            update_button();
            show_tables();
        }
        else {
            show_error("Такая ведомость уже существует!");
        };
    }
    else {
        show_error("Введите название ведомости");
    }
};

void MainWindow::on_pushButton_delete_map_clicked() {
    ui->textBrowser_console->setText("");
    auto table_name = ui->lineEdit_name_map_best->text().toStdString();
    if (table_name.size() != 0) {
        if (tables.count(table_name) != 0) {
            tables.erase(table_name);
            show_tables();
        }
        else {
            show_error("Такой ведомости не существует!");
        };
    }
    else {
        show_error("Введите название ведомости");
    }
}
