#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addaluno.h"
#include "aluno.h"
#include "dbmanager.h"
#include "QString"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()),this, SLOT(add_aluno()));    

    DbManager *dbm = new DbManager("D:/banco de dados/fitnessUfba.db");

    model = new QSqlQueryModel(this);
    model->setQuery(dbm->listarAlunos(),dbm->m_db);
    proxyModel = new QSortFilterProxyModel(this);
    proxyModel->setSourceModel(model);
    proxyModel->setFilterCaseSensitivity(Qt::CaseInsensitive);
    ui->tableView->setModel(proxyModel);
    ui->tableView->show();
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
