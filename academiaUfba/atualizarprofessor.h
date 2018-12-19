#ifndef ATUALIZARPROFESSOR_H
#define ATUALIZARPROFESSOR_H

#include <QDialog>
#include "addpro.h"
#include "dbmanager.h"

namespace Ui {
class atualizarProfessor;
}

class atualizarProfessor : public QDialog
{
    Q_OBJECT

public:
    explicit atualizarProfessor(QWidget *parent = nullptr);
    ~atualizarProfessor();

private slots:
    void busca_professor_por_matricula();

private:
    Ui::atualizarProfessor *ui;
    DbManager *dbm;
    addpro *addInstProfessor;
};

#endif // ATUALIZARPROFESSOR_H
