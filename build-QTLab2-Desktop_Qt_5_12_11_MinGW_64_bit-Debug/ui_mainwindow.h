/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QVBoxLayout *add_layout;
    QLabel *label_6;
    QLabel *label_11;
    QLineEdit *lineEdit_name_map_add;
    QLabel *label_7;
    QLineEdit *lineEdit_student;
    QLabel *label_8;
    QLineEdit *lineEdit_value;
    QPushButton *pushButton_add;
    QWidget *layoutWidget1;
    QVBoxLayout *best_3_layout;
    QLabel *label_12;
    QLabel *label_13;
    QLineEdit *lineEdit_name_map_best;
    QPushButton *pushButton_result_best;
    QWidget *layoutWidget2;
    QVBoxLayout *delete_layout;
    QLabel *label_9;
    QLabel *label_14;
    QLineEdit *lineEdit_name_map_del;
    QLabel *label_10;
    QLineEdit *lineEdit_student_2;
    QPushButton *pushButton_delete;
    QFrame *line;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLineEdit *lineEdit_name_map;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_load;
    QPushButton *pushButton_save;
    QPushButton *pushButton_result;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLabel *label;
    QWidget *layoutWidget5;
    QHBoxLayout *horizontalLayout_4;
    QTextBrowser *textBrowser_console;
    QTextBrowser *textBrowser_all_map;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(952, 550);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 290, 301, 217));
        add_layout = new QVBoxLayout(layoutWidget);
        add_layout->setObjectName(QString::fromUtf8("add_layout"));
        add_layout->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(9);
        font.setBold(true);
        font.setWeight(75);
        label_6->setFont(font);

        add_layout->addWidget(label_6);

        label_11 = new QLabel(layoutWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(9);
        label_11->setFont(font1);

        add_layout->addWidget(label_11);

        lineEdit_name_map_add = new QLineEdit(layoutWidget);
        lineEdit_name_map_add->setObjectName(QString::fromUtf8("lineEdit_name_map_add"));

        add_layout->addWidget(lineEdit_name_map_add);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font1);

        add_layout->addWidget(label_7);

        lineEdit_student = new QLineEdit(layoutWidget);
        lineEdit_student->setObjectName(QString::fromUtf8("lineEdit_student"));

        add_layout->addWidget(lineEdit_student);

        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font1);

        add_layout->addWidget(label_8);

        lineEdit_value = new QLineEdit(layoutWidget);
        lineEdit_value->setObjectName(QString::fromUtf8("lineEdit_value"));

        add_layout->addWidget(lineEdit_value);

        pushButton_add = new QPushButton(layoutWidget);
        pushButton_add->setObjectName(QString::fromUtf8("pushButton_add"));

        add_layout->addWidget(pushButton_add);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(630, 290, 301, 107));
        best_3_layout = new QVBoxLayout(layoutWidget1);
        best_3_layout->setObjectName(QString::fromUtf8("best_3_layout"));
        best_3_layout->setContentsMargins(0, 0, 0, 0);
        label_12 = new QLabel(layoutWidget1);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setFont(font);

        best_3_layout->addWidget(label_12);

        label_13 = new QLabel(layoutWidget1);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setFont(font1);

        best_3_layout->addWidget(label_13);

        lineEdit_name_map_best = new QLineEdit(layoutWidget1);
        lineEdit_name_map_best->setObjectName(QString::fromUtf8("lineEdit_name_map_best"));

        best_3_layout->addWidget(lineEdit_name_map_best);

        pushButton_result_best = new QPushButton(layoutWidget1);
        pushButton_result_best->setObjectName(QString::fromUtf8("pushButton_result_best"));

        best_3_layout->addWidget(pushButton_result_best);

        layoutWidget2 = new QWidget(centralwidget);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(320, 290, 301, 162));
        delete_layout = new QVBoxLayout(layoutWidget2);
        delete_layout->setObjectName(QString::fromUtf8("delete_layout"));
        delete_layout->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(layoutWidget2);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font);

        delete_layout->addWidget(label_9);

        label_14 = new QLabel(layoutWidget2);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setFont(font1);

        delete_layout->addWidget(label_14);

        lineEdit_name_map_del = new QLineEdit(layoutWidget2);
        lineEdit_name_map_del->setObjectName(QString::fromUtf8("lineEdit_name_map_del"));

        delete_layout->addWidget(lineEdit_name_map_del);

        label_10 = new QLabel(layoutWidget2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFont(font1);

        delete_layout->addWidget(label_10);

        lineEdit_student_2 = new QLineEdit(layoutWidget2);
        lineEdit_student_2->setObjectName(QString::fromUtf8("lineEdit_student_2"));

        delete_layout->addWidget(lineEdit_student_2);

        pushButton_delete = new QPushButton(layoutWidget2);
        pushButton_delete->setObjectName(QString::fromUtf8("pushButton_delete"));

        delete_layout->addWidget(pushButton_delete);

        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(10, 280, 921, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        layoutWidget3 = new QWidget(centralwidget);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(10, 20, 921, 29));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font1);

        horizontalLayout_3->addWidget(label_4);

        lineEdit_name_map = new QLineEdit(layoutWidget3);
        lineEdit_name_map->setObjectName(QString::fromUtf8("lineEdit_name_map"));

        horizontalLayout_3->addWidget(lineEdit_name_map);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton_load = new QPushButton(layoutWidget3);
        pushButton_load->setObjectName(QString::fromUtf8("pushButton_load"));
        pushButton_load->setEnabled(true);
        pushButton_load->setMouseTracking(false);

        horizontalLayout_2->addWidget(pushButton_load);

        pushButton_save = new QPushButton(layoutWidget3);
        pushButton_save->setObjectName(QString::fromUtf8("pushButton_save"));

        horizontalLayout_2->addWidget(pushButton_save);

        pushButton_result = new QPushButton(layoutWidget3);
        pushButton_result->setObjectName(QString::fromUtf8("pushButton_result"));

        horizontalLayout_2->addWidget(pushButton_result);


        horizontalLayout_3->addLayout(horizontalLayout_2);

        layoutWidget4 = new QWidget(centralwidget);
        layoutWidget4->setObjectName(QString::fromUtf8("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(10, 50, 921, 21));
        horizontalLayout = new QHBoxLayout(layoutWidget4);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget4);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Arial"));
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setWeight(75);
        label_2->setFont(font2);

        horizontalLayout->addWidget(label_2);

        label = new QLabel(layoutWidget4);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font2);

        horizontalLayout->addWidget(label);

        layoutWidget5 = new QWidget(centralwidget);
        layoutWidget5->setObjectName(QString::fromUtf8("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(10, 80, 921, 194));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget5);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        textBrowser_console = new QTextBrowser(layoutWidget5);
        textBrowser_console->setObjectName(QString::fromUtf8("textBrowser_console"));

        horizontalLayout_4->addWidget(textBrowser_console);

        textBrowser_all_map = new QTextBrowser(layoutWidget5);
        textBrowser_all_map->setObjectName(QString::fromUtf8("textBrowser_all_map"));

        horizontalLayout_4->addWidget(textBrowser_all_map);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        pushButton_load->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\267\320\260\320\277\320\270\321\201\321\214:", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\262\320\265\320\264\320\276\320\274\320\276\321\201\321\202\320\270:", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "\320\230\320\274\321\217 \321\201\321\202\321\203\320\264\320\265\320\275\321\202\320\260:", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "\320\225\320\263\320\276 \321\200\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202:", nullptr));
        pushButton_add->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\276\320\261\321\200\320\260\320\267\320\270\321\202\321\214 3 \320\273\321\203\321\207\321\210\320\270\321\205 \321\201\321\202\321\203\320\264\320\265\320\275\321\202\320\260:", nullptr));
        label_13->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\262\320\265\320\264\320\276\320\274\320\276\321\201\321\202\320\270:", nullptr));
        pushButton_result_best->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\276\320\261\321\200\320\260\320\267\320\270\321\202\321\214 \321\200\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214:", nullptr));
        label_14->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\262\320\265\320\264\320\276\320\274\320\276\321\201\321\202\320\270:", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "\320\230\320\274\321\217 \321\201\321\202\321\203\320\264\320\265\320\275\321\202\320\260:", nullptr));
        pushButton_delete->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\262\320\265\320\264\320\276\320\274\320\276\321\201\321\202\320\270:", nullptr));
        pushButton_load->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214", nullptr));
        pushButton_save->setText(QApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        pushButton_result->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\276\320\261\321\200\320\260\320\267\320\270\321\202\321\214 \320\262\320\265\320\264\320\276\320\274\320\276\321\201\321\202\321\214", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\275\321\201\320\276\320\273\321\214", nullptr));
        label->setText(QApplication::translate("MainWindow", "\320\222\321\201\320\265 \320\262\320\265\320\264\320\276\320\274\320\276\321\201\321\202\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
