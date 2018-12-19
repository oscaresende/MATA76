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
#include <QtGui/QIcon>
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
    QAction *actionNovo_Exerc_cio;
    QAction *actionNovo_Treino;
    QAction *actionNovo_Professor_2;
    QAction *actionRemover_Exerc_cio;
    QAction *actionRemover_Professor;
    QAction *actionRemover_Aluno;
    QAction *actionAtualizar;
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
    QLabel *label_5;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QMenu *menuCadastro;
    QMenu *menuTreinos;
    QMenu *menuConfigura_es;
    QMenu *menuProfessor;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1022, 826);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        MainWindow->setPalette(palette);
        QIcon icon;
        icon.addFile(QStringLiteral("icone.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionNovo_aluno = new QAction(MainWindow);
        actionNovo_aluno->setObjectName(QStringLiteral("actionNovo_aluno"));
        actionNovo_Exerc_cio = new QAction(MainWindow);
        actionNovo_Exerc_cio->setObjectName(QStringLiteral("actionNovo_Exerc_cio"));
        actionNovo_Treino = new QAction(MainWindow);
        actionNovo_Treino->setObjectName(QStringLiteral("actionNovo_Treino"));
        actionNovo_Professor_2 = new QAction(MainWindow);
        actionNovo_Professor_2->setObjectName(QStringLiteral("actionNovo_Professor_2"));
        actionRemover_Exerc_cio = new QAction(MainWindow);
        actionRemover_Exerc_cio->setObjectName(QStringLiteral("actionRemover_Exerc_cio"));
        actionRemover_Professor = new QAction(MainWindow);
        actionRemover_Professor->setObjectName(QStringLiteral("actionRemover_Professor"));
        actionRemover_Aluno = new QAction(MainWindow);
        actionRemover_Aluno->setObjectName(QStringLiteral("actionRemover_Aluno"));
        actionAtualizar = new QAction(MainWindow);
        actionAtualizar->setObjectName(QStringLiteral("actionAtualizar"));
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
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(811, 1, 200, 16));
        QPalette palette1;
        QBrush brush1(QColor(0, 0, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        QBrush brush2(QColor(120, 120, 120, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        label_5->setPalette(palette1);
        label_5->setTextFormat(Qt::AutoText);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(920, 20, 93, 28));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1022, 26));
        menuCadastro = new QMenu(menuBar);
        menuCadastro->setObjectName(QStringLiteral("menuCadastro"));
        menuTreinos = new QMenu(menuBar);
        menuTreinos->setObjectName(QStringLiteral("menuTreinos"));
        menuConfigura_es = new QMenu(menuBar);
        menuConfigura_es->setObjectName(QStringLiteral("menuConfigura_es"));
        menuProfessor = new QMenu(menuBar);
        menuProfessor->setObjectName(QStringLiteral("menuProfessor"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuCadastro->menuAction());
        menuBar->addAction(menuProfessor->menuAction());
        menuBar->addAction(menuConfigura_es->menuAction());
        menuBar->addAction(menuTreinos->menuAction());
        menuCadastro->addAction(actionNovo_aluno);
        menuCadastro->addAction(actionRemover_Aluno);
        menuCadastro->addAction(actionAtualizar);
        menuTreinos->addAction(actionNovo_Treino);
        menuConfigura_es->addAction(actionNovo_Exerc_cio);
        menuConfigura_es->addAction(actionRemover_Exerc_cio);
        menuProfessor->addAction(actionNovo_Professor_2);
        menuProfessor->addAction(actionRemover_Professor);
        mainToolBar->addSeparator();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Fitness UFBA", nullptr));
        actionNovo_aluno->setText(QApplication::translate("MainWindow", "Novo Aluno", nullptr));
        actionNovo_Exerc_cio->setText(QApplication::translate("MainWindow", "Novo Exerc\303\255cio", nullptr));
        actionNovo_Treino->setText(QApplication::translate("MainWindow", "Novo Treino", nullptr));
        actionNovo_Professor_2->setText(QApplication::translate("MainWindow", "Novo Professor", nullptr));
        actionRemover_Exerc_cio->setText(QApplication::translate("MainWindow", "Remover Exerc\303\255cio", nullptr));
        actionRemover_Professor->setText(QApplication::translate("MainWindow", "Remover Professor", nullptr));
        actionRemover_Aluno->setText(QApplication::translate("MainWindow", "Remover Aluno", nullptr));
        actionAtualizar->setText(QApplication::translate("MainWindow", "Atualizar ", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "Pesquisar Aluno", nullptr));
        label->setText(QApplication::translate("MainWindow", "Matricula", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "OK", nullptr));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Pesquisar Professor", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Matricula", nullptr));
        pushButton_3->setText(QApplication::translate("MainWindow", "OK", nullptr));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Pesquisar Exerc\303\255cio", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "C\303\263digo", nullptr));
        pushButton_4->setText(QApplication::translate("MainWindow", "OK", nullptr));
        label_5->setText(QString());
        pushButton->setText(QApplication::translate("MainWindow", "Login", nullptr));
        menuCadastro->setTitle(QApplication::translate("MainWindow", "Aluno", nullptr));
        menuTreinos->setTitle(QApplication::translate("MainWindow", "Treinos", nullptr));
        menuConfigura_es->setTitle(QApplication::translate("MainWindow", "Exerc\303\255cio", nullptr));
        menuProfessor->setTitle(QApplication::translate("MainWindow", "Professor", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
