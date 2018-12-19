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
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QPushButton *play_pushButton;
    QLabel *movie_label;
    QPushButton *open_pushButton;
    QSlider *frameSlider;
    QPushButton *pause_pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(438, 462);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        play_pushButton = new QPushButton(centralWidget);
        play_pushButton->setObjectName(QStringLiteral("play_pushButton"));

        gridLayout->addWidget(play_pushButton, 2, 1, 1, 1);

        movie_label = new QLabel(centralWidget);
        movie_label->setObjectName(QStringLiteral("movie_label"));
        movie_label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(movie_label, 0, 0, 1, 3);

        open_pushButton = new QPushButton(centralWidget);
        open_pushButton->setObjectName(QStringLiteral("open_pushButton"));

        gridLayout->addWidget(open_pushButton, 2, 0, 1, 1);

        frameSlider = new QSlider(centralWidget);
        frameSlider->setObjectName(QStringLiteral("frameSlider"));
        frameSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(frameSlider, 1, 0, 1, 3);

        pause_pushButton = new QPushButton(centralWidget);
        pause_pushButton->setObjectName(QStringLiteral("pause_pushButton"));

        gridLayout->addWidget(pause_pushButton, 2, 2, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 438, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        play_pushButton->setText(QApplication::translate("MainWindow", "Play", nullptr));
        movie_label->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        open_pushButton->setText(QApplication::translate("MainWindow", "Abrir", nullptr));
        pause_pushButton->setText(QApplication::translate("MainWindow", "Pause", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
