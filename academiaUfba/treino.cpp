#include "treino.h"
#include "QDateTime"

treino::treino()
{

}

treino::treino(const Aluno& aluno, const Professor& professor, const QDateTime& data, int& dias)
{
    treino::id = NULL;
    treino::aluno = aluno;
    treino::professor = professor;
    treino::data = data;
    treino::dias = dias;
}
