#include "dbmanager.h"
#include "QDebug"
#include "QSqlRecord"

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

QString DbManager::listarAlunos()
{
   QString retorno = "SELECT MATRICULA, NOME, ENDERECO, EMAIL, TELEFONE FROM ALUNO";
   return retorno;
}

QString DbManager::listarAlunoEMatricula()
{
   QString retorno = "SELECT ID_ALUNO, NOME FROM ALUNO";
   return retorno;
}

QString DbManager::listarProfessores()
{
   QString retorno = "SELECT MATRICULA, NOME, ENDERECO, EMAIL, TELEFONE FROM PROFESSOR";
   return retorno;
}

QString DbManager::listarProfessorEMatricula()
{
   QString retorno = "SELECT ID_PROFESSOR, NOME FROM PROFESSOR";
   return retorno;
}

QString DbManager::listarExercicios()
{
   QString retorno = "SELECT CODIGO, NOME, DESCRICAO FROM EXERCICIO";
   return retorno;
}


Aluno DbManager::busca_aluno(const QString& matricula)
{
   QString consulta = "SELECT * FROM ALUNO WHERE MATRICULA = '" + matricula + "'";
   QSqlQuery query(consulta);
   QSqlRecord rec = query.record();

   Aluno *aluno;

   while (query.next())
   {
         aluno = new Aluno(query.value(rec.indexOf("MATRICULA")).toString(),
                           query.value(rec.indexOf("NOME")).toString(),
                           query.value(rec.indexOf("ENDERECO")).toString(),
                           query.value(rec.indexOf("EMAIL")).toString(),
                           query.value(rec.indexOf("DATA_NASCIMENTO")).toDateTime(),
                           query.value(rec.indexOf("CPF")).toString(),
                           query.value(rec.indexOf("TELEFONE")).toString(),
                           query.value(rec.indexOf("IMAGEM")).toString());
         return *aluno;
   }

   aluno = new Aluno();

   return *aluno;
}


Professor DbManager::busca_professor(const QString& matricula)
{
   QString consulta = "SELECT * FROM PROFESSOR WHERE MATRICULA = '" + matricula + "'";
   QSqlQuery query(consulta);
   QSqlRecord rec = query.record();

   Professor *professor;

   while (query.next())
   {
         professor = new Professor(query.value(rec.indexOf("MATRICULA")).toString(),
                           query.value(rec.indexOf("NOME")).toString(),
                           query.value(rec.indexOf("ENDERECO")).toString(),
                           query.value(rec.indexOf("EMAIL")).toString(),
                           query.value(rec.indexOf("DATA_NASCIMENTO")).toDateTime(),
                           query.value(rec.indexOf("CPF")).toString(),
                           query.value(rec.indexOf("TELEFONE")).toString(),
                           query.value(rec.indexOf("IMAGEM")).toString());
         return *professor;
   }

   professor = new Professor();

   return *professor;
}

exercicio DbManager::busca_exercicio(const QString& codigo)
{
   QString consulta = "SELECT * FROM EXERCICIO WHERE CODIGO = '" + codigo + "'";
   QSqlQuery query(consulta);
   QSqlRecord rec = query.record();

   exercicio *exercicio1;

   while (query.next())
   {
         exercicio1 = new exercicio(query.value(rec.indexOf("CODIGO")).toString(),
                           query.value(rec.indexOf("NOME")).toString(),
                           query.value(rec.indexOf("DESCRICAO")).toString(),
                           query.value(rec.indexOf("IMAGEM")).toString());
         return *exercicio1;
   }

   exercicio1 = new exercicio();

   return *exercicio1;
}


bool DbManager::addAluno(const Aluno& aluno)
{
   bool success = false;
   // you should check if args are ok first...
   QSqlQuery query;

   if(query.exec("CREATE TABLE IF NOT EXISTS "
                 "                           ALUNO(ID_ALUNO INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,"
                 "                                 MATRICULA VARHCAR(6), "
                 "                                 NOME VARCHAR(100),"
                 "                                 ENDERECO VARCHAR(100),"
                 "                                 EMAIL VARCHAR(50),"
                 "                                 DATA_NASCIMENTO DATETIME,"
                 "                                 CPF VARCHAR(12),"
                 "                                 TELEFONE VARCHAR(15),"
                 "                                 IMAGEM VARCHAR(250))"))
   {
       success = true;
       qDebug() << "deu certo o create table";
   }
   else
   {
       success = false;
       qDebug() << "deu errado o create table";
   }

   query.clear();
   query.prepare("INSERT INTO ALUNO(MATRICULA, NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE, IMAGEM) "
                 "VALUES (:MATRICULA,:NOME, :ENDERECO, :EMAIL, :DATA_NASCIMENTO, :CPF, :TELEFONE, :IMAGEM)");
   query.bindValue(":MATRICULA", aluno.matricula);
   query.bindValue(":NOME", aluno.nome);
   query.bindValue(":ENDERECO", aluno.endereco);
   query.bindValue(":EMAIL", aluno.email);
   query.bindValue(":DATA_NASCIMENTO", aluno.data_nascimento);
   query.bindValue(":CPF", aluno.cpf);
   query.bindValue(":TELEFONE", aluno.telefone);
   query.bindValue(":IMAGEM", aluno.imagem);



   if(query.exec())
   {
       success = true;
       qDebug() << "deu certo inserir";
   }
   else
   {
        qDebug() << "deu errado inserir";
                 //<< query.lastError();
   }

   return success;
}


bool DbManager::addProfessor(const Professor& professor)
{
   bool success = false;
   // you should check if args are ok first...
   QSqlQuery query;

   if(query.exec("CREATE TABLE IF NOT EXISTS "
                 "                           PROFESSOR(ID_PROFESSOR INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,"
                 "                                 MATRICULA VARHCAR(6), "
                 "                                 NOME VARCHAR(100),"
                 "                                 ENDERECO VARCHAR(100),"
                 "                                 EMAIL VARCHAR(50),"
                 "                                 DATA_NASCIMENTO DATETIME,"
                 "                                 CPF VARCHAR(12),"
                 "                                 TELEFONE VARCHAR(15),"
                 "                                 IMAGEM VARCHAR(200))"))
   {
       success = true;
       qDebug() << "deu certo o create table";
   }
   else
   {
       success = false;
       qDebug() << "deu errado o create table";
   }

   query.clear();
   query.prepare("INSERT INTO PROFESSOR(MATRICULA, NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE, IMAGEM) "
                 "VALUES (:MATRICULA,:NOME, :ENDERECO, :EMAIL, :DATA_NASCIMENTO, :CPF, :TELEFONE, :IMAGEM)");
   query.bindValue(":MATRICULA", professor.matricula);
   query.bindValue(":NOME", professor.nome);
   query.bindValue(":ENDERECO", professor.endereco);
   query.bindValue(":EMAIL", professor.email);
   query.bindValue(":DATA_NASCIMENTO", professor.data_nascimento);
   query.bindValue(":CPF", professor.cpf);
   query.bindValue(":TELEFONE", professor.telefone);
   query.bindValue(":IMAGEM", professor.imagem);



   if(query.exec())
   {
       success = true;
       qDebug() << "deu certo inserir";
   }
   else
   {
        qDebug() << "deu errado inserir";
                 //<< query.lastError();
   }

   return success;
}

bool DbManager::addExercicio(const exercicio& exercicio)
{
   bool success = false;
   // you should check if args are ok first...
   QSqlQuery query;

   if(query.exec("CREATE TABLE IF NOT EXISTS "
                 "                           EXERCICIO(ID_EXERCICIO INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,"
                 "                                 CODIGO VARHCAR(10), "
                 "                                 NOME VARCHAR(100),"
                 "                                 DESCRICAO VARCHAR(100),"
                 "                                 IMAGEM VARCHAR(200))"))
   {
       success = true;
       qDebug() << "deu certo o create table";
   }
   else
   {
       success = false;
       qDebug() << "deu errado o create table";
   }

   query.clear();
   query.prepare("INSERT INTO EXERCICIO(CODIGO, NOME,DESCRICAO,IMAGEM) "
                 "VALUES (:CODIGO,:NOME, :DESCRICAO, :IMAGEM)");
   query.bindValue(":CODIGO", exercicio.codigo);
   query.bindValue(":NOME", exercicio.nome);
   query.bindValue(":DESCRICAO", exercicio.descricao);
   query.bindValue(":IMAGEM", exercicio.imagem);



   if(query.exec())
   {
       success = true;
       qDebug() << "deu certo inserir";
   }
   else
   {
        qDebug() << "deu errado inserir";
                 //<< query.lastError();
   }

   return success;
}

