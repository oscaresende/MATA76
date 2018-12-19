#ifndef ATUALIZAREXERCICIO_H
#define ATUALIZAREXERCICIO_H

#include <QDialog>
#include "addexercicio.h"
#include "dbmanager.h"

namespace Ui {
class atualizarExercicio;
}

class atualizarExercicio : public QDialog
{
    Q_OBJECT

public:
    explicit atualizarExercicio(QWidget *parent = nullptr);
    ~atualizarExercicio();

private slots:
    void busca_exercicio_por_codigo();

private:
    Ui::atualizarExercicio *ui;
    DbManager *dbm;
    addexercicio *addInstExercicio;
};

#endif // ATUALIZAREXERCICIO_H
