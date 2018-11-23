#include "removeraluno.h"
#include "ui_removeraluno.h"

removeraluno::removeraluno(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::removeraluno)
{
    ui->setupUi(this);

    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(remove_aluno()));

    dbm = new DbManager("fitnessUfba");

    model = new QSqlQueryModel(this);
    model->setQuery(dbm->listarAlunoEMatricula(),dbm->m_db);
    ui->comboBox->setModel(model);
    ui->comboBox->setModelColumn(0);
    ui->comboBox->show();
}

removeraluno::~removeraluno()
{
    delete ui;
}

void removeraluno::remove_aluno()
{
    QMessageBox mensagem;
    mensagem.setWindowTitle("Alerta");

    if (dbm->remover_aluno(ui->comboBox->currentText()))
    {
        mensagem.setText("Aluno removido com sucesso!");
        mensagem.exec();
        emit recarrega();
    }

    else
    {
        mensagem.setText("Erro ao remover!");
        mensagem.exec();
    }
}
