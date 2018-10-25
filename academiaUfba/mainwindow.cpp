#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addaluno.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()),this, SLOT(add_aluno()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::add_aluno()
{
    AddAluno *tela2 = new AddAluno();
    tela2->setWindowTitle("Adicionar Aluno");
    tela2->show();
}
