#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    db = new DbManager("fitnessUfba");

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(autenticar()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(cancelar()));
}

login::~login()
{
    delete ui;
}

void login::autenticar()
{
    QMessageBox mensagem;
    mensagem.setWindowTitle("Alerta");

    if (ui->lineEdit_2->text() == "admin")
    {
        if (ui->lineEdit->text() == "admin")
        {
            mensagem.setText("Autenticado");
            mensagem.exec();
            usuario = "admin";
            emit autenticou(usuario);
            this->close();
        }
        else
        {
            mensagem.setText("Senha incorreta.");
            mensagem.exec();
        }

    }
    else
    {
        Professor Pesquisa = db->busca_professor(ui->lineEdit_2->text());

        if(Pesquisa.matricula != "")
        {
            if (ui->lineEdit->text() == Pesquisa.senha)
            {
                mensagem.setText("Autenticado");
                mensagem.exec();
                usuario = Pesquisa.nome;
                emit autenticou(usuario);
                this->close();
            }
            else
            {
                mensagem.setText("Senha incorreta.");
                mensagem.exec();
            }
        }
        else
        {
            mensagem.setText("Dados Incorretos.");
            mensagem.exec();
        }
    }

}

void login::cancelar()
{
    this->close();
}
