#ifndef ATUALIZARALUNO_H
#define ATUALIZARALUNO_H

#include <QDialog>
#include "addaluno.h"
#include "dbmanager.h"

namespace Ui {
class atualizarAluno;
}

class atualizarAluno : public QDialog
{
    Q_OBJECT

public:
    explicit atualizarAluno(QWidget *parent = nullptr);
    ~atualizarAluno();

private slots:
    void busca_aluno_por_matricula();

private:
    Ui::atualizarAluno *ui;
    DbManager *dbm;
    AddAluno *addInstAluno;
};

#endif // ATUALIZARALUNO_H
