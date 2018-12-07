#ifndef ITEMTREINO_H
#define ITEMTREINO_H

#include "treino.h"
#include "aluno.h"
#include "exercicio.h"

class itemTreino
{
public:
    itemTreino();
    itemTreino(const treino& Treino, const exercicio& Exercicio, const QString &serie, const QString &repeticao);

    treino treino;
    exercicio exercicio;
    QString serie;
    QString repeticao;
};


#endif // ITEMTREINO_H
