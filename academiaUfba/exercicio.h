#ifndef EXERCICIO_H
#define EXERCICIO_H

#include "QString"

class exercicio
{
public:
    exercicio();
    exercicio(const QString& codigo, const QString& nome, const QString& descricao, const QString & imagem);
    int id;
    QString codigo;
    QString nome;
    QString descricao;
    QString imagem;
};

#endif // EXERCICIO_H
