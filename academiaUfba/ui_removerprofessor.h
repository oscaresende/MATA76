/********************************************************************************
** Form generated from reading UI file 'removerprofessor.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REMOVERPROFESSOR_H
#define UI_REMOVERPROFESSOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_removerProfessor
{
public:
    QDialogButtonBox *buttonBox;
    QComboBox *comboBox;
    QLabel *label;

    void setupUi(QDialog *removerProfessor)
    {
        if (removerProfessor->objectName().isEmpty())
            removerProfessor->setObjectName(QStringLiteral("removerProfessor"));
        removerProfessor->resize(490, 228);
        buttonBox = new QDialogButtonBox(removerProfessor);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(20, 150, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        comboBox = new QComboBox(removerProfessor);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(170, 80, 301, 22));
        label = new QLabel(removerProfessor);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 80, 141, 20));

        retranslateUi(removerProfessor);
        QObject::connect(buttonBox, SIGNAL(accepted()), removerProfessor, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), removerProfessor, SLOT(reject()));

        QMetaObject::connectSlotsByName(removerProfessor);
    } // setupUi

    void retranslateUi(QDialog *removerProfessor)
    {
        removerProfessor->setWindowTitle(QApplication::translate("removerProfessor", "Dialog", nullptr));
        label->setText(QApplication::translate("removerProfessor", "Matr\303\255cula do Professor", nullptr));
    } // retranslateUi

};

namespace Ui {
    class removerProfessor: public Ui_removerProfessor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REMOVERPROFESSOR_H
