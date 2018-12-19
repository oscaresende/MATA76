/********************************************************************************
** Form generated from reading UI file 'atualizaraluno.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ATUALIZARALUNO_H
#define UI_ATUALIZARALUNO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_atualizarAluno
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLineEdit *lineEdit;

    void setupUi(QDialog *atualizarAluno)
    {
        if (atualizarAluno->objectName().isEmpty())
            atualizarAluno->setObjectName(QStringLiteral("atualizarAluno"));
        atualizarAluno->resize(386, 193);
        buttonBox = new QDialogButtonBox(atualizarAluno);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(90, 130, 211, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(atualizarAluno);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 50, 121, 20));
        lineEdit = new QLineEdit(atualizarAluno);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(210, 50, 113, 22));

        retranslateUi(atualizarAluno);
        QObject::connect(buttonBox, SIGNAL(accepted()), atualizarAluno, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), atualizarAluno, SLOT(reject()));

        QMetaObject::connectSlotsByName(atualizarAluno);
    } // setupUi

    void retranslateUi(QDialog *atualizarAluno)
    {
        atualizarAluno->setWindowTitle(QApplication::translate("atualizarAluno", "Dialog", nullptr));
        label->setText(QApplication::translate("atualizarAluno", "Matr\303\255cula do Aluno", nullptr));
    } // retranslateUi

};

namespace Ui {
    class atualizarAluno: public Ui_atualizarAluno {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ATUALIZARALUNO_H
