/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNovo_aluno;
    QAction *actionNovo_Professor;
    QAction *actionNovo_Exerc_cio;
    QAction *actionNovo_Treino;
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QLineEdit *lineEdit;
    QLabel *label;
    QPushButton *pushButton_2;
    QGroupBox *groupBox_2;
    QLineEdit *lineEdit_2;
    QLabel *label_2;
    QPushButton *pushButton_3;
    QGroupBox *groupBox_3;
    QLineEdit *lineEdit_3;
    QLabel *label_3;
    QPushButton *pushButton_4;
    QTableView *tableView;
    QMenuBar *menuBar;
    QMenu *menuCadastro;
    QMenu *menuTreinos;
    QMenu *menuConfigura_es;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1022, 826);
        actionNovo_aluno = new QAction(MainWindow);
        actionNovo_aluno->setObjectName(QStringLiteral("actionNovo_aluno"));
        actionNovo_Professor = new QAction(MainWindow);
        actionNovo_Professor->setObjectName(QStringLiteral("actionNovo_Professor"));
        actionNovo_Exerc_cio = new QAction(MainWindow);
        actionNovo_Exerc_cio->setObjectName(QStringLiteral("actionNovo_Exerc_cio"));
        actionNovo_Treino = new QAction(MainWindow);
        actionNovo_Treino->setObjectName(QStringLiteral("actionNovo_Treino"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 320, 181, 131));
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(10, 47, 113, 22));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 30, 55, 16));
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(130, 47, 41, 21));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 460, 181, 131));
        lineEdit_2 = new QLineEdit(groupBox_2);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(10, 47, 113, 22));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 30, 55, 16));
        pushButton_3 = new QPushButton(groupBox_2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(130, 47, 41, 21));
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 610, 181, 131));
        lineEdit_3 = new QLineEdit(groupBox_3);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(10, 47, 113, 22));
        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 30, 55, 16));
        pushButton_4 = new QPushButton(groupBox_3);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(130, 47, 41, 21));
        tableView = new QTableView(centralWidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(0, 0, 671, 192));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1022, 22));
        menuCadastro = new QMenu(menuBar);
        menuCadastro->setObjectName(QStringLiteral("menuCadastro"));
        menuTreinos = new QMenu(menuBar);
        menuTreinos->setObjectName(QStringLiteral("menuTreinos"));
        menuConfigura_es = new QMenu(menuBar);
        menuConfigura_es->setObjectName(QStringLiteral("menuConfigura_es"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuCadastro->menuAction());
        menuBar->addAction(menuTreinos->menuAction());
        menuBar->addAction(menuConfigura_es->menuAction());
        menuCadastro->addAction(actionNovo_aluno);
        menuCadastro->addAction(actionNovo_Professor);
        menuTreinos->addAction(actionNovo_Treino);
        menuConfigura_es->addAction(actionNovo_Exerc_cio);
        mainToolBar->addSeparator();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Fitness UFBA", nullptr));
        actionNovo_aluno->setText(QApplication::translate("MainWindow", "Novo aluno", nullptr));
        actionNovo_Professor->setText(QApplication::translate("MainWindow", "Novo Professor", nullptr));
        actionNovo_Exerc_cio->setText(QApplication::translate("MainWindow", "Novo Exerc\303\255cio", nullptr));
        actionNovo_Treino->setText(QApplication::translate("MainWindow", "Novo Treino", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "Pesquisar Aluno", nullptr));
        label->setText(QApplication::translate("MainWindow", "Matricula", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "OK", nullptr));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Pesquisar Professor", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Matricula", nullptr));
        pushButton_3->setText(QApplication::translate("MainWindow", "OK", nullptr));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Pesquisar Exerc\303\255cio", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Matricula", nullptr));
        pushButton_4->setText(QApplication::translate("MainWindow", "OK", nullptr));
        menuCadastro->setTitle(QApplication::translate("MainWindow", "Cadastro", nullptr));
        menuTreinos->setTitle(QApplication::translate("MainWindow", "Treinos", nullptr));
        menuConfigura_es->setTitle(QApplication::translate("MainWindow", "Configura\303\247\303\265es", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
