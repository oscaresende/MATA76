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
    QAction *actionNovo_Aluno;
    QAction *actionNovo_Aluno_2;
    QAction *actionNovo_aluno;
    QAction *actionNovo_Professor;
    QWidget *centralWidget;
    QPushButton *pushButton;
    QTableView *tableView;
    QGroupBox *groupBox;
    QLineEdit *lineEdit;
    QLabel *label;
    QPushButton *pushButton_2;
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
        actionNovo_Aluno = new QAction(MainWindow);
        actionNovo_Aluno->setObjectName(QStringLiteral("actionNovo_Aluno"));
        actionNovo_Aluno_2 = new QAction(MainWindow);
        actionNovo_Aluno_2->setObjectName(QStringLiteral("actionNovo_Aluno_2"));
        actionNovo_aluno = new QAction(MainWindow);
        actionNovo_aluno->setObjectName(QStringLiteral("actionNovo_aluno"));
        actionNovo_Professor = new QAction(MainWindow);
        actionNovo_Professor->setObjectName(QStringLiteral("actionNovo_Professor"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 10, 75, 23));
        tableView = new QTableView(centralWidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(10, 60, 861, 221));
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
        MainWindow->insertToolBarBreak(mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuCadastro->menuAction());
        menuBar->addAction(menuTreinos->menuAction());
        menuBar->addAction(menuConfigura_es->menuAction());
        menuCadastro->addAction(actionNovo_aluno);
        menuCadastro->addAction(actionNovo_Professor);
        mainToolBar->addSeparator();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Fitness UFBA", nullptr));
        actionNovo_Aluno->setText(QApplication::translate("MainWindow", "Novo Aluno", nullptr));
        actionNovo_Aluno_2->setText(QApplication::translate("MainWindow", "Novo Aluno", nullptr));
        actionNovo_aluno->setText(QApplication::translate("MainWindow", "Novo aluno", nullptr));
        actionNovo_Professor->setText(QApplication::translate("MainWindow", "Novo Professor", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "Add Aluno", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "Pesquisar Aluno", nullptr));
        label->setText(QApplication::translate("MainWindow", "Matricula", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "OK", nullptr));
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
