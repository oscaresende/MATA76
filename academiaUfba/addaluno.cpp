#include "addaluno.h"
#include "ui_addaluno.h"
#include "dbmanager.h"


AddAluno::AddAluno(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddAluno)
{
    ui->setupUi(this);
    connect(ui->pushButton_2, SIGNAL(clicked()),this, SLOT(cadastrar()));
}

AddAluno::~AddAluno()
{
    delete ui;
}

void AddAluno::cadastrar()
{
    DbManager *manager = new DbManager("D:/banco de dados/fitnessUfba.db");
    manager->addAluno(ui->lineEdit->text());
}
