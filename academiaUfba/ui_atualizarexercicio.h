/********************************************************************************
** Form generated from reading UI file 'atualizarexercicio.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ATUALIZAREXERCICIO_H
#define UI_ATUALIZAREXERCICIO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_atualizarExercicio
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *lineEdit;
    QLabel *label;

    void setupUi(QDialog *atualizarExercicio)
    {
        if (atualizarExercicio->objectName().isEmpty())
            atualizarExercicio->setObjectName(QStringLiteral("atualizarExercicio"));
        atualizarExercicio->resize(341, 225);
        buttonBox = new QDialogButtonBox(atualizarExercicio);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 160, 241, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        lineEdit = new QLineEdit(atualizarExercicio);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(180, 70, 113, 22));
        label = new QLabel(atualizarExercicio);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 70, 141, 20));

        retranslateUi(atualizarExercicio);
        QObject::connect(buttonBox, SIGNAL(accepted()), atualizarExercicio, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), atualizarExercicio, SLOT(reject()));

        QMetaObject::connectSlotsByName(atualizarExercicio);
    } // setupUi

    void retranslateUi(QDialog *atualizarExercicio)
    {
        atualizarExercicio->setWindowTitle(QApplication::translate("atualizarExercicio", "Dialog", nullptr));
        label->setText(QApplication::translate("atualizarExercicio", "C\303\263digo do Exerc\303\255cio", nullptr));
    } // retranslateUi

};

namespace Ui {
    class atualizarExercicio: public Ui_atualizarExercicio {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ATUALIZAREXERCICIO_H
