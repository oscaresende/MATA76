#ifndef TREINO_H
#define TREINO_H

#include "QDateTime"
#include "aluno.h"
#include "professor.h"


class treino
{
public:
    treino();
    treino(const Aluno& aluno, const Professor& professor, const QDateTime& data_inicial,
           const QDateTime& data_final, bool& ativo, int& dias);

    int id;
    Aluno aluno;
    Professor professor;
    QDateTime data_inicial;
    QDateTime data_final;
    bool ativo;
    int dias;

};

#endif // TREINO_H
