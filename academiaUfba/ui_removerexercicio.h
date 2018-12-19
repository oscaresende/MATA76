/********************************************************************************
** Form generated from reading UI file 'removerexercicio.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REMOVEREXERCICIO_H
#define UI_REMOVEREXERCICIO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_removerExercicio
{
public:
    QDialogButtonBox *buttonBox;
    QComboBox *comboBox;
    QLabel *label;

    void setupUi(QDialog *removerExercicio)
    {
        if (removerExercicio->objectName().isEmpty())
            removerExercicio->setObjectName(QStringLiteral("removerExercicio"));
        removerExercicio->resize(502, 191);
        buttonBox = new QDialogButtonBox(removerExercicio);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 120, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        comboBox = new QComboBox(removerExercicio);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(140, 60, 301, 22));
        label = new QLabel(removerExercicio);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 60, 111, 20));

        retranslateUi(removerExercicio);
        QObject::connect(buttonBox, SIGNAL(accepted()), removerExercicio, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), removerExercicio, SLOT(reject()));

        QMetaObject::connectSlotsByName(removerExercicio);
    } // setupUi

    void retranslateUi(QDialog *removerExercicio)
    {
        removerExercicio->setWindowTitle(QApplication::translate("removerExercicio", "Dialog", nullptr));
        label->setText(QApplication::translate("removerExercicio", "Nome do Exerc\303\255cio", nullptr));
    } // retranslateUi

};

namespace Ui {
    class removerExercicio: public Ui_removerExercicio {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REMOVEREXERCICIO_H
