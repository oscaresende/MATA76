#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    moviePlayer = new QMovie();
    moviePathPast = "";
    frameAtual = 0;
    paused = true;

    msg = new QMessageBox();    

    connect(ui->open_pushButton, SIGNAL(clicked(bool)), this, SLOT(openMovie()));
    connect(ui->play_pushButton, SIGNAL(clicked(bool)), this, SLOT(Play()));
    connect(ui->pause_pushButton, SIGNAL(clicked(bool)), this, SLOT(Pause()));
    connect(moviePlayer, SIGNAL(frameChanged(int)), this, SLOT(changeSliderNumber()));
    connect(this, SIGNAL(pathChanged()), msg, SLOT(exec()));
    connect(this, SIGNAL(deu_play()), this, SLOT(setarPlayed()));
    connect(this, SIGNAL(deu_pause()), this, SLOT(setarPaused()));
    connect(this, SIGNAL(pausou_de_novo()), msg, SLOT(exec()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openMovie()
{
    QString moviePath = QFileDialog::getOpenFileName(this, tr("Open a Movie"),
                                                     "/home");
    if (moviePath != moviePathPast)
    {
        moviePathPast = moviePath;
        msg->setText("Novo .gif carregado com sucesso!");
        emit pathChanged();
    }

    moviePlayer->stop();
    ui->movie_label->setMovie(moviePlayer);
    moviePlayer->setFileName(moviePath);
    //moviePlayer->start();
}

void MainWindow::changeSliderNumber()
{
    ui->frameSlider->setMaximum(moviePlayer->frameCount() - 1);
    ui->frameSlider->setValue(moviePlayer->currentFrameNumber());
    frameAtual = moviePlayer->currentFrameNumber();
}

void MainWindow::Play()
{
    moviePlayer->jumpToFrame(frameAtual);
    moviePlayer->setPaused(false);
    emit deu_play();
}

void MainWindow::Pause()
{

    if (!paused)
    {
        moviePlayer->setPaused(true);
        frameAtual = moviePlayer->currentFrameNumber();
        emit deu_pause();
    }
    else
    {
       msg->setText("O gif já está pausado.");
       emit pausou_de_novo();
    }
}

void MainWindow::setarPlayed()
{
    paused = false;
    qDebug() << "Frame Atual:" << frameAtual;
}

void MainWindow::setarPaused()
{
    paused = true;
    qDebug() << "Frame Atual:" << frameAtual;
}
