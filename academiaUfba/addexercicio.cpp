#include "addexercicio.h"
#include "ui_addexercicio.h"
#include "exercicio.h"
#include "dbmanager.h"
#include "QMessageBox"
#include "QFileDialog"

addexercicio::addexercicio(QWidget *parent, exercicio *exercicio) :
    QWidget(parent),
    ui(new Ui::addexercicio)
{
    ui->setupUi(this);
    db = new DbManager("fitnessUfba");

    connect(ui->pushButton_2, SIGNAL(clicked()),this, SLOT(cadastrar()));
    connect(ui->pushButton, SIGNAL(clicked()),this, SLOT(cancelar()));
    connect(ui->toolButton, SIGNAL(clicked()),this, SLOT(escolher_arquivo()));

    if (exercicio != NULL)
    {
        ui->lineEdit_7->setText(exercicio->codigo);
        ui->lineEdit->setText(exercicio->nome);
        ui->lineEdit_2->setText(exercicio->descricao);
        ui->pushButton_2->setEnabled(false);

        imageFile.load(exercicio->imagem);
        ui->image_label->setPixmap(QPixmap::fromImage(imageFile).scaled(ui->image_label->width(),
                                                                        ui->image_label->height(),
                                                                        Qt::KeepAspectRatioByExpanding));
    }
}

addexercicio::~addexercicio()
{
    delete ui;
}

void addexercicio::cadastrar()
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
        exercicio *novo = new exercicio(ui->lineEdit_7->text(),ui->lineEdit->text(),ui->lineEdit_2->text(),this->imagePath);

        if(db->addExercicio(*novo))
        {
            mensagem.setText("Exercício cadastrado com sucesso!");
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

void addexercicio::escolher_arquivo()
{
    this->imagePath = QFileDialog::getOpenFileName(this, "Open", "/home",
                                                     "*.png *.jpg *.jpeg");
    if (this->imagePath!= "") imageFile.load(this->imagePath);
    ui->image_label->setPixmap(QPixmap::fromImage(imageFile).scaled(ui->image_label->width(),
                                                                    ui->image_label->height(),
                                                                    Qt::KeepAspectRatioByExpanding));
}

void addexercicio::cancelar()
{
    this->close();
}


