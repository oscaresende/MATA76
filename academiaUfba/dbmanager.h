#ifndef DBMANAGER_H
#define DBMANAGER_H
#include "QString"
#include "QDateTime"
#include "QSqlDatabase"
#include "QSqlQuery"
#include "aluno.h"
#include "professor.h"
#include "exercicio.h"
#include "treino.h"


class DbManager
{
public:
    DbManager(const QString& path);

    void VerificarTabelas();
    void CarregarDados();

    bool addAluno(const Aluno& aluno);
    bool atualizarAluno(const Aluno& aluno);
    Aluno busca_aluno(const QString& matricula);
    QString listarAlunos();
    QString listarAlunoEMatricula();
    bool remover_aluno(const QString& matricula);

    bool addProfessor(const Professor& professor);
    bool atualizarProfessor(const Professor& professor);
    Professor busca_professor(const QString& matricula);
    QString listarProfessores();
    QString listarProfessorEMatricula();
    bool remover_professor(const QString& matricula);

    bool addExercicio(const exercicio& exercicio);
    bool atualizarExercicio(const exercicio& exercicio);
    bool remover_exercicio(const QString& codigo);
    QString listarExercicioECodigo();
    bool addExercicio_temp(const int& id, const QString& nome, const QString& serie, const QString& repeticao);
    bool remExercicio_temp(const int& id);
    exercicio busca_exercicio(const QString& codigo);
    QString listarExercicios();
    QString listarExercicios_temp();
    void limpar_tabela_temporaria();

    bool addTreino(const treino& treino);

    QSqlDatabase m_db;
private:

};

#endif // DBMANAGER_H
