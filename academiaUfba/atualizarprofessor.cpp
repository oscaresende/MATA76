#include "atualizarprofessor.h"
#include "ui_atualizarprofessor.h"

atualizarProfessor::atualizarProfessor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::atualizarProfessor)
{
    ui->setupUi(this);
    dbm = new DbManager("fitnessUfba");

    connect(ui->buttonBox, SIGNAL(accepted()),this, SLOT(busca_professor_por_matricula()));
}

atualizarProfessor::~atualizarProfessor()
{
    delete ui;
}

void atualizarProfessor::busca_professor_por_matricula()
{
    Professor Pesquisa = dbm->busca_professor(ui->lineEdit->text());

    if(Pesquisa.matricula!="")
    {
        addpro *tela2 = new addpro(NULL, &Pesquisa, "ATUALIZAR");
        tela2->setWindowTitle("Consultando Professor");
        tela2->show();
    }
}
