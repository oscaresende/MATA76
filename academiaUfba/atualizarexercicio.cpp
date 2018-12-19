#include "atualizarexercicio.h"
#include "ui_atualizarexercicio.h"

atualizarExercicio::atualizarExercicio(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::atualizarExercicio)
{
    ui->setupUi(this);
    dbm = new DbManager("fitnessUfba");

    connect(ui->buttonBox, SIGNAL(accepted()),this, SLOT(busca_exercicio_por_codigo()));
}

atualizarExercicio::~atualizarExercicio()
{
    delete ui;
}

void atualizarExercicio::busca_exercicio_por_codigo()
{
    exercicio Pesquisa = dbm->busca_exercicio(ui->lineEdit->text());

    if(Pesquisa.codigo!="")
    {
        addexercicio *tela2 = new addexercicio(NULL, &Pesquisa, "ATUALIZAR");
        tela2->setWindowTitle("Consultando Exercício");
        tela2->show();
    }
}
