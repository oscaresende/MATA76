#include "exercicio.h"

exercicio::exercicio()
{

}

exercicio::exercicio(const QString& codigo, const QString& nome, const QString& descricao, const QString & imagem)
{
    exercicio::id=NULL;
    exercicio::codigo=codigo;
    exercicio::nome=nome;
    exercicio::descricao=descricao;
    exercicio::imagem=imagem;
}
