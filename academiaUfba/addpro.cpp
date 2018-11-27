#include "addpro.h"
#include "ui_addpro.h"
#include "dbmanager.h"
#include "professor.h"
#include "QMessageBox"
#include "QFileDialog"

addpro::addpro(QWidget *parent, Professor *professor) :
    QWidget(parent),
    ui(new Ui::addpro)
{
    ui->setupUi(this);
    ui->setupUi(this);

        db = new DbManager("fitnessUfba");

        connect(ui->pushButton_2, SIGNAL(clicked()),this, SLOT(cadastrar()));
        connect(ui->pushButton, SIGNAL(clicked()),this, SLOT(cancelar()));
        connect(ui->toolButton, SIGNAL(clicked()),this, SLOT(escolher_arquivo()));        




        if (professor != NULL)
        {
            ui->lineEdit_7->setText(professor->matricula);
            ui->lineEdit_8->setText(professor->senha);
            ui->lineEdit->setText(professor->nome);
            ui->lineEdit_2->setText(professor->endereco);
            ui->lineEdit_3->setText(professor->telefone);
            ui->lineEdit_5->setText(professor->email);
            ui->lineEdit_6->setText(professor->cpf);
            ui->dateEdit->setDateTime(professor->data_nascimento);
            ui->pushButton_2->setEnabled(false);

            imageFile.load(professor->imagem);
            ui->image_label->setPixmap(QPixmap::fromImage(imageFile).scaled(ui->image_label->width(),
                                                                            ui->image_label->height(),
                                                                            Qt::KeepAspectRatioByExpanding));
        }
}

addpro::~addpro()
{
    delete ui;
}

void addpro::cadastrar()
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
        DbManager *manager = new DbManager("fitnessUfba");

        Professor *novo = new Professor(ui->lineEdit_7->text(),ui->lineEdit_8->text(),ui->lineEdit->text(),ui->lineEdit_2->text(), ui->lineEdit_5->text(),
                                ui->dateEdit->dateTime(), ui->lineEdit_6->text(), ui->lineEdit_3->text(), this->imagePath);

        if(manager->addProfessor(*novo))
        {
            mensagem.setText("Profesor cadastrado com sucesso!");
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

void addpro::escolher_arquivo()
{
    this->imagePath = QFileDialog::getOpenFileName(this, "Open", "/home",
                                                     "*.png *.jpg *.jpeg");
    if (this->imagePath!= "") imageFile.load(this->imagePath);
    ui->image_label->setPixmap(QPixmap::fromImage(imageFile).scaled(ui->image_label->width(),
                                                                    ui->image_label->height(),
                                                                    Qt::KeepAspectRatioByExpanding));
}

void addpro::cancelar()
{
    this->close();
}
