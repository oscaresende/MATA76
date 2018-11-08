#include "addprofessor.h"
#include "ui_addprofessor.h"
#include "dbmanager.h"
#include "professor.h"
#include "QMessageBox"
#include "QFileDialog"


AddProfessor::AddProfessor(QWidget *parent, Professor *professor) :
    QWidget(parent),
    ui(new Ui::AddProfessor)
{
    ui->setupUi(this);

    db = new DbManager("fitnessUfba");

    connect(ui->pushButton_2, SIGNAL(clicked()),this, SLOT(cadastrar()));
    connect(ui->pushButton, SIGNAL(clicked()),this, SLOT(cancelar()));
    connect(ui->toolButton, SIGNAL(clicked()),this, SLOT(escolher_arquivo()));
    connect(ui->toolButton, SIGNAL(clicked()),this, SLOT(escolher_arquivo()));




    if (professor != NULL)
    {
        ui->lineEdit_7->setText(professor->matricula);
        ui->lineEdit->setText(professor->nome);
        ui->lineEdit_2->setText(professor->endereco);
        ui->lineEdit_3->setText(professor->telefone);
        ui->lineEdit_5->setText(professor->email);
        ui->lineEdit_6->setText(professor->cpf);
        ui->dateEdit->setDateTime(professor->data_nascimento);
        ui->pushButton_2->setEnabled(false);

        imageFile.loadFromData(professor->imagem, "JPEG");
        ui->image_label->setPixmap(QPixmap::fromImage(imageFile).scaled(ui->image_label->width(),
                                                                        ui->image_label->height(),
                                                                        Qt::KeepAspectRatioByExpanding));
    }
}

AddProfessor::~AddProfessor()
{
    delete ui;
}

void AddProfessor::cadastrar()
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

        QByteArray compressed = qCompress(imageFile.bits(), imageFile.byteCount());

        Aluno *novo = new Aluno(ui->lineEdit_7->text(),ui->lineEdit->text(),ui->lineEdit_2->text(), ui->lineEdit_5->text(),
                                ui->dateEdit->dateTime(), ui->lineEdit_6->text(), ui->lineEdit_3->text(), compressed);

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

void AddProfessor::escolher_arquivo()
{
    QString imagePath = QFileDialog::getOpenFileName(this, "Open", "/home",
                                                     "*.png *.jpg *.jpeg");
    if (imagePath!= "") imageFile.load(imagePath);
    ui->image_label->setPixmap(QPixmap::fromImage(imageFile).scaled(ui->image_label->width(),
                                                                    ui->image_label->height(),
                                                                    Qt::KeepAspectRatioByExpanding));
}

void AddProfessor::cancelar()
{
    this->close();
}
