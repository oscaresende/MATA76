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
    moviePlayer = new QMovie();
    imagePath = "";

    connect(ui->pushButton_2, SIGNAL(clicked()),this, SLOT(cadastrar()));
    connect(ui->pushButton, SIGNAL(clicked()),this, SLOT(cancelar()));    
    connect(ui->open_pushButton, SIGNAL(clicked(bool)), this, SLOT(openMovie()));
    connect(ui->play_pushButton, SIGNAL(clicked(bool)), this, SLOT(play()));
    connect(ui->pause_pushButton, SIGNAL(clicked(bool)), this, SLOT(pause()));
    connect(moviePlayer, SIGNAL(frameChanged(int)), this, SLOT(changeSliderNumber()));
    connect(this, SIGNAL(pathChanged()), msg, SLOT(exec()));

    if (exercicio != NULL)
    {
        ui->lineEdit_7->setText(exercicio->codigo);
        ui->lineEdit->setText(exercicio->nome);
        ui->lineEdit_2->setText(exercicio->descricao);
        ui->pushButton_2->setEnabled(false);
        imagePath = exercicio->imagem;

        if (imagePath != "")
        {
            moviePlayer->stop();
            ui->movie_label->setMovie(moviePlayer);
            moviePlayer->setFileName(imagePath);
            moviePlayer->start();
        }
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

void addexercicio::openMovie()
{
    QString moviePath = QFileDialog::getOpenFileName(this, tr("Open a Movie"),
                                                     "/gifs/");
    if (moviePath != imagePath)
    {
        imagePath = moviePath;
        emit pathChanged();
    }

    moviePlayer->stop();
    ui->movie_label->setMovie(moviePlayer);
    moviePlayer->setFileName(moviePath);
    moviePlayer->start();
}

void addexercicio::changeSliderNumber()
{
    ui->frameSlider->setMaximum(moviePlayer->frameCount() - 1);
    ui->frameSlider->setValue(moviePlayer->currentFrameNumber());
}

void addexercicio::play()
{
    moviePlayer->setPaused(false);
}

void addexercicio::pause()
{
    moviePlayer->setPaused(true);
}

void addexercicio::cancelar()
{
    this->close();
}




