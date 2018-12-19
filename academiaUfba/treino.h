#ifndef TREINO_H
#define TREINO_H

#include "QDateTime"
#include "aluno.h"
#include "professor.h"
#include "exercicio.h"



class treino
{
public:
    treino();
    treino(const Aluno& aluno, const Professor& professor, const QDateTime& data,int& dias, const QList<exercicio>&& exercicios);

    int id;
    Aluno aluno;
    Professor professor;
    QDateTime data;
    int dias;
    QList<exercicio> exercicios;
};

#endif // TREINO_H
