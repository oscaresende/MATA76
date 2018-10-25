#ifndef DBMANAGER_H
#define DBMANAGER_H
#include "QString"
#include "QSqlDatabase"
#include "QSqlQuery"


class DbManager
{
public:
    DbManager(const QString& path);
    bool addAluno(const QString& name);
private:
    QSqlDatabase m_db;
};

#endif // DBMANAGER_H
