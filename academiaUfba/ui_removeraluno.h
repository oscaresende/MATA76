/********************************************************************************
** Form generated from reading UI file 'removeraluno.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REMOVERALUNO_H
#define UI_REMOVERALUNO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_removeraluno
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QComboBox *comboBox;

    void setupUi(QDialog *removeraluno)
    {
        if (removeraluno->objectName().isEmpty())
            removeraluno->setObjectName(QStringLiteral("removeraluno"));
        removeraluno->resize(481, 189);
        buttonBox = new QDialogButtonBox(removeraluno);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(100, 100, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(removeraluno);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 50, 101, 16));
        comboBox = new QComboBox(removeraluno);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(140, 50, 301, 22));

        retranslateUi(removeraluno);
        QObject::connect(buttonBox, SIGNAL(accepted()), removeraluno, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), removeraluno, SLOT(reject()));

        QMetaObject::connectSlotsByName(removeraluno);
    } // setupUi

    void retranslateUi(QDialog *removeraluno)
    {
        removeraluno->setWindowTitle(QApplication::translate("removeraluno", "Dialog", nullptr));
        label->setText(QApplication::translate("removeraluno", "Nome do Aluno", nullptr));
    } // retranslateUi

};

namespace Ui {
    class removeraluno: public Ui_removeraluno {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REMOVERALUNO_H
