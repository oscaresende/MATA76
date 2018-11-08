/********************************************************************************
** Form generated from reading UI file 'addprofessor.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDPROFESSOR_H
#define UI_ADDPROFESSOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addprofessor
{
public:
    QLabel *image_label;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QDateEdit *dateEdit;
    QLineEdit *lineEdit_7;
    QLabel *label_5;
    QLabel *label_7;
    QToolButton *toolButton;
    QLineEdit *lineEdit_5;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QLabel *label;
    QLabel *label_6;
    QLabel *label_4;
    QLineEdit *lineEdit_6;
    QLabel *label_2;
    QPushButton *pushButton;

    void setupUi(QWidget *addprofessor)
    {
        if (addprofessor->objectName().isEmpty())
            addprofessor->setObjectName(QStringLiteral("addprofessor"));
        addprofessor->resize(579, 291);
        image_label = new QLabel(addprofessor);
        image_label->setObjectName(QStringLiteral("image_label"));
        image_label->setGeometry(QRect(380, 46, 191, 161));
        lineEdit_2 = new QLineEdit(addprofessor);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(110, 72, 261, 20));
        lineEdit_3 = new QLineEdit(addprofessor);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(110, 102, 261, 20));
        dateEdit = new QDateEdit(addprofessor);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setGeometry(QRect(110, 132, 110, 22));
        lineEdit_7 = new QLineEdit(addprofessor);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));
        lineEdit_7->setGeometry(QRect(110, 10, 81, 20));
        label_5 = new QLabel(addprofessor);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 169, 51, 16));
        label_7 = new QLabel(addprofessor);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 10, 91, 16));
        toolButton = new QToolButton(addprofessor);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setGeometry(QRect(550, 220, 27, 22));
        lineEdit_5 = new QLineEdit(addprofessor);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(110, 162, 261, 20));
        pushButton_2 = new QPushButton(addprofessor);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(190, 260, 75, 23));
        lineEdit = new QLineEdit(addprofessor);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(110, 45, 261, 20));
        label_3 = new QLabel(addprofessor);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 109, 51, 16));
        label = new QLabel(addprofessor);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 49, 91, 16));
        label_6 = new QLabel(addprofessor);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 199, 51, 16));
        label_4 = new QLabel(addprofessor);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 139, 51, 16));
        lineEdit_6 = new QLineEdit(addprofessor);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(110, 192, 261, 20));
        label_2 = new QLabel(addprofessor);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 79, 61, 16));
        pushButton = new QPushButton(addprofessor);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(280, 260, 75, 23));

        retranslateUi(addprofessor);

        QMetaObject::connectSlotsByName(addprofessor);
    } // setupUi

    void retranslateUi(QWidget *addprofessor)
    {
        addprofessor->setWindowTitle(QApplication::translate("addprofessor", "Form", nullptr));
        image_label->setText(QString());
        label_5->setText(QApplication::translate("addprofessor", "E-mail", nullptr));
        label_7->setText(QApplication::translate("addprofessor", "Matricula", nullptr));
        toolButton->setText(QApplication::translate("addprofessor", "...", nullptr));
        pushButton_2->setText(QApplication::translate("addprofessor", "Cadastrar", nullptr));
        label_3->setText(QApplication::translate("addprofessor", "Telefone", nullptr));
        label->setText(QApplication::translate("addprofessor", "Nome Completo", nullptr));
        label_6->setText(QApplication::translate("addprofessor", "CPF", nullptr));
        label_4->setText(QApplication::translate("addprofessor", "Dt. Nasc.", nullptr));
        label_2->setText(QApplication::translate("addprofessor", "Endere\303\247o", nullptr));
        pushButton->setText(QApplication::translate("addprofessor", "Cancelar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addprofessor: public Ui_addprofessor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDPROFESSOR_H
