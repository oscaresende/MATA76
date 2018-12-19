/********************************************************************************
** Form generated from reading UI file 'atualizarprofessor.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ATUALIZARPROFESSOR_H
#define UI_ATUALIZARPROFESSOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_atualizarProfessor
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLineEdit *lineEdit;

    void setupUi(QDialog *atualizarProfessor)
    {
        if (atualizarProfessor->objectName().isEmpty())
            atualizarProfessor->setObjectName(QStringLiteral("atualizarProfessor"));
        atualizarProfessor->resize(328, 190);
        buttonBox = new QDialogButtonBox(atualizarProfessor);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(40, 120, 231, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(atualizarProfessor);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 60, 141, 20));
        lineEdit = new QLineEdit(atualizarProfessor);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(180, 60, 113, 22));

        retranslateUi(atualizarProfessor);
        QObject::connect(buttonBox, SIGNAL(accepted()), atualizarProfessor, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), atualizarProfessor, SLOT(reject()));

        QMetaObject::connectSlotsByName(atualizarProfessor);
    } // setupUi

    void retranslateUi(QDialog *atualizarProfessor)
    {
        atualizarProfessor->setWindowTitle(QApplication::translate("atualizarProfessor", "Dialog", nullptr));
        label->setText(QApplication::translate("atualizarProfessor", "Matr\303\255cula do Professor", nullptr));
    } // retranslateUi

};

namespace Ui {
    class atualizarProfessor: public Ui_atualizarProfessor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ATUALIZARPROFESSOR_H
