#include "addaluno.h"
#include "ui_addaluno.h"
#include "dbmanager.h"
#include "aluno.h"
#include "QMessageBox"


AddAluno::AddAluno(QWidget *parent, Aluno *aluno) :
    QWidget(parent),
    ui(new Ui::AddAluno)
{
    ui->setupUi(this);
    connect(ui->pushButton_2, SIGNAL(clicked()),this, SLOT(cadastrar()));
    connect(ui->pushButton, SIGNAL(clicked()),this, SLOT(cancelar()));

    if (aluno != NULL)
    {
        ui->lineEdit_7->setText(aluno->matricula);
        ui->lineEdit->setText(aluno->nome);
        ui->lineEdit_2->setText(aluno->endereco);
        ui->lineEdit_3->setText(aluno->telefone);
        ui->lineEdit_5->setText(aluno->email);
        ui->lineEdit_6->setText(aluno->cpf);
        ui->dateEdit->setDateTime(aluno->data_nascimento);
        ui->pushButton_2->setEnabled(false);
    }
}

AddAluno::~AddAluno()
{
    delete ui;
}

void AddAluno::cadastrar()
{
    bool erro;
    erro = false;
    QMessageBox mensagem;
    mensagem.setWindowTitle("Alerta");

    if ((ui->lineEdit_7->text() == "") ||(ui->lineEdit->text() == ""))
    {
        mensagem.setText("Dados Incompletos!");
        mensagem.exec();
        erro = true;
    }

    if (!erro)
    {
        DbManager *manager = new DbManager("D:/banco de dados/fitnessUfba.db");

        Aluno *novo = new Aluno(ui->lineEdit_7->text(),ui->lineEdit->text(),ui->lineEdit_2->text(), ui->lineEdit_5->text(),
                                ui->dateEdit->dateTime(), ui->lineEdit_6->text(), ui->lineEdit_3->text());

        if(manager->addAluno(*novo))
        {
            mensagem.setText("Aluno cadastrado com sucesso!");
            mensagem.exec();
            this->close();
        }
        else
        {
            mensagem.setText("Inclusão não realizada.");
            mensagem.exec();
        }
    }
}

void AddAluno::cancelar()
{
    this->close();
}

