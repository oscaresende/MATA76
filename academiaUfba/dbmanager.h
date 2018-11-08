#ifndef DBMANAGER_H
#define DBMANAGER_H
#include "QString"
#include "QDateTime"
#include "QSqlDatabase"
#include "QSqlQuery"

#include "aluno.h"
#include "professor.h"


class DbManager
{
public:
    DbManager(const QString& path);
    bool addAluno(const Aluno& aluno);
    Aluno busca_aluno(const QString& matricula);
    QString listarAlunos();

    bool addProfessor(const Professor& professor);
    Professor busca_professor(const QString& matricula);
    QString listarProfessores();

    QSqlDatabase m_db;
private:

};

#endif // DBMANAGER_H
