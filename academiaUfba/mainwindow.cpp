#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addaluno.h"
#include "addpro.h"
#include "aluno.h"
#include "professor.h"
#include "dbmanager.h"
#include "QString"
#include "QDebug"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_2, SIGNAL(clicked()),this, SLOT(busca_aluno_por_matricula()));
    connect(ui->pushButton_3, SIGNAL(clicked()),this, SLOT(busca_professor_por_matricula()));

    addInstAluno = new AddAluno();
    connect(ui->actionNovo_aluno,SIGNAL(triggered()),addInstAluno, SLOT(show()));

    addInstProfessor = new addpro();
    connect(ui->actionNovo_Professor,SIGNAL(triggered()),addInstProfessor, SLOT(show()));

    DbManager *dbm = new DbManager("fitnessUfba");

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

void MainWindow::busca_aluno_por_matricula()
{
    DbManager *dbm = new DbManager("fitnessUfba");
    Aluno Pesquisa = dbm->busca_aluno(ui->lineEdit->text());

    if(Pesquisa.matricula!="")
    {
        AddAluno *tela2 = new AddAluno(NULL, &Pesquisa);
        tela2->setWindowTitle("Consultando aluno");
        tela2->show();    
    }

    dbm->m_db.close();
}

void MainWindow::busca_professor_por_matricula()
{
    DbManager *dbm = new DbManager("fitnessUfba");
    Professor Pesquisa = dbm->busca_professor(ui->lineEdit_2->text());

    if(Pesquisa.matricula!="")
    {
        addpro *tela2 = new addpro(NULL, &Pesquisa);
        tela2->setWindowTitle("Consultando professor");
        tela2->show();
    }

    dbm->m_db.close();
}

