#ifndef ADDEXERCICIO_H
#define ADDEXERCICIO_H

#include <QWidget>
#include "exercicio.h"
#include "dbmanager.h"
#include <QMovie>
#include <QVideoWidget>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QFileDialog>
#include <QMessageBox>

namespace Ui {
class addexercicio;
}

class addexercicio : public QWidget
{
    Q_OBJECT

public:
    explicit addexercicio(QWidget *parent = nullptr, exercicio *exercicio = nullptr, const QString& operacao = "");
    ~addexercicio();
private slots:
    void cadastrar();
    void cancelar();
    void openMovie();
    void changeSliderNumber ();
    void play();
    void pause();

signals:
    void pathChanged();

private:
    Ui::addexercicio *ui;    
    QString imagePath;
    DbManager *db;
    QMovie *moviePlayer;
    QMediaPlayer *mediaPlayer;
    QMediaPlaylist *playList;
    QMessageBox *msg;
    QString op;
};

#endif // ADDEXERCICIO_H
