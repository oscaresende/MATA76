#ifndef ADDALUNO_H
#define ADDALUNO_H

#include <QWidget>
#include "aluno.h"

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

private:
    Ui::AddAluno *ui;        
};

#endif // ADDALUNO_H
