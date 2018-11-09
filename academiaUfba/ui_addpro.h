/********************************************************************************
** Form generated from reading UI file 'addpro.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDPRO_H
#define UI_ADDPRO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addpro
{
public:
    QLineEdit *lineEdit_7;
    QLineEdit *lineEdit_6;
    QLabel *image_label;
    QDateEdit *dateEdit;
    QLabel *label_3;
    QLabel *label_2;
    QLineEdit *lineEdit_5;
    QPushButton *pushButton_2;
    QLabel *label;
    QPushButton *pushButton;
    QLabel *label_4;
    QLineEdit *lineEdit_3;
    QLabel *label_5;
    QLineEdit *lineEdit_2;
    QToolButton *toolButton;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *lineEdit;

    void setupUi(QWidget *addpro)
    {
        if (addpro->objectName().isEmpty())
            addpro->setObjectName(QStringLiteral("addpro"));
        addpro->resize(578, 311);
        lineEdit_7 = new QLineEdit(addpro);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));
        lineEdit_7->setGeometry(QRect(110, 15, 81, 20));
        lineEdit_6 = new QLineEdit(addpro);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(110, 197, 261, 20));
        image_label = new QLabel(addpro);
        image_label->setObjectName(QStringLiteral("image_label"));
        image_label->setGeometry(QRect(380, 51, 191, 161));
        dateEdit = new QDateEdit(addpro);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setGeometry(QRect(110, 137, 110, 22));
        label_3 = new QLabel(addpro);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 114, 51, 16));
        label_2 = new QLabel(addpro);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 84, 61, 16));
        lineEdit_5 = new QLineEdit(addpro);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(110, 167, 261, 20));
        pushButton_2 = new QPushButton(addpro);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(190, 265, 75, 23));
        label = new QLabel(addpro);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 54, 91, 16));
        pushButton = new QPushButton(addpro);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(280, 265, 75, 23));
        label_4 = new QLabel(addpro);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 144, 51, 16));
        lineEdit_3 = new QLineEdit(addpro);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(110, 107, 261, 20));
        label_5 = new QLabel(addpro);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 174, 51, 16));
        lineEdit_2 = new QLineEdit(addpro);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(110, 77, 261, 20));
        toolButton = new QToolButton(addpro);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setGeometry(QRect(550, 225, 27, 22));
        label_6 = new QLabel(addpro);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 204, 51, 16));
        label_7 = new QLabel(addpro);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 15, 91, 16));
        lineEdit = new QLineEdit(addpro);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(110, 50, 261, 20));

        retranslateUi(addpro);

        QMetaObject::connectSlotsByName(addpro);
    } // setupUi

    void retranslateUi(QWidget *addpro)
    {
        addpro->setWindowTitle(QApplication::translate("addpro", "Form", nullptr));
        image_label->setText(QString());
        label_3->setText(QApplication::translate("addpro", "Telefone", nullptr));
        label_2->setText(QApplication::translate("addpro", "Endere\303\247o", nullptr));
        pushButton_2->setText(QApplication::translate("addpro", "Cadastrar", nullptr));
        label->setText(QApplication::translate("addpro", "Nome Completo", nullptr));
        pushButton->setText(QApplication::translate("addpro", "Cancelar", nullptr));
        label_4->setText(QApplication::translate("addpro", "Dt. Nasc.", nullptr));
        label_5->setText(QApplication::translate("addpro", "E-mail", nullptr));
        toolButton->setText(QApplication::translate("addpro", "...", nullptr));
        label_6->setText(QApplication::translate("addpro", "CPF", nullptr));
        label_7->setText(QApplication::translate("addpro", "Matricula", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addpro: public Ui_addpro {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDPRO_H
