#include "dbmanager.h"
#include "QDebug"


DbManager::DbManager(const QString& path)
{
   m_db = QSqlDatabase::addDatabase("QSQLITE");
   m_db.setDatabaseName(path);

   if (!m_db.open())
   {
      qDebug() << "Error: connection with database fail";
   }
   else
   {
      qDebug() << "Database: connection ok";
   }
}

bool DbManager::addAluno(const QString& name)
{
   bool success = false;
   // you should check if args are ok first...
   QSqlQuery query;

   query.exec("CREATE TABLE IF NOT EXISTS Aluno(nome VARCHAR(100))");
   query.clear();

   query.prepare("INSERT INTO Aluno(nome) VALUES (:nome)");
   query.bindValue(":nome", name);
   if(query.exec())
   {
       success = true;
       qDebug() << "deu certo";
   }
   else
   {
        qDebug() << "deu errado";
                 //<< query.lastError();
   }

   return success;
}
