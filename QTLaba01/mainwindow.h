#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Queue.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void test();

private slots:
    void show_queues();

    void test_reading(const Queue& queue, const std::string& file_name, const std::string& queue_name);

    void test_saving(const std::string& file_name, const std::string& queue_name);

    void test_enqueue(const Queue& queue, const std::string& data, const std::string& queue_name);

    void test_dequeue(const Queue& queue, const std::string& queue_name);

    void test_coord(const std::string& queue_name, const std::vector<int>& true_coord);

    void test_comparing(const bool& true_res, const std::string& q_name_1, const std::string& q_name_2);

    void on_get_result_clicked();

    void on_add_command_clicked();

    void on_delete_first_clicked();

    void on_get_coord_clicked();

    void on_compare_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
