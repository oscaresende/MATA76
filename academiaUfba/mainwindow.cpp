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
    connect(ui->pushButton_4, SIGNAL(clicked()),this, SLOT(busca_exercicio_por_codigo()));

    connect(ui->actionNovo_aluno,SIGNAL(triggered()),this, SLOT(abrir_tela_cadastro_aluno()));
    connect(ui->actionNovo_Professor,SIGNAL(triggered()),this, SLOT(abrir_tela_cadastro_professor()));
    connect(ui->actionNovo_Exerc_cio,SIGNAL(triggered()),this, SLOT(abrir_tela_cadastro_exercicio()));
    connect(ui->actionNovo_Treino,SIGNAL(triggered()),this, SLOT(abrir_tela_cadastro_treino()));

    DbManager *dbm = new DbManager("fitnessUfba");

    //model = new QSqlQueryModel(this);
    //model->setQuery(dbm->listarAlunos(),dbm->m_db);
    //proxyModel = new QSortFilterProxyModel(this);
    //proxyModel->setSourceModel(model);
    //proxyModel->setFilterCaseSensitivity(Qt::CaseInsensitive);
    //ui->tableView->setModel(proxyModel);
    //ui->tableView->show();
}

MainWindow::~MainWindow()
{
    delete ui;
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

void MainWindow::busca_exercicio_por_codigo()
{
    DbManager *dbm = new DbManager("fitnessUfba");
    exercicio Pesquisa = dbm->busca_exercicio(ui->lineEdit_3->text());

    if(Pesquisa.codigo!="")
    {
        addexercicio *tela2 = new addexercicio(NULL, &Pesquisa);
        tela2->setWindowTitle("Consultando exercicio");
        tela2->show();
    }

    dbm->m_db.close();
}

void MainWindow::abrir_tela_cadastro_aluno()
{
    addInstAluno = new AddAluno();
    addInstAluno->setWindowTitle("Cadastro de Aluno");
    addInstAluno->show();
}

void MainWindow::abrir_tela_cadastro_professor()
{
    addInstProfessor = new addpro();
    addInstProfessor->setWindowTitle("Cadastro de Professor");
    addInstProfessor->show();
}


void MainWindow::abrir_tela_cadastro_exercicio()
{
    addInstExercicio = new addexercicio();
    addInstExercicio->setWindowTitle("Cadastro de Exercício");
    addInstExercicio->show();
}

void MainWindow::abrir_tela_cadastro_treino()
{
    addInstTreino = new addTreino();
    addInstTreino->setWindowTitle("Cadastro de Treino");
    addInstTreino->show();
}
