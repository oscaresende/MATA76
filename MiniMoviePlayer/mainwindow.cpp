#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    moviePlayer = new QMovie();
    moviePathPast = "";

    msg = new QMessageBox();
    msg->setText("Novo .gif carregado com sucesso!");

    connect(ui->open_pushButton, SIGNAL(clicked(bool)), this, SLOT(openMovie()));
    connect(ui->play_pushButton, SIGNAL(clicked(bool)), this, SLOT(Play()));
    connect(ui->pause_pushButton, SIGNAL(clicked(bool)), this, SLOT(Pause()));
    connect(moviePlayer, SIGNAL(frameChanged(int)), this, SLOT(changeSliderNumber()));
    connect(this, SIGNAL(pathChanged()), msg, SLOT(exec()));
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
        emit pathChanged();
    }

    moviePlayer->stop();
    ui->movie_label->setMovie(moviePlayer);
    moviePlayer->setFileName(moviePath);
    moviePlayer->start();
}

void MainWindow::changeSliderNumber()
{
    ui->frameSlider->setMaximum(moviePlayer->frameCount() - 1);
    ui->frameSlider->setValue(moviePlayer->currentFrameNumber());
}

void MainWindow::play()
{
    if (moviePlayer->Paused)
    {
        moviePlayer->jumpToFrame(ui->frameSlider->value());
        moviePlayer->start();
    }
}

void MainWindow::Pause()
{
    if (moviePlayer->Running)
    {
        moviePlayer->setPaused(true);
    }
}
