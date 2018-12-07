#ifndef TREINO_H
#define TREINO_H

#include "QDateTime"
#include "aluno.h"
#include "professor.h"


class treino
{
public:
    treino();
    treino(const Aluno& aluno, const Professor& professor, const QDateTime& data,int& dias);

    int id;
    Aluno aluno;
    Professor professor;
    QDateTime data;
    int dias;
    QList<QString> lista;

};

#endif // TREINO_H
