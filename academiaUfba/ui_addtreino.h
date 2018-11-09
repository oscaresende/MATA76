/********************************************************************************
** Form generated from reading UI file 'addtreino.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDTREINO_H
#define UI_ADDTREINO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addTreino
{
public:
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QLineEdit *lineEdit;
    QDateEdit *dateEdit;
    QDateEdit *dateEdit_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *addTreino)
    {
        if (addTreino->objectName().isEmpty())
            addTreino->setObjectName(QStringLiteral("addTreino"));
        addTreino->resize(400, 300);
        comboBox = new QComboBox(addTreino);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(90, 40, 231, 22));
        comboBox_2 = new QComboBox(addTreino);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setGeometry(QRect(90, 80, 231, 22));
        lineEdit = new QLineEdit(addTreino);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(90, 200, 41, 22));
        dateEdit = new QDateEdit(addTreino);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setGeometry(QRect(90, 120, 110, 22));
        dateEdit_2 = new QDateEdit(addTreino);
        dateEdit_2->setObjectName(QStringLiteral("dateEdit_2"));
        dateEdit_2->setGeometry(QRect(90, 160, 110, 22));
        label = new QLabel(addTreino);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 40, 55, 16));
        label_2 = new QLabel(addTreino);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 80, 55, 16));
        label_3 = new QLabel(addTreino);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 120, 55, 16));
        label_4 = new QLabel(addTreino);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 160, 55, 16));
        label_5 = new QLabel(addTreino);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 200, 55, 16));
        pushButton = new QPushButton(addTreino);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(80, 250, 93, 28));
        pushButton_2 = new QPushButton(addTreino);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(180, 250, 93, 28));

        retranslateUi(addTreino);

        QMetaObject::connectSlotsByName(addTreino);
    } // setupUi

    void retranslateUi(QWidget *addTreino)
    {
        addTreino->setWindowTitle(QApplication::translate("addTreino", "Form", nullptr));
        label->setText(QApplication::translate("addTreino", "Aluno", nullptr));
        label_2->setText(QApplication::translate("addTreino", "Professor", nullptr));
        label_3->setText(QApplication::translate("addTreino", "Inicio", nullptr));
        label_4->setText(QApplication::translate("addTreino", "Fim", nullptr));
        label_5->setText(QApplication::translate("addTreino", "Dias", nullptr));
        pushButton->setText(QApplication::translate("addTreino", "Cadastrar", nullptr));
        pushButton_2->setText(QApplication::translate("addTreino", "Cancelar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addTreino: public Ui_addTreino {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDTREINO_H
