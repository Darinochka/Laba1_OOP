#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "HashTable.h"
#include "Student.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

//    void test();

private slots:
    void show_tables();

//    void test_import(const HashTable<Student>& table, const std::string& file_name, const std::string& table_name);

//    void test_saving(const HashTable<Student>& table, const string& table_name);

//    void test_insert(const HashTable<Student>& table, const Student& student, const int& value, const std::string& table_name);

//    void test_erase(const HashTable<Student>& table, const Student& student, const std::string& table_name);

//    void test_best(const vector<Student> best_students, const string& table_name);

    void on_pushButton_result_clicked();

    void on_pushButton_save_clicked();

    void on_pushButton_load_clicked();

    void on_pushButton_add_clicked();

    void on_pushButton_delete_clicked();

    void on_pushButton_result_best_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
