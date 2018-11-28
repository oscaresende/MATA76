#include "addtreino.h"
#include "ui_addtreino.h"

addTreino::addTreino(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addTreino)
{
    ui->setupUi(this);

    connect(ui->pushButton_2, SIGNAL(clicked()),this, SLOT(cancelar()));

    connect(ui->pushButton_3, SIGNAL(clicked()),this, SLOT(adicionar_exercicio()));
    connect(ui->pushButton_4, SIGNAL(clicked()),this, SLOT(remover_exercicio()));

    db = new DbManager("fitnessUfba");

    model = new QSqlQueryModel(this);
    model->setQuery(db->listarAlunoEMatricula(),db->m_db);
    ui->comboBox->setModel(model);
    ui->comboBox->setModelColumn(1);
    ui->comboBox->show();


    model2 = new QSqlQueryModel(this);
    model2->setQuery(db->listarProfessorEMatricula(),db->m_db);
    ui->comboBox_2->setModel(model2);
    ui->comboBox_2->setModelColumn(1);
    ui->comboBox_2->show();

    carregarTableViewDisponiveis();
    carregarTableViewUsados();

}

addTreino::~addTreino()
{
    delete ui;
}

void addTreino::cancelar()
{    
    this->close();
}

void addTreino::carregarTableViewDisponiveis()
{
    model3 = new QSqlQueryModel(this);
    model3->setQuery(db->listarExercicios(),db->m_db);
    proxyModel = new QSortFilterProxyModel(this);
    proxyModel->setSourceModel(model3);
    proxyModel->setFilterCaseSensitivity(Qt::CaseInsensitive);
    ui->tableView->setModel(proxyModel);
    ui->tableView->show();
}

void addTreino::carregarTableViewUsados()
{
    model4 = new QSqlQueryModel(this);
    model4->setQuery(db->listarExercicios_temp(),db->m_db);
    proxyModel2 = new QSortFilterProxyModel(this);
    proxyModel2->setSourceModel(model4);
    proxyModel2->setFilterCaseSensitivity(Qt::CaseInsensitive);
    ui->tableView_2->setModel(proxyModel2);
    ui->tableView_2->show();
}

void addTreino::adicionar_exercicio()
{


}

void addTreino::remover_exercicio()
{

}
