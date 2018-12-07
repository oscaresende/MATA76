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
    //model3 = new QSqlQueryModel(this);
    //model3->setQuery(db->listarExercicios(),db->m_db);
    //proxyModel = new QSortFilterProxyModel(this);
    //proxyModel->setSourceModel(model3);
    //proxyModel->setFilterCaseSensitivity(Qt::CaseInsensitive);
    //ui->tableView->setModel(proxyModel);
    //ui->tableView->show();

    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setShowGrid(true);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()
                                                   << trUtf8("ID")
                                                   << trUtf8("NOME"));
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);


    QSqlQuery query(db->listarExercicios());
    QSqlRecord rec = query.record();

    int i = 0;

    while (query.next())
    {
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(query.value(rec.indexOf("ID_EXERCICIO")).toString()));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(query.value(rec.indexOf("NOME")).toString()));
        i++;
    }
    ui->tableWidget->resizeColumnsToContents();
    //ui->tableWidget->hideColumn(0);
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

    qDebug() << ui->tableWidget->selectedItems().value(0)->text()
             << ui->tableWidget->selectedItems().value(1)->text();

}

void addTreino::remover_exercicio()
{

}
