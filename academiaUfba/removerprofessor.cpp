#include "removerprofessor.h"
#include "ui_removerprofessor.h"

removerProfessor::removerProfessor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::removerProfessor)
{
    ui->setupUi(this);

    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(remove_professor()));

    dbm = new DbManager("fitnessUfba");

    model = new QSqlQueryModel(this);
    model->setQuery(dbm->listarProfessorEMatricula(),dbm->m_db);
    ui->comboBox->setModel(model);
    ui->comboBox->setModelColumn(0);
    ui->comboBox->show();
}

removerProfessor::~removerProfessor()
{
    delete ui;
}

void removerProfessor::remove_professor()
{
    QMessageBox mensagem;
    mensagem.setWindowTitle("Alerta");

    if (dbm->remover_professor(ui->comboBox->currentText()))
    {
        mensagem.setText("Professor removido com sucesso!");
        mensagem.exec();
    }

    else
    {
        mensagem.setText("Erro ao remover!");
        mensagem.exec();
    }
}
