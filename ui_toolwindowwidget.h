/********************************************************************************
** Form generated from reading UI file 'toolwindowwidget.ui'
**
** Created: Mon Nov 12 11:17:53 2012
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOOLWINDOWWIDGET_H
#define UI_TOOLWINDOWWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "QVTKWidget.h"

QT_BEGIN_NAMESPACE

class Ui_ToolWindowWIdget
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QVTKWidget *qvtkWidget;
    QGroupBox *groupBox;

    void setupUi(QWidget *ToolWindowWIdget)
    {
        if (ToolWindowWIdget->objectName().isEmpty())
            ToolWindowWIdget->setObjectName(QString::fromUtf8("ToolWindowWIdget"));
        ToolWindowWIdget->resize(640, 480);
        verticalLayout_2 = new QVBoxLayout(ToolWindowWIdget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        qvtkWidget = new QVTKWidget(ToolWindowWIdget);
        qvtkWidget->setObjectName(QString::fromUtf8("qvtkWidget"));

        verticalLayout->addWidget(qvtkWidget);

        groupBox = new QGroupBox(ToolWindowWIdget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));

        verticalLayout->addWidget(groupBox);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(ToolWindowWIdget);

        QMetaObject::connectSlotsByName(ToolWindowWIdget);
    } // setupUi

    void retranslateUi(QWidget *ToolWindowWIdget)
    {
        ToolWindowWIdget->setWindowTitle(QApplication::translate("ToolWindowWIdget", "Form", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("ToolWindowWIdget", "GroupBox", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ToolWindowWIdget: public Ui_ToolWindowWIdget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOOLWINDOWWIDGET_H
