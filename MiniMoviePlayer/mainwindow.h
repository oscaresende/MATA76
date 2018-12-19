#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMovie>
#include <QVideoWidget>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QFileDialog>
#include <QMessageBox>

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
    void changeSliderNumber ();
    void play();
    void Pause();

signals:
    void pathChanged();
    void deuPlay();

private:
    Ui::MainWindow *ui;
    QMovie *moviePlayer;
    QMediaPlayer *mediaPlayer;
    QMediaPlaylist *playList;
    QMessageBox *msg;
};

#endif // MAINWINDOW_H
