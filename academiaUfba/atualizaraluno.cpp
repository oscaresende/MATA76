#include "atualizaraluno.h"
#include "ui_atualizaraluno.h"

atualizarAluno::atualizarAluno(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::atualizarAluno)
{
    ui->setupUi(this);
    dbm = new DbManager("fitnessUfba");

    connect(ui->buttonBox, SIGNAL(accepted()),this, SLOT(busca_aluno_por_matricula()));
}

atualizarAluno::~atualizarAluno()
{
    delete ui;
}


void atualizarAluno::busca_aluno_por_matricula()
{
    Aluno Pesquisa = dbm->busca_aluno(ui->lineEdit->text());

    if(Pesquisa.matricula!="")
    {
        AddAluno *tela2 = new AddAluno(NULL, &Pesquisa, "ATUALIZAR");
        tela2->setWindowTitle("Consultando aluno");
        tela2->show();
    }
}
