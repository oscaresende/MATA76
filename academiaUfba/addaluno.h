#ifndef ADDALUNO_H
#define ADDALUNO_H

#include <QWidget>
#include "aluno.h"
#include "dbmanager.h"

namespace Ui {
class AddAluno;
}

class AddAluno : public QWidget
{
    Q_OBJECT

public:
    explicit AddAluno(QWidget *parent = nullptr, Aluno *aluno = nullptr);
    ~AddAluno();
private slots:
    void cadastrar();
    void cancelar();
    void escolher_arquivo();

private:
    Ui::AddAluno *ui;        
    QImage imageFile;
    DbManager *db;

};

#endif // ADDALUNO_H
