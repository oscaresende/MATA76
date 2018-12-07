#include "addtreino.h"
#include "ui_addtreino.h"

addTreino::addTreino(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addTreino)
{
    ui->setupUi(this);

    connect(ui->pushButton, SIGNAL(clicked()),this, SLOT(cadastrar()));
    connect(ui->pushButton_2, SIGNAL(clicked()),this, SLOT(cancelar()));
    connect(ui->pushButton_3, SIGNAL(clicked()),this, SLOT(adicionar_exercicio()));
    connect(ui->pushButton_4, SIGNAL(clicked()),this, SLOT(remover_exercicio()));

    db = new DbManager("fitnessUfba");
    db->limpar_tabela_temporaria();


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
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setShowGrid(true);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()
                                                   << trUtf8("ID")
                                                   << trUtf8("NOME")
                                                   << trUtf8("SÉRIE")
                                                   << trUtf8("REPETIÇÃO"));
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);

    QSqlQuery query(db->listarExercicios());
    QSqlRecord rec = query.record();
    int i = 0;

    while (query.next())
    {
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(query.value(rec.indexOf("ID_EXERCICIO")).toString()));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(query.value(rec.indexOf("NOME")).toString()));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem("3"));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem("12"));
        i++;
    }

    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->clearSelection();
}

void addTreino::carregarTableViewUsados()
{
    ui->tableWidget_2->clearContents();
    ui->tableWidget_2->setRowCount(0);
    ui->tableWidget_2->setColumnCount(4);
    ui->tableWidget_2->setShowGrid(true);
    ui->tableWidget_2->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget_2->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget_2->setHorizontalHeaderLabels(QStringList()
                                                   << trUtf8("ID")
                                                   << trUtf8("NOME")
                                                   << trUtf8("SÉRIE")
                                                   << trUtf8("REPETIÇÃO"));
    ui->tableWidget_2->horizontalHeader()->setStretchLastSection(true);

    QSqlQuery query(db->listarExercicios_temp());
    QSqlRecord rec = query.record();
    int i = 0;

    while (query.next())
    {
        ui->tableWidget_2->insertRow(i);
        ui->tableWidget_2->setItem(i,0,new QTableWidgetItem(query.value(rec.indexOf("ID_EXERCICIO")).toString()));
        ui->tableWidget_2->setItem(i,1,new QTableWidgetItem(query.value(rec.indexOf("NOME")).toString()));
        ui->tableWidget_2->setItem(i,2,new QTableWidgetItem(query.value(rec.indexOf("SERIE")).toString()));
        ui->tableWidget_2->setItem(i,3,new QTableWidgetItem(query.value(rec.indexOf("REPETICAO")).toString()));
        i++;
    }

    ui->tableWidget_2->resizeColumnsToContents();
    ui->tableWidget_2->clearSelection();
}

void addTreino::cadastrar()
{
    bool erro;
    erro = false;
    QMessageBox mensagem;
    mensagem.setWindowTitle("Alerta");

    if ((ui->comboBox->currentText() == "") || (ui->comboBox_2->currentText() == ""))
    {
        mensagem.setText("Dados Incompletos!");
        mensagem.exec();
        erro = true;
    }

    if (!erro)
    {
        /*treino *novo = new treino(ui->lineEdit_7->text(),ui->lineEdit_8->text(),ui->lineEdit->text(),ui->lineEdit_2->text(), ui->lineEdit_5->text(),
                                ui->dateEdit->dateTime(), ui->lineEdit_6->text(), ui->lineEdit_3->text(), this->imagePath);

        if(db->addProfessor(*novo))
        {
            mensagem.setText("Profesor cadastrado com sucesso!");
            mensagem.exec();
            this->close();
        }
        else
        {
            mensagem.setText("Inclusão não realizada.");
            mensagem.exec();
        }*/
    }
}

void addTreino::adicionar_exercicio()
{

    if (ui->tableWidget->selectedItems().isEmpty())
    {
        QMessageBox mensagem;
        mensagem.setWindowTitle("Alerta");
        mensagem.setText("Selecione um Exercício.");
        mensagem.exec();
    }
    else
    {
        if (db->addExercicio_temp(ui->tableWidget->selectedItems().value(0)->text().toInt(),
                                  ui->tableWidget->selectedItems().value(1)->text(),
                                  ui->tableWidget->selectedItems().value(2)->text(),
                                  ui->tableWidget->selectedItems().value(3)->text()))
        {
            qDebug() << "Inseriu";
        }

        carregarTableViewDisponiveis();
        carregarTableViewUsados();
    }
}

void addTreino::remover_exercicio()
{

    if (ui->tableWidget_2->selectedItems().isEmpty())
    {
        QMessageBox mensagem;
        mensagem.setWindowTitle("Alerta");
        mensagem.setText("Selecione um Exercício.");
        mensagem.exec();
    }
    else
    {
        if (db->remExercicio_temp(ui->tableWidget_2->selectedItems().value(0)->text().toInt()))
        {
            qDebug() << "Removeu";
        }

        carregarTableViewDisponiveis();
        carregarTableViewUsados();
    }

}
