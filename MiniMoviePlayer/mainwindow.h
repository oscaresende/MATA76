#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMovie>
#include <QVideoWidget>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QString moviePathPast;

public slots:
    void openMovie();
    void changeSliderNumber();
    void Play();
    void Pause();
    void setarPaused();
    void setarPlayed();

signals:
    void pathChanged();
    void deu_play();
    void deu_pause();
    void pausou_de_novo();

private:
    Ui::MainWindow *ui;
    QMovie *moviePlayer;
    QMediaPlayer *mediaPlayer;
    QMediaPlaylist *playList;
    QMessageBox *msg;
    bool paused;
    int frameAtual;
};

#endif // MAINWINDOW_H
