/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButton_import;
    QRadioButton *radioButton_save;
    QRadioButton *radioButton_show;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_4;
    QLineEdit *lineEdit_name_map;
    QLabel *label_5;
    QLineEdit *lineEdit_name_file;
    QFrame *line_2;
    QPushButton *pushButton_result;
    QTextBrowser *textBrowser_console;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *add_layout;
    QLabel *label_6;
    QLabel *label_11;
    QLineEdit *lineEdit_name_map_add;
    QLabel *label_7;
    QLineEdit *lineEdit_student;
    QLabel *label_8;
    QLineEdit *lineEdit_value;
    QPushButton *pushButton_add;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *best_3_layout;
    QLabel *label_12;
    QLabel *label_13;
    QLineEdit *lineEdit_name_map_best;
    QPushButton *pushButton_result_best;
    QFrame *frame;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_9;
    QPushButton *pushButton_delete;
    QTableWidget *tableWidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(986, 590);
        MainWindow->setMinimumSize(QSize(986, 590));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(11, 21, 965, 535));
        verticalLayout_6 = new QVBoxLayout(widget);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(10);
        font.setBold(true);
        label_3->setFont(font);

        horizontalLayout_2->addWidget(label_3);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        horizontalLayout_2->addWidget(label);


        verticalLayout_6->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        radioButton_import = new QRadioButton(widget);
        radioButton_import->setObjectName(QString::fromUtf8("radioButton_import"));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Arial")});
        font1.setPointSize(9);
        radioButton_import->setFont(font1);

        verticalLayout->addWidget(radioButton_import);

        radioButton_save = new QRadioButton(widget);
        radioButton_save->setObjectName(QString::fromUtf8("radioButton_save"));
        radioButton_save->setFont(font1);

        verticalLayout->addWidget(radioButton_save);

        radioButton_show = new QRadioButton(widget);
        radioButton_show->setObjectName(QString::fromUtf8("radioButton_show"));
        radioButton_show->setFont(font1);

        verticalLayout->addWidget(radioButton_show);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font1);

        verticalLayout_3->addWidget(label_4);

        lineEdit_name_map = new QLineEdit(widget);
        lineEdit_name_map->setObjectName(QString::fromUtf8("lineEdit_name_map"));

        verticalLayout_3->addWidget(lineEdit_name_map);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font1);

        verticalLayout_3->addWidget(label_5);

        lineEdit_name_file = new QLineEdit(widget);
        lineEdit_name_file->setObjectName(QString::fromUtf8("lineEdit_name_file"));

        verticalLayout_3->addWidget(lineEdit_name_file);


        verticalLayout->addLayout(verticalLayout_3);

        line_2 = new QFrame(widget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_2);

        pushButton_result = new QPushButton(widget);
        pushButton_result->setObjectName(QString::fromUtf8("pushButton_result"));
        pushButton_result->setEnabled(true);
        pushButton_result->setCheckable(false);
        pushButton_result->setAutoRepeat(false);

        verticalLayout->addWidget(pushButton_result);


        horizontalLayout->addLayout(verticalLayout);

        textBrowser_console = new QTextBrowser(widget);
        textBrowser_console->setObjectName(QString::fromUtf8("textBrowser_console"));
        textBrowser_console->setMinimumSize(QSize(256, 273));
        textBrowser_console->setMaximumSize(QSize(256, 16777215));

        horizontalLayout->addWidget(textBrowser_console);


        verticalLayout_5->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        add_layout = new QVBoxLayout();
        add_layout->setObjectName(QString::fromUtf8("add_layout"));
        label_6 = new QLabel(widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Arial")});
        font2.setPointSize(9);
        font2.setBold(true);
        label_6->setFont(font2);

        add_layout->addWidget(label_6);

        label_11 = new QLabel(widget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setFont(font1);

        add_layout->addWidget(label_11);

        lineEdit_name_map_add = new QLineEdit(widget);
        lineEdit_name_map_add->setObjectName(QString::fromUtf8("lineEdit_name_map_add"));
        lineEdit_name_map_add->setEnabled(false);

        add_layout->addWidget(lineEdit_name_map_add);

        label_7 = new QLabel(widget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font1);

        add_layout->addWidget(label_7);

        lineEdit_student = new QLineEdit(widget);
        lineEdit_student->setObjectName(QString::fromUtf8("lineEdit_student"));
        lineEdit_student->setEnabled(false);

        add_layout->addWidget(lineEdit_student);

        label_8 = new QLabel(widget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font1);

        add_layout->addWidget(label_8);

        lineEdit_value = new QLineEdit(widget);
        lineEdit_value->setObjectName(QString::fromUtf8("lineEdit_value"));
        lineEdit_value->setEnabled(false);

        add_layout->addWidget(lineEdit_value);

        pushButton_add = new QPushButton(widget);
        pushButton_add->setObjectName(QString::fromUtf8("pushButton_add"));
        pushButton_add->setEnabled(false);

        add_layout->addWidget(pushButton_add);


        horizontalLayout_3->addLayout(add_layout);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        best_3_layout = new QVBoxLayout();
        best_3_layout->setObjectName(QString::fromUtf8("best_3_layout"));
        label_12 = new QLabel(widget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setFont(font2);

        best_3_layout->addWidget(label_12);

        label_13 = new QLabel(widget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setFont(font1);

        best_3_layout->addWidget(label_13);

        lineEdit_name_map_best = new QLineEdit(widget);
        lineEdit_name_map_best->setObjectName(QString::fromUtf8("lineEdit_name_map_best"));
        lineEdit_name_map_best->setEnabled(false);

        best_3_layout->addWidget(lineEdit_name_map_best);

        pushButton_result_best = new QPushButton(widget);
        pushButton_result_best->setObjectName(QString::fromUtf8("pushButton_result_best"));
        pushButton_result_best->setEnabled(false);

        best_3_layout->addWidget(pushButton_result_best);


        verticalLayout_4->addLayout(best_3_layout);

        frame = new QFrame(widget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);

        verticalLayout_4->addWidget(frame);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_9 = new QLabel(widget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font1);

        verticalLayout_2->addWidget(label_9);

        pushButton_delete = new QPushButton(widget);
        pushButton_delete->setObjectName(QString::fromUtf8("pushButton_delete"));
        pushButton_delete->setEnabled(false);

        verticalLayout_2->addWidget(pushButton_delete);


        verticalLayout_4->addLayout(verticalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout_4);


        verticalLayout_5->addLayout(horizontalLayout_3);


        horizontalLayout_4->addLayout(verticalLayout_5);

        tableWidget = new QTableWidget(widget);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setMinimumSize(QSize(395, 501));
        tableWidget->setAutoFillBackground(true);
        tableWidget->setLineWidth(1);
        tableWidget->setMidLineWidth(0);
        tableWidget->setAlternatingRowColors(false);
        tableWidget->setSortingEnabled(true);

        horizontalLayout_4->addWidget(tableWidget);


        verticalLayout_6->addLayout(horizontalLayout_4);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\236\320\277\320\265\321\200\320\260\321\206\320\270\320\270 \321\201 \320\262\320\265\320\264\320\276\320\274\320\276\321\201\321\202\321\217\320\274\320\270:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\275\321\201\320\276\320\273\321\214", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\222\321\201\320\265 \320\262\320\265\320\264\320\276\320\274\320\276\321\201\321\202\320\270", nullptr));
        radioButton_import->setText(QCoreApplication::translate("MainWindow", "\320\230\320\274\320\277\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \320\262\320\265\320\264\320\276\320\274\320\276\321\201\321\202\321\214", nullptr));
        radioButton_save->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\262\320\265\320\264\320\276\320\274\320\276\321\201\321\202\321\214", nullptr));
        radioButton_show->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\276\320\261\321\200\320\260\320\267\320\270\321\202\321\214 \320\262\320\265\320\264\320\276\320\274\320\276\321\201\321\202\321\214\n"
"(\320\262\320\262\320\265\320\264\320\270\321\202\320\265 \321\202\320\276\320\273\321\214\320\272\320\276 \320\275\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\262\320\265\320\264\320\276\320\274\320\276\321\201\321\202\320\270)", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\262\320\265\320\264\320\276\320\274\320\276\321\201\321\202\320\270:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \321\204\320\260\320\271\320\273\320\260:", nullptr));
        pushButton_result->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\273\321\203\321\207\320\270\321\202\321\214 \321\200\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\267\320\260\320\277\320\270\321\201\321\214:", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\262\320\265\320\264\320\276\320\274\320\276\321\201\321\202\320\270:", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\320\230\320\274\321\217 \321\201\321\202\321\203\320\264\320\265\320\275\321\202\320\260:", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\320\225\320\263\320\276 \321\200\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202:", nullptr));
        pushButton_add->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\276\320\261\321\200\320\260\320\267\320\270\321\202\321\214 3 \320\273\321\203\321\207\321\210\320\270\321\205 \321\201\321\202\321\203\320\264\320\265\320\275\321\202\320\260:", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\262\320\265\320\264\320\276\320\274\320\276\321\201\321\202\320\270:", nullptr));
        pushButton_result_best->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\276\320\261\321\200\320\260\320\267\320\270\321\202\321\214 \321\200\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\264\320\265\320\273\320\270\321\202\320\265 \321\217\321\207\320\265\320\271\320\272\320\270 \320\270 \320\275\320\260\320\266\320\274\320\270\321\202\320\265 \320\272\320\275\320\276\320\277\320\272\321\203:", nullptr));
        pushButton_delete->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "\320\241\321\202\321\203\320\264\320\265\320\275\321\202\321\213", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "\320\222\320\265\320\264\320\276\320\274\320\276\321\201\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
