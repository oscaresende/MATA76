/********************************************************************************
** Form generated from reading UI file 'addexercicio.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDEXERCICIO_H
#define UI_ADDEXERCICIO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addexercicio
{
public:
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_7;
    QLabel *label_7;
    QLabel *label_2;
    QToolButton *toolButton;
    QLabel *image_label;
    QPushButton *pushButton;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_2;
    QLabel *label;

    void setupUi(QWidget *addexercicio)
    {
        if (addexercicio->objectName().isEmpty())
            addexercicio->setObjectName(QStringLiteral("addexercicio"));
        addexercicio->resize(631, 300);
        lineEdit = new QLineEdit(addexercicio);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(120, 133, 261, 20));
        lineEdit_7 = new QLineEdit(addexercicio);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));
        lineEdit_7->setGeometry(QRect(120, 98, 81, 20));
        label_7 = new QLabel(addexercicio);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(20, 98, 91, 16));
        label_2 = new QLabel(addexercicio);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 167, 61, 16));
        toolButton = new QToolButton(addexercicio);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setGeometry(QRect(580, 240, 27, 22));
        image_label = new QLabel(addexercicio);
        image_label->setObjectName(QStringLiteral("image_label"));
        image_label->setGeometry(QRect(410, 60, 191, 161));
        pushButton = new QPushButton(addexercicio);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(280, 261, 75, 23));
        lineEdit_2 = new QLineEdit(addexercicio);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(120, 163, 261, 20));
        pushButton_2 = new QPushButton(addexercicio);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(190, 261, 75, 23));
        label = new QLabel(addexercicio);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 137, 91, 16));

        retranslateUi(addexercicio);

        QMetaObject::connectSlotsByName(addexercicio);
    } // setupUi

    void retranslateUi(QWidget *addexercicio)
    {
        addexercicio->setWindowTitle(QApplication::translate("addexercicio", "Form", nullptr));
        label_7->setText(QApplication::translate("addexercicio", "Codigo", nullptr));
        label_2->setText(QApplication::translate("addexercicio", "Descri\303\247\303\243o", nullptr));
        toolButton->setText(QApplication::translate("addexercicio", "...", nullptr));
        image_label->setText(QString());
        pushButton->setText(QApplication::translate("addexercicio", "Cancelar", nullptr));
        pushButton_2->setText(QApplication::translate("addexercicio", "Cadastrar", nullptr));
        label->setText(QApplication::translate("addexercicio", "Nome", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addexercicio: public Ui_addexercicio {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDEXERCICIO_H
