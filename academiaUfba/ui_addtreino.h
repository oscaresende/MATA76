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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addTreino
{
public:
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QLineEdit *lineEdit;
    QDateEdit *dateEdit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_5;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QTableWidget *tableWidget;
    QTableWidget *tableWidget_2;

    void setupUi(QWidget *addTreino)
    {
        if (addTreino->objectName().isEmpty())
            addTreino->setObjectName(QStringLiteral("addTreino"));
        addTreino->resize(780, 589);
        QIcon icon;
        icon.addFile(QStringLiteral("icone.png"), QSize(), QIcon::Normal, QIcon::Off);
        addTreino->setWindowIcon(icon);
        comboBox = new QComboBox(addTreino);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(90, 40, 231, 22));
        comboBox_2 = new QComboBox(addTreino);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setGeometry(QRect(90, 80, 231, 22));
        lineEdit = new QLineEdit(addTreino);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(90, 160, 41, 22));
        dateEdit = new QDateEdit(addTreino);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setGeometry(QRect(90, 120, 110, 22));
        label = new QLabel(addTreino);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 40, 55, 16));
        label_2 = new QLabel(addTreino);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 80, 55, 16));
        label_3 = new QLabel(addTreino);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 120, 55, 16));
        label_5 = new QLabel(addTreino);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 160, 55, 16));
        pushButton = new QPushButton(addTreino);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(280, 550, 93, 28));
        pushButton_2 = new QPushButton(addTreino);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(380, 550, 93, 28));
        pushButton_3 = new QPushButton(addTreino);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(360, 350, 41, 28));
        pushButton_4 = new QPushButton(addTreino);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(360, 390, 41, 28));
        tableWidget = new QTableWidget(addTreino);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(10, 240, 341, 281));
        tableWidget_2 = new QTableWidget(addTreino);
        tableWidget_2->setObjectName(QStringLiteral("tableWidget_2"));
        tableWidget_2->setGeometry(QRect(410, 240, 361, 281));

        retranslateUi(addTreino);

        QMetaObject::connectSlotsByName(addTreino);
    } // setupUi

    void retranslateUi(QWidget *addTreino)
    {
        addTreino->setWindowTitle(QApplication::translate("addTreino", "Form", nullptr));
        label->setText(QApplication::translate("addTreino", "Aluno", nullptr));
        label_2->setText(QApplication::translate("addTreino", "Professor", nullptr));
        label_3->setText(QApplication::translate("addTreino", "Inicio", nullptr));
        label_5->setText(QApplication::translate("addTreino", "Dias", nullptr));
        pushButton->setText(QApplication::translate("addTreino", "Cadastrar", nullptr));
        pushButton_2->setText(QApplication::translate("addTreino", "Cancelar", nullptr));
        pushButton_3->setText(QApplication::translate("addTreino", ">", nullptr));
        pushButton_4->setText(QApplication::translate("addTreino", "<", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addTreino: public Ui_addTreino {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDTREINO_H
