#ifndef ADDEXERCICIO_H
#define ADDEXERCICIO_H

#include <QWidget>
#include "exercicio.h"
#include "dbmanager.h"

namespace Ui {
class addexercicio;
}

class addexercicio : public QWidget
{
    Q_OBJECT

public:
    explicit addexercicio(QWidget *parent = nullptr, exercicio *exercicio = nullptr);
    ~addexercicio();
private slots:
    void cadastrar();
    void cancelar();
    void escolher_arquivo();

private:
    Ui::addexercicio *ui;
    QImage imageFile;
    QString imagePath;
    DbManager *db;
};

#endif // ADDEXERCICIO_H
