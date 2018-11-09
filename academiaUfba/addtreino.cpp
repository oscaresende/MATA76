#include "addtreino.h"
#include "ui_addtreino.h"

addTreino::addTreino(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addTreino)
{
    ui->setupUi(this);

    connect(ui->pushButton_2, SIGNAL(clicked()),this, SLOT(cancelar()));

    DbManager *dbm = new DbManager("fitnessUfba");

    model = new QSqlQueryModel(this);
    model->setQuery(dbm->listarAlunoEMatricula(),dbm->m_db);
    //proxyModel = new QSortFilterProxyModel(this);
    //roxyModel->setSourceModel(model);
    //proxyModel->setFilterCaseSensitivity(Qt::CaseInsensitive);
    ui->comboBox->setModel(model);
    ui->comboBox->setModelColumn(1);
    ui->comboBox->show();


    model2 = new QSqlQueryModel(this);
    model2->setQuery(dbm->listarProfessorEMatricula(),dbm->m_db);
    //proxyModel = new QSortFilterProxyModel(this);
    //roxyModel->setSourceModel(model);
    //proxyModel->setFilterCaseSensitivity(Qt::CaseInsensitive);
    ui->comboBox_2->setModel(model2);
    ui->comboBox_2->setModelColumn(1);
    ui->comboBox_2->show();
}

addTreino::~addTreino()
{
    delete ui;
}

void addTreino::cancelar()
{
    this->close();
}
