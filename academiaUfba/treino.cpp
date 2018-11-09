#include "treino.h"
#include "QDateTime"

treino::treino()
{

}

treino::treino(const Aluno& aluno, const Professor& professor, const QDateTime& data_inicial,
               const QDateTime& data_final, bool& ativo, int& dias)
{
    treino::id=NULL;
    treino::aluno=aluno;
    treino::professor=professor;
    treino::data_inicial=data_inicial;
    treino::data_final=data_final;
    treino::ativo=ativo;
    treino::dias=dias;
}
