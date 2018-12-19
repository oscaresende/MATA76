#include "removerexercicio.h"
#include "ui_removerexercicio.h"

removerExercicio::removerExercicio(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::removerExercicio)
{
    ui->setupUi(this);

    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(remove_exercicio()));

    dbm = new DbManager("fitnessUfba");

    model = new QSqlQueryModel(this);
    model->setQuery(dbm->listarExercicioECodigo(),dbm->m_db);
    ui->comboBox->setModel(model);
    ui->comboBox->setModelColumn(0);
    ui->comboBox->show();
}

removerExercicio::~removerExercicio()
{
    delete ui;
}

void removerExercicio::remove_exercicio()
{
    QMessageBox mensagem;
    mensagem.setWindowTitle("Alerta");

    if (dbm->remover_exercicio(ui->comboBox->currentText()))
    {
        mensagem.setText("Exercício removido com sucesso!");
        mensagem.exec();
    }

    else
    {
        mensagem.setText("Erro ao remover!");
        mensagem.exec();
    }
}
