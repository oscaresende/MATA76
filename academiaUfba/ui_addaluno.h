/********************************************************************************
** Form generated from reading UI file 'addaluno.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDALUNO_H
#define UI_ADDALUNO_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddAluno
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *lineEdit_5;
    QLabel *label_6;
    QLineEdit *lineEdit_6;
    QDateEdit *dateEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_7;
    QLineEdit *lineEdit_7;
    QToolButton *toolButton;
    QLabel *image_label;

    void setupUi(QWidget *AddAluno)
    {
        if (AddAluno->objectName().isEmpty())
            AddAluno->setObjectName(QStringLiteral("AddAluno"));
        AddAluno->resize(592, 300);
        QIcon icon;
        icon.addFile(QStringLiteral("icone.png"), QSize(), QIcon::Normal, QIcon::Off);
        AddAluno->setWindowIcon(icon);
        label = new QLabel(AddAluno);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 59, 91, 16));
        label_2 = new QLabel(AddAluno);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 89, 61, 16));
        lineEdit = new QLineEdit(AddAluno);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(120, 55, 261, 20));
        lineEdit_2 = new QLineEdit(AddAluno);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(120, 82, 261, 20));
        label_3 = new QLabel(AddAluno);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 119, 51, 16));
        lineEdit_3 = new QLineEdit(AddAluno);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(120, 112, 261, 20));
        label_4 = new QLabel(AddAluno);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 149, 51, 16));
        label_5 = new QLabel(AddAluno);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 179, 51, 16));
        lineEdit_5 = new QLineEdit(AddAluno);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(120, 172, 261, 20));
        label_6 = new QLabel(AddAluno);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(20, 209, 51, 16));
        lineEdit_6 = new QLineEdit(AddAluno);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(120, 202, 261, 20));
        dateEdit = new QDateEdit(AddAluno);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setGeometry(QRect(120, 142, 110, 22));
        pushButton = new QPushButton(AddAluno);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(290, 270, 75, 23));
        pushButton_2 = new QPushButton(AddAluno);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(200, 270, 75, 23));
        label_7 = new QLabel(AddAluno);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(20, 20, 91, 16));
        lineEdit_7 = new QLineEdit(AddAluno);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));
        lineEdit_7->setGeometry(QRect(120, 20, 81, 20));
        toolButton = new QToolButton(AddAluno);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setGeometry(QRect(560, 230, 27, 22));
        image_label = new QLabel(AddAluno);
        image_label->setObjectName(QStringLiteral("image_label"));
        image_label->setGeometry(QRect(390, 56, 191, 161));

        retranslateUi(AddAluno);

        QMetaObject::connectSlotsByName(AddAluno);
    } // setupUi

    void retranslateUi(QWidget *AddAluno)
    {
        AddAluno->setWindowTitle(QApplication::translate("AddAluno", "Form", nullptr));
        label->setText(QApplication::translate("AddAluno", "Nome Completo", nullptr));
        label_2->setText(QApplication::translate("AddAluno", "Endere\303\247o", nullptr));
        label_3->setText(QApplication::translate("AddAluno", "Telefone", nullptr));
        label_4->setText(QApplication::translate("AddAluno", "Dt. Nasc.", nullptr));
        label_5->setText(QApplication::translate("AddAluno", "E-mail", nullptr));
        label_6->setText(QApplication::translate("AddAluno", "CPF", nullptr));
        pushButton->setText(QApplication::translate("AddAluno", "Cancelar", nullptr));
        pushButton_2->setText(QApplication::translate("AddAluno", "Cadastrar", nullptr));
        label_7->setText(QApplication::translate("AddAluno", "Matricula", nullptr));
        toolButton->setText(QApplication::translate("AddAluno", "...", nullptr));
        image_label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AddAluno: public Ui_AddAluno {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDALUNO_H
