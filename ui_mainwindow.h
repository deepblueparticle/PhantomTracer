/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon Nov 12 11:07:44 2012
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "QVTKWidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionLoad_STL_mesh;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QVTKWidget *qvtkWidget;
    QGroupBox *groupBox;
    QGroupBox *groupBox_2;
    QLabel *label;
    QSlider *horizontalSlider;
    QDoubleSpinBox *doubleSpinBox;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QGroupBox *groupBox_3;
    QLabel *label_2;
    QSpinBox *spinBox;
    QLabel *label_3;
    QDoubleSpinBox *doubleSpinBox_2;
    QGroupBox *groupBox_5;
    QLabel *label_10;
    QComboBox *comboBox_2;
    QLabel *label_11;
    QComboBox *comboBox_3;
    QLabel *label_13;
    QComboBox *comboBox_5;
    QLabel *label_14;
    QSpinBox *spinBox_2;
    QLabel *label_4;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QGroupBox *groupBox_4;
    QLabel *label_5;
    QSpinBox *spinBox_3;
    QDoubleSpinBox *doubleSpinBox_3;
    QLabel *label_6;
    QMenuBar *menuBar;
    QMenu *menuMenu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(501, 832);
        actionLoad_STL_mesh = new QAction(MainWindow);
        actionLoad_STL_mesh->setObjectName(QString::fromUtf8("actionLoad_STL_mesh"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        qvtkWidget = new QVTKWidget(centralWidget);
        qvtkWidget->setObjectName(QString::fromUtf8("qvtkWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(qvtkWidget->sizePolicy().hasHeightForWidth());
        qvtkWidget->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(qvtkWidget);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(0, 200));
        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 20, 141, 111));
        groupBox_2->setStyleSheet(QString::fromUtf8("QGroupBox { \n"
"     border: 1px solid black; \n"
"     border-radius: 1px; \n"
" } "));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 20, 41, 16));
        horizontalSlider = new QSlider(groupBox_2);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(0, 40, 131, 29));
        horizontalSlider->setMaximum(100);
        horizontalSlider->setValue(50);
        horizontalSlider->setOrientation(Qt::Horizontal);
        doubleSpinBox = new QDoubleSpinBox(groupBox_2);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setGeometry(QRect(60, 20, 51, 21));
        doubleSpinBox->setMaximum(1);
        doubleSpinBox->setSingleStep(0.1);
        doubleSpinBox->setValue(0.5);
        checkBox = new QCheckBox(groupBox_2);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(10, 60, 83, 21));
        checkBox_2 = new QCheckBox(groupBox_2);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(10, 80, 101, 21));
        groupBox_3 = new QGroupBox(groupBox);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(170, 20, 120, 80));
        groupBox_3->setStyleSheet(QString::fromUtf8("QGroupBox { \n"
"     border: 1px solid black; \n"
"     border-radius: 1px; \n"
" } "));
        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 20, 31, 16));
        spinBox = new QSpinBox(groupBox_3);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(50, 20, 53, 21));
        spinBox->setMaximum(12);
        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(0, 50, 61, 16));
        doubleSpinBox_2 = new QDoubleSpinBox(groupBox_3);
        doubleSpinBox_2->setObjectName(QString::fromUtf8("doubleSpinBox_2"));
        doubleSpinBox_2->setGeometry(QRect(60, 50, 51, 20));
        groupBox_5 = new QGroupBox(groupBox);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(300, 20, 161, 181));
        groupBox_5->setStyleSheet(QString::fromUtf8("QGroupBox { \n"
"     border: 1px solid black; \n"
"     border-radius: 1px; \n"
" } "));
        label_10 = new QLabel(groupBox_5);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(10, 50, 53, 14));
        comboBox_2 = new QComboBox(groupBox_5);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(70, 50, 71, 21));
        label_11 = new QLabel(groupBox_5);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(10, 80, 53, 14));
        comboBox_3 = new QComboBox(groupBox_5);
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));
        comboBox_3->setGeometry(QRect(70, 80, 71, 21));
        label_13 = new QLabel(groupBox_5);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(10, 100, 53, 14));
        comboBox_5 = new QComboBox(groupBox_5);
        comboBox_5->setObjectName(QString::fromUtf8("comboBox_5"));
        comboBox_5->setGeometry(QRect(70, 100, 71, 21));
        label_14 = new QLabel(groupBox_5);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(10, 120, 71, 16));
        spinBox_2 = new QSpinBox(groupBox_5);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setGeometry(QRect(90, 120, 53, 24));
        label_4 = new QLabel(groupBox_5);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 20, 53, 14));
        lineEdit = new QLineEdit(groupBox_5);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(50, 20, 91, 21));
        pushButton = new QPushButton(groupBox_5);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(20, 150, 85, 27));
        groupBox_4 = new QGroupBox(groupBox);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(170, 110, 120, 80));
        groupBox_4->setStyleSheet(QString::fromUtf8("QGroupBox { \n"
"     border: 1px solid black; \n"
"     border-radius: 1px; \n"
" } "));
        groupBox_4->setCheckable(true);
        label_5 = new QLabel(groupBox_4);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 20, 31, 16));
        spinBox_3 = new QSpinBox(groupBox_4);
        spinBox_3->setObjectName(QString::fromUtf8("spinBox_3"));
        spinBox_3->setGeometry(QRect(50, 20, 53, 21));
        spinBox_3->setMaximum(12);
        doubleSpinBox_3 = new QDoubleSpinBox(groupBox_4);
        doubleSpinBox_3->setObjectName(QString::fromUtf8("doubleSpinBox_3"));
        doubleSpinBox_3->setGeometry(QRect(60, 50, 51, 20));
        label_6 = new QLabel(groupBox_4);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(0, 50, 61, 16));

        verticalLayout->addWidget(groupBox);


        verticalLayout_2->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 501, 22));
        menuMenu = new QMenu(menuBar);
        menuMenu->setObjectName(QString::fromUtf8("menuMenu"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuMenu->menuAction());
        menuMenu->addAction(actionLoad_STL_mesh);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionLoad_STL_mesh->setText(QApplication::translate("MainWindow", "Load STL mesh", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "Controls", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "STL view", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Opacity", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("MainWindow", "Wireframe", 0, QApplication::UnicodeUTF8));
        checkBox_2->setText(QApplication::translate("MainWindow", "Edges visible", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Camera", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "FSAA", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Cam angle", 0, QApplication::UnicodeUTF8));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "HW Control", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MainWindow", "Reference", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("MainWindow", "Tool", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("MainWindow", "Catheter", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("MainWindow", "updates/sec.", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Port", 0, QApplication::UnicodeUTF8));
        lineEdit->setText(QApplication::translate("MainWindow", "/dev/ttyUSB0", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "Run", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Tool view", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "FSAA", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "Cam angle", 0, QApplication::UnicodeUTF8));
        menuMenu->setTitle(QApplication::translate("MainWindow", "Menu", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
