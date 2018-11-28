#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addaluno.h"
#include "addpro.h"
#include "aluno.h"
#include "professor.h"
#include "dbmanager.h"
#include "QString"
#include "QDebug"
#include "QSignalMapper"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    autenticado = false;

    QPixmap bkgnd("fundo.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    connect(ui->pushButton_2, SIGNAL(clicked()),this, SLOT(busca_aluno_por_matricula()));
    connect(ui->pushButton_3, SIGNAL(clicked()),this, SLOT(busca_professor_por_matricula()));    
    connect(ui->pushButton_4, SIGNAL(clicked()),this, SLOT(busca_exercicio_por_codigo()));
    connect(ui->pushButton,SIGNAL(clicked()),this, SLOT(logar()));

    connect(ui->actionNovo_aluno,SIGNAL(triggered()),this, SLOT(abrir_tela_cadastro_aluno()));
    connect(ui->actionNovo_Professor_2,SIGNAL(triggered()),this, SLOT(abrir_tela_cadastro_professor()));
    connect(ui->actionNovo_Exerc_cio,SIGNAL(triggered()),this, SLOT(abrir_tela_cadastro_exercicio()));
    connect(ui->actionNovo_Treino,SIGNAL(triggered()),this, SLOT(abrir_tela_cadastro_treino()));
    connect(ui->actionRemover_Aluno,SIGNAL(triggered()),this, SLOT(abrir_tela_remover_aluno()));

    ui->menuBar->setEnabled(false);
    dbm = new DbManager("fitnessUfba");    
    ui->tableView->setVisible(false);
    //carregarTableView();
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
    connect(addInstAluno, SIGNAL(recarrega()), this, SLOT( carregarTableView()));
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

void MainWindow::abrir_tela_remover_aluno()
{
    remInstAluno = new removeraluno();
    remInstAluno->setWindowTitle("Remoção de Aluno");
    remInstAluno->show();
    connect(remInstAluno, SIGNAL(recarrega()), this, SLOT( carregarTableView()));
}

void MainWindow::carregarTableView()
{
    model = new QSqlQueryModel(this);
    model->setQuery(dbm->listarAlunos(),dbm->m_db);
    proxyModel = new QSortFilterProxyModel(this);
    proxyModel->setSourceModel(model);
    proxyModel->setFilterCaseSensitivity(Qt::CaseInsensitive);
    ui->tableView->setModel(proxyModel);
    ui->tableView->show();
}

void MainWindow::logar()
{
    if (autenticado == false)
    {
        addInstlogin = new login();
        addInstlogin->setWindowTitle("Autenticar");
        addInstlogin->show();
        connect(addInstlogin, SIGNAL(autenticou(QString&)), this, SLOT(autenticar(QString&)));
    }
    else
    {
        desautenticar();
    }
}

void MainWindow::autenticar(QString &usuario)
{
    this->autenticado = true;
    ui->label_5->setText("Olá, " + usuario);
    ui->label_5->setStyleSheet("QLabel { background-color : white; color : blue; }");
    ui->pushButton->setText("Logout");
    ui->menuBar->setEnabled(true);
}

void MainWindow::desautenticar()
{
    this->autenticado = false;
    ui->label_5->setText("");
    ui->pushButton->setText("Login");
    ui->menuBar->setEnabled(false);
}




