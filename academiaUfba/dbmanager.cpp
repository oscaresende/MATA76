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

void DbManager::VerificarTabelas()
{
    QSqlQuery query;

    //criar se não existir a tabela aluno
    if(query.exec("CREATE TABLE IF NOT EXISTS "
                  "                           ALUNO(ID_ALUNO INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,"
                  "                                 MATRICULA VARCHAR(6), "
                  "                                 NOME VARCHAR(100),"
                  "                                 ENDERECO VARCHAR(100),"
                  "                                 EMAIL VARCHAR(50),"
                  "                                 DATA_NASCIMENTO DATETIME,"
                  "                                 CPF VARCHAR(12),"
                  "                                 TELEFONE VARCHAR(15),"
                  "                                 IMAGEM VARCHAR(250))"))
    {
        qDebug() << "tabela aluno verificada";
    }
    else
    {
        qDebug() << "erro na verificação tabela aluno";
    }

    //criar se não existir a tabela professor
    if(query.exec("CREATE TABLE IF NOT EXISTS "
                  "                           PROFESSOR(ID_PROFESSOR INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,"
                  "                                 MATRICULA VARCHAR(6),"
                  "                                 SENHA VARCHAR(6),"
                  "                                 NOME VARCHAR(100),"
                  "                                 ENDERECO VARCHAR(100),"
                  "                                 EMAIL VARCHAR(50),"
                  "                                 DATA_NASCIMENTO DATETIME,"
                  "                                 CPF VARCHAR(12),"
                  "                                 TELEFONE VARCHAR(15),"
                  "                                 IMAGEM VARCHAR(200))"))
    {
        qDebug() << "tabela professor verificada";
    }
    else
    {
        qDebug() << "erro na verificação tabela professor";
    }

    //criar se não existir a tabela exercicio
    if(query.exec("CREATE TABLE IF NOT EXISTS "
                  "                           EXERCICIO(ID_EXERCICIO INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,"
                  "                                 CODIGO VARCHAR(10), "
                  "                                 NOME VARCHAR(100),"
                  "                                 DESCRICAO VARCHAR(100),"
                  "                                 IMAGEM VARCHAR(200))"))
    {
        qDebug() << "tabela exercicio verificada";
    }
    else
    {
        qDebug() << "erro na verificação tabela exercicio";
    }

    //criar se não existir a tabela temp_exercicio
    if(query.exec("CREATE TABLE IF NOT EXISTS "
                  "                           TEMP_EXERCICIO(ID_EXERCICIO INTEGER NOT NULL,"
                  "                                 NOME VARCHAR(100),"
                  "                                 SERIE VARCHAR(5),"
                  "                                 REPETICAO VARCHAR(5))"))
    {
        qDebug() << "tabela temp_exercicio verificada";
    }
    else
    {
        qDebug() << "erro na verificação tabela temp_exercicio";
    }

    //criar se não existir a tabela treino
    if(query.exec("CREATE TABLE IF NOT EXISTS "
                  "                           TREINO(ID_TREINO INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,"
                  "                                  ID_ALUNO INTEGER NOT NULL,"
                  "                                  ID_PROFESSOR INTEGER NOT NULL,"
                  "                                  DATA DATETIME,"
                  "                                  QUANTIDADE_DIAS INTEGER)"))
    {
        qDebug() << "tabela treino verificada";
    }
    else
    {
        qDebug() << "erro na verificação tabela treino";
    }

    //criar se não existir a tabela itens_treino
    if(query.exec("CREATE TABLE IF NOT EXISTS "
                  "                           ITENS_TREINO(ID_TREINO INTEGER NOT NULL,"
                  "                                        ID_EXERCICIO INTEGER NOT NULL,"
                  "                                        SERIE VARCHAR(5),"
                  "                                        REPETICAO VARCHAR(5))"))
    {
        qDebug() << "tabela itens_treino verificada";
    }
    else
    {
        qDebug() << "erro na verificação tabela itens_treino";
    }
}

QString DbManager::listarAlunos()
{
    QString retorno = "SELECT MATRICULA, NOME, ENDERECO, EMAIL, TELEFONE FROM ALUNO";
    return retorno;
}

QString DbManager::listarAlunoEMatricula()
{
    QString retorno = "SELECT MATRICULA, NOME FROM ALUNO";
    return retorno;
}

QString DbManager::listarExercicioECodigo()
{
    QString retorno = "SELECT CODIGO, NOME FROM EXERCICIO";
    return retorno;
}

bool DbManager::remover_aluno(const QString& matricula)
{
    QSqlQuery query;
    query.prepare ("DELETE FROM ALUNO WHERE MATRICULA = :MATRICULA");

    query.bindValue(":MATRICULA", matricula);

    if (query.exec())
    {
        qDebug() << "A remoção deu certo!";
        return true;
    }

    else
    {
        qDebug() << "A remoção falhou!";
        return false;
    }
}

bool DbManager::remover_exercicio(const QString& codigo)
{
    QSqlQuery query;
    query.prepare ("DELETE FROM EXERCICIO WHERE CODIGO = :CODIGO");

    query.bindValue(":CODIGO", codigo);

    if (query.exec())
    {
        qDebug() << "A remoção deu certo!";
        return true;
    }

    else
    {
        qDebug() << "A remoção falhou!";
        return false;
    }
}

bool DbManager::remover_professor(const QString& matricula)
{
    QSqlQuery query;
    query.prepare ("DELETE FROM PROFESSOR WHERE MATRICULA = :MATRICULA");

    query.bindValue(":MATRICULA", matricula);

    if (query.exec())
    {
        qDebug() << "A remoção deu certo!";
        return true;
    }

    else
    {
        qDebug() << "A remoção falhou!";
        return false;
    }
}

QString DbManager::listarProfessores()
{
    QString retorno = "SELECT MATRICULA, NOME, ENDERECO, EMAIL, TELEFONE FROM PROFESSOR";
    return retorno;
}

QString DbManager::listarProfessorEMatricula()
{
    QString retorno = "SELECT MATRICULA, NOME FROM PROFESSOR";
    return retorno;
}

QString DbManager::listarExercicios()
{
    QString retorno = "SELECT ID_EXERCICIO, CODIGO, NOME FROM EXERCICIO  "
                      "WHERE ID_EXERCICIO NOT IN (SELECT ID_EXERCICIO FROM TEMP_EXERCICIO)";
    return retorno;
}

QString DbManager::listarExercicios_temp()
{
    QString retorno = "SELECT ID_EXERCICIO, NOME, SERIE, REPETICAO FROM TEMP_EXERCICIO";
    return retorno;
}

void DbManager::limpar_tabela_temporaria()
{
    QSqlQuery query;
    query.prepare ("DELETE FROM TEMP_EXERCICIO");

    if (query.exec())
    {
        qDebug() << "A remoção deu certo!";
    }
    else
    {
        qDebug() << "A remoção falhou!";
    }
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
                                  query.value(rec.indexOf("SENHA")).toString(),
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
    QSqlQuery query;

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
    }

    return success;
}

bool DbManager::atualizarAluno(const Aluno& aluno)
{
    bool success = false;
    QSqlQuery query;

    query.clear();
    query.prepare("UPDATE ALUNO SET NOME = :NOME, ENDERECO = :ENDERECO, EMAIL = :EMAIL, DATA_NASCIMENTO = :DATA_NASCIMENTO,"
                  "CPF = :CPF, TELEFONE = :TELEFONE, IMAGEM = :IMAGEM "
                  "WHERE MATRICULA = :MATRICULA");
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
        qDebug() << "deu certo atualizar";
    }
    else
    {
        qDebug() << "deu errado atualizar";
    }

    return success;
}


bool DbManager::addProfessor(const Professor& professor)
{
    bool success = false;
    QSqlQuery query;

    query.clear();
    query.prepare("INSERT INTO PROFESSOR(MATRICULA, SENHA, NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE, IMAGEM) "
                  "VALUES (:MATRICULA,:SENHA,:NOME, :ENDERECO, :EMAIL, :DATA_NASCIMENTO, :CPF, :TELEFONE, :IMAGEM)");
    query.bindValue(":MATRICULA", professor.matricula);
    query.bindValue(":SENHA", professor.senha);
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

bool DbManager::atualizarProfessor(const Professor& professor)
{
    bool success = false;
    QSqlQuery query;

    query.clear();
    query.prepare("UPDATE PROFESSOR SET NOME = :NOME, ENDERECO = :ENDERECO, EMAIL = :EMAIL, DATA_NASCIMENTO = :DATA_NASCIMENTO,"
                  "CPF = :CPF, TELEFONE = :TELEFONE, SENHA = :SENHA, IMAGEM = :IMAGEM "
                  "WHERE MATRICULA = :MATRICULA");
    query.bindValue(":MATRICULA", professor.matricula);
    query.bindValue(":NOME", professor.nome);
    query.bindValue(":ENDERECO", professor.endereco);
    query.bindValue(":EMAIL", professor.email);
    query.bindValue(":DATA_NASCIMENTO", professor.data_nascimento);
    query.bindValue(":CPF", professor.cpf);
    query.bindValue(":TELEFONE", professor.telefone);
    query.bindValue(":IMAGEM", professor.imagem);
    query.bindValue(":SENHA", professor.senha);


    if(query.exec())
    {
        success = true;
        qDebug() << "deu certo atualizar";
    }
    else
    {
        qDebug() << "deu errado atualizar";
    }

    return success;
}

bool DbManager::addExercicio(const exercicio& exercicio)
{
    bool success = false;
    QSqlQuery query;

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

bool DbManager::atualizarExercicio(const exercicio& exercicio)
{
    bool success = false;
    QSqlQuery query;

    query.clear();
    query.prepare("UPDATE EXERCICIO SET NOME = :NOME, DESCRICAO = :DESCRICAO, IMAGEM = :IMAGEM "
                  "WHERE CODIGO = :CODIGO");
    query.bindValue(":NOME", exercicio.nome);
    query.bindValue(":DESCRICAO", exercicio.descricao);
    query.bindValue(":IMAGEM", exercicio.imagem);
    query.bindValue(":CODIGO", exercicio.codigo);

    if(query.exec())
    {
        success = true;
        qDebug() << "deu certo atualizar";
    }
    else
    {
        qDebug() << "deu errado atualizar";
    }

    return success;
}

bool DbManager::addExercicio_temp(const int& id, const QString& nome, const QString& serie, const QString& repeticao)
{
    bool success = false;
    QSqlQuery query;

    query.clear();
    query.prepare("INSERT INTO TEMP_EXERCICIO(ID_EXERCICIO, NOME,SERIE,REPETICAO) "
                  "VALUES (:ID,:NOME, :SERIE, :REPETICAO)");
    query.bindValue(":ID", id);
    query.bindValue(":NOME", nome);
    query.bindValue(":SERIE", serie);
    query.bindValue(":REPETICAO", repeticao);

    if(query.exec())
    {
        success = true;
        qDebug() << "deu certo inserir";
    }
    else
    {
        qDebug() << "deu errado inserir";
    }

    return success;
}

bool DbManager::remExercicio_temp(const int &id)
{
    bool success = false;
    QSqlQuery query;

    query.clear();
    query.prepare("DELETE FROM TEMP_EXERCICIO WHERE ID_EXERCICIO = :ID");
    query.bindValue(":ID", id);

    if(query.exec())
    {
        success = true;
        qDebug() << "deu certo remover";
    }
    else
    {
        qDebug() << "deu errado remover";
    }

    return success;
}


bool DbManager::addTreino(const treino& treino)
{
    bool success = false;
    QSqlQuery query;
    int i, max_treino = 0;

    query.clear();
    query.prepare("INSERT INTO TREINO(ID_ALUNO, ID_PROFESSOR, DATA, QUANTIDADE_DIAS) "
                  "VALUES (:ID_ALUNO, :ID_PROFESSOR, :DATA, :QUANTIDADE_DIAS)");
    query.bindValue(":ID_ALUNO", treino.aluno.id);
    query.bindValue(":ID_PROFESSOR", treino.professor.id);
    query.bindValue(":DATA", treino.data);
    query.bindValue(":QUANTIDADE_DIAS", treino.dias);

    if(query.exec())
    {
        success = true;
        qDebug() << "deu certo inserir o treino";
    }
    else
    {
        qDebug() << "deu errado inserir o treino";

    }

    QSqlQuery query_aux(m_db);
    query.prepare("SELECT MAX(ID_TREINO) FROM TREINO");

    if (query.exec())
    {
        while (query.next())
        {
            max_treino = query.value(0).toInt();
        }
    }

    for (i=0; i<treino.exercicios.length(); i++)
    {
        query.clear();
        query.prepare("INSERT INTO ITENS_TREINO(ID_TREINO, ID_EXERCICIO, SERIE, REPETICAO) "
                      "VALUES (:ID_TREINO, :ID_EXERCICIO, :SERIE, :REPETICAO)");
        query.bindValue(":ID_TREINO", max_treino);
        query.bindValue(":ID_EXERCICIO", treino.exercicios[i].id);
        query.bindValue(":SERIE", 3);
        query.bindValue(":REPETICAO", 12);

        if(query.exec())
        {
            success = true;
            qDebug() << "deu certo inserir itens treino";
        }
        else
        {
            qDebug() << "deu errado inserir itens treino";

        }
    }

    return success;
}

void DbManager::CarregarDados()
{
    QSqlQuery query;

    //carga de alunos
    query.clear();
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('10051', 'FRANCISCO PEREIRA DA SILVA', 'RUA CARLOS CÂMARA, 1.652. PRÓXIMO A PC. DO JARDIM AMÉRICA', 'ALUNO@UFBA.BR', '19510716', '05968151315', '8788-0218', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('81', 'ANTONIO BONFIM MEDEIROS', 'RUA FONSECA LOBO 50 APTO.501', 'ALUNO@UFBA.BR', '19510714', '04853873368', '3267-1103', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('251', 'ELIANE QUEIROZ XAVIER', 'RUA VILEBAUDO AGUIAR, 607 APTO. 703', 'ALUNO@UFBA.BR', '19510605', '04513606304', '85 3262-4680', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('271', 'ESTELA ALENCAR MOREIRA', 'RUA MOREIRA DA ROCHA, 89', 'ALUNO@UFBA.BR', '19540520', '06185479320', '3298-1746', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('341', 'FRANCISCA MARCIA LUSTOSA AUTRAN', 'RUA EDGAR PINHO FILHO, 313', 'ALUNO@UFBA.BR', '19470831', '01890948349', '85 3256-5411', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('351', 'FRANCISCA DE MARIA MARQUES CAVALCANTE', 'AV. JOSE LEON, 2740 CASA 07', 'ALUNO@UFBA.BR', '19530424', '06107370315', '85 32710592', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('401', 'FRANCISCO ARISIO BEZERRA CHAVES', 'RUA ISAIE BORIS 349', 'ALUNO@UFBA.BR', '19450811', '00279323387', '85 34914643', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('15882', 'MARIA AVANY MESQUITA', 'RUA MONSENHOR BRUNO, 866 AP 202', 'ALUNO@UFBA.BR', '19620821', '21363358391', '3025.3884', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('631', 'GILBERTO SANTANA NEVES', 'AV.PADRE ANTÔNIIO TOMÁS, 630 APTO 1001 - ED. BALI', 'ALUNO@UFBA.BR', '19490620', '01868560325', '85 32610207', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('641', 'HALEY DE CARVALHO', 'AV. ANTONIO SALES, 2155 APTO. 1201 BLOCO 01', 'ALUNO@UFBA.BR', '19430609', '00231282320', '85 3264-1914', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('681', 'JAIRO GIRAO MACHADO', 'RUA CEL DUARTE COUTINHO 68', 'ALUNO@UFBA.BR', '19590906', '12167320353', '3278-3214', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('701', 'JOAO BARBOSA DO NASCIMENTO', 'RUA SEMPRE VIVA, 92 - COELCE 88', 'ALUNO@UFBA.BR', '19420127', '09784349353', '3482-6663', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('771', 'JOAQUIM JAIRO FERREIRA PAZ', 'RUA CONSELHEIRO ESTELITA, 541', 'ALUNO@UFBA.BR', '19500402', '01995219304', '85 3035 5514', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('941', 'JOSE RIBAMAR OLIVEIRA', 'RUA FAUSTO CABRAL, 240 AP. 602', 'ALUNO@UFBA.BR', '19510407', '01482548372', '85 30940069', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('961', 'JOSE SILVA GURGEL NOGUEIRA', 'RUA TINGUA, 55/403 B', 'ALUNO@UFBA.BR', '19440504', '00222240334', '85 34942036', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('981', 'JOSE WELLINGTON ARAGAO ESMERALDO', 'RUA QUINTINO CUNHA, 809', 'ALUNO@UFBA.BR', '19451107', '00100200397', '3494-8930', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('1011', 'JULIA MARIA DA COSTA FIRMEZA', 'RUA  MARIA ARAUJO COCHRANE, 34', 'ALUNO@UFBA.BR', '19460503', '04871464334', '85 3295-4243', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('1041', 'LINDA CRISTINA TEIXEIRA SILVANO', 'RUA DJALMA ULRICH, 110 APT§ 314', 'ALUNO@UFBA.BR', '19511213', '34436740706', '21 5236568', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('1061', 'LUIZ RODRIGUES', 'RUA ERETIDES DE ALENCAR, 1353', 'ALUNO@UFBA.BR', '19460306', '04150740372', '85 3286-5092', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('1071', 'MANOEL CASTELO BRANCO CAMURCA', 'RUA IEDA CAMURÇA, 168', 'ALUNO@UFBA.BR', '19450830', '00208566368', '85 32905741', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('1121', 'MARIA AURILENE CANDIDO MARTINS', 'RUA MARCONDES PEREIRA, 58', 'ALUNO@UFBA.BR', '19540307', '07334133315', '85 3261.2500', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('1131', 'MARIA BERENICE ROGERIO MAIA', 'RUA GEN. TERTULIANO POTIGUARA 722 APTO.402', 'ALUNO@UFBA.BR', '19380601', '00110396391', '3244.6767', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('1191', 'MARIA DAS GRACAS LEITE ARAUJO', 'RUA J DA PENHA, 284', 'ALUNO@UFBA.BR', '19471018', '04516915391', '85 32260419', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('1201', 'MARIA HELENA MONTEIRO CAVALCANTE', 'RUA CARLOS VASCONCELOS, 2910 CASA 40', 'ALUNO@UFBA.BR', '19451030', '19326580334', '85 32270755', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('1261', 'MARIA LUCINETE SILVA LIMA', 'RUA MARECHAL LOTT, 210', 'ALUNO@UFBA.BR', '19540413', '07387580359', '3275-7303', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('1291', 'MARIA VALDIVIA OLIVEIRA PINHEIRO SALES', 'RUA MONSENHOR BRUNO 782 APT§302', 'ALUNO@UFBA.BR', '19491110', '05993334304', '85 3224-0294', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('1301', 'MARIA VILANI RIBEIRO XAVIER', 'RUA SENADOR SA, 79.', 'ALUNO@UFBA.BR', '19530409', '07271352368', '85 3225-0525', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('1331', 'MURILO VIANA ARAUJO FILHO', 'RUA: VEREADOR PEDRO PAULO, 678', 'ALUNO@UFBA.BR', '19451112', '04531752368', '2781316', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('1341', 'NARCISO FERREIRA', 'RUA RAIMUNDO SIQUEIRA, 1696', 'ALUNO@UFBA.BR', '19441029', '00236292315', '88 33451930', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('1351', 'ONOFRE DE PINHO NUNES', 'AV. BENJAMIM BRASIL, 215', 'ALUNO@UFBA.BR', '19490724', '04847628349', '3262.5594', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('1381', 'PEDRO JORGE', 'RUA MANOEL NUNES 133  A', 'ALUNO@UFBA.BR', '19451110', '00239453387', '3235 5854', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('1401', 'PEDRO WILTON CLARES', 'RUA JOAQUIM NABUCO 2576 APTO.  401', 'ALUNO@UFBA.BR', '19570413', '09071326349', '3244-7343', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('1411', 'POMPEU JUNQUEIRO CHAVES', 'RUA MARCOS MACEDO, 770 APTO. 402', 'ALUNO@UFBA.BR', '19410403', '01562207334', '85 32246017', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('1421', 'RAIMUNDO DE ALMEIDA MIRANDA', 'RUA CARLOS BRAGA, 90', 'ALUNO@UFBA.BR', '19480305', '03923479387', '85 3081.0999', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('1451', 'RAIMUNDO OSVALDO ALMEIDA FILHO', 'RUA DR. JOSE LOURENCO, 1910  APTO. 302', 'ALUNO@UFBA.BR', '19410201', '00316970387', '85 32614094', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('1461', 'REJANE DAMASCENO SERRA DE FREITAS', 'RUA FRANCISCO CHAGAS MENDES 420', 'ALUNO@UFBA.BR', '19560114', '07349009372', '3273-5429', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('1481', 'RITA BRAGA ALVES', 'RUA DES. LAURO NOGUEIRA,1315 AP 301', 'ALUNO@UFBA.BR', '19580513', '10975853368', '3393.3029', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('1491', 'RITA ROCIDELIA SAMPAIO SALES', 'AV. DEPUTADO OSVALDO STUDART, 88', 'ALUNO@UFBA.BR', '19490422', '04672682315', '85 3257-9399', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('1511', 'ROBERTO WILNER REBOUCAS CHAGAS', 'RUA BRUNO PORTO 600 AP 401 B', 'ALUNO@UFBA.BR', '19500902', '05993130300', '3275 2060', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('1521', 'ROMELIA MARIA MARTINS LOPES', 'AV. MISTER HULL, 2992 BL.2 APTO. 301', 'ALUNO@UFBA.BR', '19461230', '01527622304', '85 3287-5067', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('1561', 'SILVIO FONTENELE FACANHA', 'RUA 8 DE SETEMBRO 1130/1501', 'ALUNO@UFBA.BR', '19420107', '00203971353', '85 3267-1576', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('1571', 'SONIA MARIA RIOS VIEIRA', 'RUA MARECHAL DEODORO 755 APTO.204-BL.B', 'ALUNO@UFBA.BR', '19521115', '03475964368', '32236459', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('1611', 'TEREZA ABIGAIL VASCONCELOS DE OLIVEIRA', 'AV. FELICIANO DE ATAIDE 939', 'ALUNO@UFBA.BR', '19530109', '07309848349', '85 32730263', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('1631', 'VANJA SUELY MORENO PRACIANO', 'SHIN QI 7 CONJUNTO 10 CASA 10', 'ALUNO@UFBA.BR', '19561113', '06060277349', '00 33683973', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('1671', 'WILSON FLAVIO ANDRADE AQUINO', 'RUA SILVA JATAY, 250 APTO 1100', 'ALUNO@UFBA.BR', '19500128', '00479055300', '85 3248.0810', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('1691', 'ADALBERTO JACINTO NOGUEIRA', 'RUA PADRE GUERRA, 974', 'ALUNO@UFBA.BR', '19421228', '01018787372', '85 3281-3823', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('1711', 'AGOSTINHO CORREIA FILHO', 'RUA BRUNO VALENTE 1102', 'ALUNO@UFBA.BR', '19540615', '07398956304', '3044 3270', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('1751', 'ALMIR RIBEIRO DA SILVA', 'R. DESEMB. LEITE ALBUQUERQUE, 290 APTO 901', 'ALUNO@UFBA.BR', '19480321', '03770680391', '85 3226-0658', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('1791', 'ANTONIA IVES CAVALCANTE LOPES', 'RUA SAMUEL UCHOA, 985', 'ALUNO@UFBA.BR', '19500320', '03368718304', '85 34947917', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('1841', 'ANTONIO BORGES DA SILVA', 'RUA FRANCISCO DAS CHAGAS MENDES, 615', 'ALUNO@UFBA.BR', '19510103', '01523023368', '85 34592382', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('1941', 'CAIO REGIS AGUIAR DO NASCIMENTO', 'RUA ANTENOR FROTA WANDERLEY, 299 AP. 203BL.01', 'ALUNO@UFBA.BR', '19440718', '01021591300', '85 32833496', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('1991', 'CARLOS CESAR UCHOA BARRETO', 'RUA DR. PERIGARY, 216', 'ALUNO@UFBA.BR', '19500701', '00239259300', '85 32353869', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('2021', 'DARIO RODRIGUES DA SILVA JUNIOR', 'RUA PROFESSOR HERACLITO 605', 'ALUNO@UFBA.BR', '19511108', '03387011334', '3234-0613', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('2111', 'EULALIA VERAS DE MENESCAL PINTO', 'RUA  JOSE LOURENCO 1500 APTO.502-BL.A', 'ALUNO@UFBA.BR', '19570827', '10307214320', '3264-4262', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('2121', 'EUSTACIO ALENCAR MARTINS', 'RUA JOAO REGINO, 88', 'ALUNO@UFBA.BR', '19470602', '01612034349', '85 3091.0235', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('2131', 'EVA NINA GONCALVES DAMASCENO', 'RUA TIRADENTES, 523', 'ALUNO@UFBA.BR', '19451127', '21032041315', '85 32813000', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('2141', 'EYMARD MARTINS DE ALMEIDA FREIRE', 'RUA DR. ALFREDO WEYNE, 55 AP 202 B', 'ALUNO@UFBA.BR', '19500124', '00245046372', '3256 5089', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('1000001', 'GILSON GONÇALVES PEREIRA', 'RUA JOSE FLORENCIO VASCONCELOS,149', 'ALUNO@UFBA.BR', '19620124', '20885458320', '88 3511 1843', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('2161', 'FATIMA MIRES FONTENELE', 'RUA MARECHAL DEODORO, 1301 APTO. 103 BL B', 'ALUNO@UFBA.BR', '19540112', '05123364315', '85 32833916', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('2201', 'FRANCISCA ANITA MARTINS GOMES', 'RUA PASCOAL DE CASTRO ALVES, 778', 'ALUNO@UFBA.BR', '19541205', '10964207320', '85 3234-0810', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('2211', 'FRANCISCO AFONSO RODRIGUES DE CASTRO', 'RUA CARLOS VASCONCELOS, 764 APTO. 103', 'ALUNO@UFBA.BR', '19410808', '00282898387', '85 3224-7556', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('2241', 'FRANCISCO DE ASSIS IVO CAVALCANTE', 'RUA TIBURCIO RODRIGUES, 127', 'ALUNO@UFBA.BR', '19500806', '05673631391', '9.8698 9211', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('2261', 'FRANCISCO BATISTA RIBEIRO', 'RUA PROFESSOR JOAQUIM ANTONIO, 260', 'ALUNO@UFBA.BR', '19460827', '02458039391', '3099 4137', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('2321', 'FRANCISCO EDMILSON SOUSA ARRUDA', 'RUA CABRAL DE ALENCAR, 301 AP 201 BL 08', 'ALUNO@UFBA.BR', '19570919', '09037314368', '3492.1808', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('2341', 'FRANCISCO GOMES DE ARAGAO', 'RUA CEL. MOZART GONDIM, 1400 APTO. 201 BL A', 'ALUNO@UFBA.BR', '19540507', '07324227368', '85 3281-0390', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('2381', 'FRANCISCO PAULINO DE CARVALHO', 'RUA MARTINHO RODRIGUES 1201 APTO.603-BL.B', 'ALUNO@UFBA.BR', '19560422', '09321853391', '3247-1406', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('2391', 'FRANCISCO PAULO MARQUES DO NASCIMENTO', 'RUA WILSON AGUIAR 280, AP 701', 'ALUNO@UFBA.BR', '19460720', '00252352300', '3241.4352', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('2401', 'FRANCISCO SOARES DE OLIVEIRA', 'AV. DOMINGOS OLIMPIO, 1071 APTO. 402 BL. A', 'ALUNO@UFBA.BR', '19511004', '01021656372', '85 3226-5301', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('2421', 'GERALDO ROCILOM DE CASTRO SOUZA', 'RUA SOARES BULCÃO, 350 AP 605 BL B C II', 'ALUNO@UFBA.BR', '19511225', '05104319334', '85 3032 6112', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('2481', 'IRIANE MEDEIROS BANDEIRA BEZERRA DE CARV', 'RUA GENERAL TERTULIANO POTIGUARA, 272 AP. 700', 'ALUNO@UFBA.BR', '19520901', '07383894391', '85 32619092', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('2491', 'IVAN MACHADO DE ALMEIDA', 'RUA GAL. SILVA JUNIOR 700 APTO.401 - BL G', 'ALUNO@UFBA.BR', '19530118', '04923120363', '8686.0153', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('2501', 'IVONEIDE FERNANDES CHAGAS', 'RUA MANOEL JACARE 189 APTO 104 B', 'ALUNO@UFBA.BR', '19530803', '07335008387', '2631501', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('2541', 'JOAO BATISTA CARNEIRO', 'AV. MINISTRO JOSÉ AMÉRICO, 150 - BL. A - APTO 112', 'ALUNO@UFBA.BR', '19550403', '07104758372', '3272-8444', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('2551', 'JOAO BATISTA CARVALHO CAVALCANTE', 'RUA DOM AURELIANO MATOS, 1778', 'ALUNO@UFBA.BR', '19490720', '05672546315', '85 3346-1432', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('2561', 'JOAO DE DEUS BESERRA CAVALCANTE', 'TRAVESSA JOSE PEDRA 333', 'ALUNO@UFBA.BR', '19570308', '07327064320', '3493.3773', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('2581', 'JOAO FREIRE DO PRADO', 'RUA AMERICO VESPUCIO, 352', 'ALUNO@UFBA.BR', '19331118', '00404071368', '3232-9451', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('2621', 'JONAS DE SOUZA VARELA', 'RUA CEL. JOAO CARNEIRO 67 APTO.904', 'ALUNO@UFBA.BR', '19530228', '05958482300', '3257.3860', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('2631', 'JOSE ALCI NORBERTO', 'AV. RUI BARBOSA, 2100 - APTO 302', 'ALUNO@UFBA.BR', '19521208', '05103444372', '2725008', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('2651', 'JOSE CAVALCANTE DE OLIVEIRA', 'RUA AMELIA CONDE, 980', 'ALUNO@UFBA.BR', '19410328', '00278637353', '85 3091 8733', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('2671', 'JOSE EDMAR LIMA MELO', 'RUA JUAQUIM NABUCO, 1850 APTO. 401', 'ALUNO@UFBA.BR', '19510201', '03645916334', '85 3065-5444', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('2701', 'JOSE EUDES GOMES DO CARMO', 'AV. 13 DE JUNHO 925', 'ALUNO@UFBA.BR', '19511102', '06004423300', '8210617', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('2711', 'JOSE HAROLDO LIMA BATISTA', 'RUA LIVREIRO EDESIO, 600', 'ALUNO@UFBA.BR', '19500427', '00245461353', '85 3044.2022', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('2771', 'JOSE LINDEMBERG DUARTE DE SOUSA', 'AV. SENADOR VIRGILIO TAVORA, 2400/1401 BL A', 'ALUNO@UFBA.BR', '19520906', '05311608315', '85 3261-6082', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('2791', 'JOSE MARIA DAMASCENO', 'RUA CARVALHO PEREIRA, 125', 'ALUNO@UFBA.BR', '19540205', '08116288334', '85 3278-3777', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('2801', 'JOSE MARIA DE OLIVEIRA SILVA', 'RUA VIRIATO RIBEIRO 1720', 'ALUNO@UFBA.BR', '19460912', '06809294368', '85 3032 4169', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('2821', 'JOSE ORTAN GOMES MARTINS', 'AV. SANTOS DUMONT, 6400 APTO. 703 BL A', 'ALUNO@UFBA.BR', '19510218', '06102751353', '85 34583586', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('2931', 'LUCIA HELENA GOMES DE CARVALHO', 'RUA ANTÔNIO GENTIL GOMES, 300 APTO 302', 'ALUNO@UFBA.BR', '19500718', '18623891368', '3271.0396', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('2981', 'LUIZ DE GONZAGA TIMBO RODRIGUES', 'RUA REPUBLICA DO LIBANO, 300 BL C APTO. 603', 'ALUNO@UFBA.BR', '19460103', '00234150378', '85 32423559', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('2991', 'LUIZ HUMBERTO FERREIRA', 'RUA LOPES FILHO, 130', 'ALUNO@UFBA.BR', '19530716', '04849779387', '2234030', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('3011', 'MANOEL AFRANIO PEDROSA', 'RUA EDUARDO GARCIA, 735 AP. 701', 'ALUNO@UFBA.BR', '19551013', '07065361349', '3224-1682', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('3041', 'MARCELO CAMPOS DE ALCANTARA', 'RUA 28 LOTE 6/8 TORRE 3 AP 504', 'ALUNO@UFBA.BR', '19560628', '09034951391', '61 3047-2731', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('3051', 'MARCIA MARIA DE MELO', 'RUA ANTONINA DO NORTE, 295 APTO. 1101', 'ALUNO@UFBA.BR', '19480501', '04507649315', '85 32140055', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('3101', 'MARIA AMELIA DE MENEZES ARAUJO', 'RUA VISCONDE DE MAUA, 1661/1802 BL RODIN', 'ALUNO@UFBA.BR', '19520615', '04679679387', '85 3268-9357', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('3131', 'MARIA CLEUBA DE OLIVEIRA CALDAS', 'RUA FAGUNDES VARELA, 668', 'ALUNO@UFBA.BR', '19500204', '04692551372', '85 3495-6217', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('3151', 'MARIA ELIETE MAIA ARAUJO', 'RUA MATIAS BARBOSA, 165', 'ALUNO@UFBA.BR', '19560113', '07444915334', '2781316', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('3191', 'MARIA DE FATIMA COELHO PINTO', 'RUA DR. EDSON BRAGA, 88', 'ALUNO@UFBA.BR', '19521103', '05839351334', '85 32235412', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('3201', 'MARIA DE FATIMA DE OLIVEIRA RODRIGUES', 'RUA TEOFREDO GOIANA, 744', 'ALUNO@UFBA.BR', '19491108', '04660803368', '88 9.99377331', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('3281', 'MARIA DO LIVRAMENTO VASCONCELOS MAGALHÃE', 'R. JORGE GUIMARÃES ALMEIDA, 520 BL 06 AP 202', 'ALUNO@UFBA.BR', '19541003', '06124399334', '3063.0905', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('3291', 'MARIA DE LOURDES NOBRE ARAGAO', 'RUA CORONEL MOZART GONDIM, 1400 APTO.201 BL A', 'ALUNO@UFBA.BR', '19550901', '07333242315', '85 3281-0390', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('3311', 'MARIA NEUMA DE AQUINO', 'RUA JAGUARETAMA, 181 APTO. 702 BL 01', 'ALUNO@UFBA.BR', '19470701', '04257596368', '85 3254-5634', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('3321', 'MARIA OLIVEIRA DAVID', 'RUA ALMIRANTE RUFINO 1089 TORRE 1 APTO 903', 'ALUNO@UFBA.BR', '19510108', '07154860391', '85 3085 0937', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('3351', 'MARIA DO SOCORRO RODRIGUES BATISTA', 'RUA MONSENHOR SALVIANO, 115', 'ALUNO@UFBA.BR', '19490419', '06013180300', '85 32254040', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('904991', 'MARIA DO SOCORRO SENA', 'RUA AGAPITO DOS SANTOS, 376 APTO. 204', 'ALUNO@UFBA.BR', '19501220', '09154159334', '85 32812314', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('3391', 'MARIA ZULENE BARBOSA NOGUEIRA', 'RUA MARIA JOSEFINA PESSOA, 519', 'ALUNO@UFBA.BR', '19500914', '10508945372', '3467-2879', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('3411', 'MARLY JUSTO RIBEIRO', 'RUA DOS TABAJARAS, 138 APTO 505 - B', 'ALUNO@UFBA.BR', '19360517', '11635614368', '85 3267-2203', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('3421', 'MARTA MACEDO LOIOLA PARENTE', 'RUA DAS OITICICAS, Nº 100 - APTO 202 BLOCO A1', 'ALUNO@UFBA.BR', '19501027', '05289050310', '85 3232-3203', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('3441', 'MAURILISIO NEPOMUCENO DE ARAUJO', 'RUA DR. MANOEL TEOFILO 191', 'ALUNO@UFBA.BR', '19551227', '07135955315', '3292-9888', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('3501', 'PAULO DE TARSO COLARES DE MELO', 'RUA JULIO AZEVEDO 1516 APTO.702', 'ALUNO@UFBA.BR', '19530101', '07400683349', '3234-4041', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('3561', 'RAIMUNDO MAURICIO MEDINA JUNIOR', 'RUA CONEGUNDES RODRIGUES, 844', 'ALUNO@UFBA.BR', '19410707', '00204609372', '85 3491-5926', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('3581', 'RAIMUNDO SANTANA SILVA', 'RUA CHASTINET GUIMARAES, 56', 'ALUNO@UFBA.BR', '19400111', '02478994372', '85 3287-4694', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('3591', 'REGINALDO DE SOUSA TEIXEIRA', 'RUA CANUTO DE AGUIR 734 - 201', 'ALUNO@UFBA.BR', '19500228', '03178498320', '2429591', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('3601', 'RICARDO LOPES GOYANNA', 'RUA MARIA TOMAZIA, 1429  - AP. 1002', 'ALUNO@UFBA.BR', '19510424', '01331914353', '85 3267 19 00', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('3721', 'SONIA MARIA BESSA', 'RUA ESCRIVAO PINHEIRO, 4195 APT§ 203', 'ALUNO@UFBA.BR', '19501202', '03388727368', '85 3227.8928', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('3821', 'ZILSON CLERTON PONTES', 'RUA FONSECA LOBO 1191 APTO.402', 'ALUNO@UFBA.BR', '19560817', '10262644304', '3244-5547', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('3851', 'ALCINA STELA MAIA MENEZES', 'RUA GUSTAVO SAMPAIO 02075 ED. VERONA AP 303', 'ALUNO@UFBA.BR', '19510506', '07275030306', '3067-8456', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('3861', 'ALOISIO HERBERT LOBO', 'RUA FAUSTO CABRAL, 509', 'ALUNO@UFBA.BR', '19600401', '14199297391', '85 3234.6974', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('3971', 'HENRIQUETA MARIA CARDONHA SAMPAIO', 'RUA DOM JERONIMO 339 APTO.403', 'ALUNO@UFBA.BR', '19570126', '11586648349', '3243-8428', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('4041', 'JOSE TEOFILO HERCULANO BARROSO RODRIGUES', 'RUA CARLOS VASCONCELOS, 3100 APTO 101', 'ALUNO@UFBA.BR', '19500504', '01329162315', '85 3111 5170', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('4061', 'LUCINEIDE PEREIRA DE OLIVEIRA', 'RUA BARAO DE  ARACATI, 1430 AP 1901', 'ALUNO@UFBA.BR', '19540615', '09054448334', '85 3226-4268', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('4271', 'FRANCISCO DE ARAUJO MELO', 'RUA LOBANGO 227', 'ALUNO@UFBA.BR', '19500424', '37295063749', '3342-4048', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('4331', 'JOSE CARLOS SOARES', 'RUA PAULO CHAUTEN BELLO 469 DESTRITO SALURARE', 'ALUNO@UFBA.BR', '19500313', '37435469734', '2205028', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('4401', 'PAULO FERNANDO SOARES', 'RUA ALTO SANTO 42', 'ALUNO@UFBA.BR', '19551121', '38533545720', '2601017', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('4441', 'WLADIA LUCIA BRASIL F DE OLIVEIRA', 'RUA DR. PEDRO SAMPAIO 440', 'ALUNO@UFBA.BR', '19541002', '04845897334', '3262-7207', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('4671', 'MARIA DE FATIMA PIMENTEL CASTELO', 'RUA CEL. LOURENÇO FEITOSA, 75', 'ALUNO@UFBA.BR', '19540421', '07270500363', '88 9.9918 9915', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('4881', 'JOSE ALMIR DE OLIVEIRA', 'RUA BENJAMIN MOURA 448', 'ALUNO@UFBA.BR', '19500104', '54848733804', '85 32793004', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('4911', 'RAIMUNDO FELIPE NETO', 'RUA PAULO MORAIS 600 APTO.202', 'ALUNO@UFBA.BR', '19510316', '05262860320', '3249-3571', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('5061', 'REGINALDO LINS DO CARMO', 'RUA JOSÉ LEON 1078 APTO.204 - BL.05', 'ALUNO@UFBA.BR', '19560330', '05237122353', '3277.9868', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('5181', 'LUCIA MARIA ALVES', 'RUA SOLON PINHEIRO 659', 'ALUNO@UFBA.BR', '19550212', '05943167315', '3226-6406', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('5201', 'MARIA DO CARMO SIQUEIRA F. VIANA', 'SHIN - QL16- CONJ. 06 CASA 17', 'ALUNO@UFBA.BR', '19550410', '05290384391', '3684017', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('5271', 'HERALDO HUMBERTO DE VASCONCELOS', 'TRAVESSA JACINTO 37 APTO 202', 'ALUNO@UFBA.BR', '19571007', '10171762304', '2524518', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('5291', 'MARIA ITANIRA ARAUJO SOARES', 'RUA JOSE GOMES DE MOURA, 91 APTO. 902', 'ALUNO@UFBA.BR', '19511201', '07006640334', '85 3221-3096', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('5331', 'FERNANDO VERISSIMO DE MELO FILHO', 'RUA JOÃO BATISTA RIOS 293', 'ALUNO@UFBA.BR', '19541122', '07410468300', '3289-2408', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('5491', 'MOLARD PARENTE FILHO', 'RUA VALDEMIRO CAVALCANTE 145', 'ALUNO@UFBA.BR', '19460413', '02670887368', '88 3624-1137', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('5501', 'ODINEA ARAUJO SANTOS', 'AV. VIRGILIO TAVORA, 1900 APTO. 202', 'ALUNO@UFBA.BR', '19450110', '04280466300', '85 3244.1628', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('5551', 'MARIA DAS DORES CARNEIRO TORRES', 'RUA SILVA PAULET, 1083 APTO. 301', 'ALUNO@UFBA.BR', '19570915', '10201327368', '85 32245584', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('5611', 'ANTONIO NEUCIRO FERREIRA PONTES', 'R. PINTO MADEIRA, 777 AP. 101', 'ALUNO@UFBA.BR', '19550720', '07329156353', '2268321', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('5691', 'FERNANDO DE SOUSA GURJAO MARQUES', 'AV. HUMBERTO MONTE, 447', 'ALUNO@UFBA.BR', '19570410', '11643374320', '3047-6205', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('5721', 'MANUEL TADEU DA SILVA', 'RUA ESCRIVAO AZEVEDO 456', 'ALUNO@UFBA.BR', '19590924', '13522132300', '32794371', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('5811', 'MARIA DE FATIMA CASTELO BRANCO MONTEIRO', 'RUA VICENTE LEITE 1392 APTO 201', 'ALUNO@UFBA.BR', '19530827', '06187021304', '2243447', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('15801', 'FRANCISCO JOSE NOGUEIRA DA COSTA', 'RUA IRMA SIMAS 100 APTO.704-BL.A', 'ALUNO@UFBA.BR', '19531117', '05363217368', '3267-4898', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('5901', 'MARIA ELZA FERREIRA LIMA', 'SQN 302 - Bl C APTo. 401', 'ALUNO@UFBA.BR', '19551113', '07347162300', '3477435', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('5931', 'APARICIO ROSA FILHO', 'RUA STO ANTONIO, 292', 'ALUNO@UFBA.BR', '19531207', '26191660715', '85 3055.3618', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('6001', 'BOANERGES AUGUSTO BATISTA FILHO', 'RUA ALAMEDA DAS ROSAS 256 Q.15', 'ALUNO@UFBA.BR', '19550307', '10509127304', '3249-1995', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('6061', 'INACIO EDUARDO ANDRADE DOS SANTOS', 'RUA CAMPO AMOR ROCHA 188, APTO. 601', 'ALUNO@UFBA.BR', '19560730', '05129400372', '85 3227-3880', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('6081', 'MARIA MAURICIA GOMES', 'RUA EDMAR VILAR DE QUEIROZ, 197', 'ALUNO@UFBA.BR', '19540713', '06200044368', '85 3278-1624', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('6201', 'JOSE ANDROCELI SAMPAIO GOMES', 'RUA DOUTOR JURANDYR NUNES 508', 'ALUNO@UFBA.BR', '19590904', '12142174353', '3273.2295', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('6211', 'JOSE ARAUJO GOMES', 'RUA MUNDICA PAULA, 681 BL I APTO. 201', 'ALUNO@UFBA.BR', '19440703', '03424820334', '9.8795 7832', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('6221', 'MARIA VERA LUCIA MACHADO', 'AV. SENADOR VIRGILIO TAVORA, 50 APT§ 804', 'ALUNO@UFBA.BR', '19400711', '01480693391', '3242.5184', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('6241', 'MARIA MATILDES DE LIMA', 'RUA JOSE FRAGA NETO, 111', 'ALUNO@UFBA.BR', '19440411', '01657089304', '85 32794482', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('6271', 'ALBERTO JORGE TIGRE FRANCA', 'RUA DR JOAQUIM FROTA, 639 CASA 105', 'ALUNO@UFBA.BR', '19611204', '13947621353', '3361-2776', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('6291', 'SILVIA HELENA ARRAES DE ALENCAR', 'RUA SILVA PAULET, 1151 APTO.201 BL. B', 'ALUNO@UFBA.BR', '19520116', '18623794320', '85 3224-8569', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('6321', 'JOSE SANTOS FILHO', 'RUA WALDERY UCHOA, 600 AP 805', 'ALUNO@UFBA.BR', '19570403', '12083216334', '9.8600 6852', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('6361', 'JOSE MARIA FACANHA', 'RUA TEODOMIRO DE CASTRO, 4160', 'ALUNO@UFBA.BR', '19481208', '05311365315', '85 3228-7115', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('6371', 'PAULO VASCONCELOS SIEBRA', 'RUA RICARDO DE ARAÚJO BRAGA, 76', 'ALUNO@UFBA.BR', '19610302', '16183290300', '3279.5363', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('6381', 'ANTONIA LUCINEIDE MAIA SILVA', 'AV. GENERAL OSORIO DE PAIVA, 7001', 'ALUNO@UFBA.BR', '19530331', '07387610363', '85 34981418', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('6391', 'ELZENI FERREIRA DA SILVA', 'RUA BRAZ DE FRANCESCO, 300 APTO 334', 'ALUNO@UFBA.BR', '19521210', '11204354391', '85 32874195', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('6441', 'FRANCISCO DE ASSIS CASTRO E SILVA', 'RUA ARTUR FERREIRA, 119', 'ALUNO@UFBA.BR', '19481004', '06819893353', '85 34917915', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('6461', 'MARIA DA CONCEICAO PAULA ARAGAO', 'AV. AGUANAMBI,1000 APTO 602', 'ALUNO@UFBA.BR', '19511208', '08153493353', '3231 8344', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('904251', 'RICARDO SERGIO LEITE DEMETRIO DE SOUSA', 'RUA PADRE GUERRA, 2668', 'ALUNO@UFBA.BR', '19541222', '11967684391', '3088-3809', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('6501', 'ANA TEREZA NUNES MAIA', 'RUA GENERAL SILVA JUNIOR, 855 AP. 202 BL A', 'ALUNO@UFBA.BR', '19560612', '11677988304', '85 32562058', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('6531', 'JOSEFA GENY SANTOS', 'RUA ROCHA LIMA, 150 APT§ 102', 'ALUNO@UFBA.BR', '19520406', '03183777304', '3182 3120', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('6541', 'MANOEL PAULO RODRIGUES DA SILVA', 'RUA SANTA CECÍLIA, 1940 CASA 70 - COND. VILA FORTUNA', 'ALUNO@UFBA.BR', '19610914', '06943705334', '99730.1971', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('6571', 'MAYNARDIRA RUIEFISA B. DE MOURA RODRIGUE', 'RUA 1º  DE MAIO, 600', 'ALUNO@UFBA.BR', '19500530', '09086730353', '85 3121 2194', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('6581', 'ULISSES MOREIRA DE PINHO', 'RUA DR. GUIDO FURTADO PINTO 214', 'ALUNO@UFBA.BR', '19560625', '05843057372', '3239-3393', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('6591', 'RUTHE VIEIRA CARNEIRO DUARTE', 'AV.SENADOR VIRGILIO TAVORA, 2400 APTO.1401 BL. A', 'ALUNO@UFBA.BR', '19570326', '11200901304', '85 3261 6082', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('6611', 'JOSE DE CARVALHO OSORIO JUNIOR', 'AV DESEMBARGADOR MOREIRA 2880 APTO.601', 'ALUNO@UFBA.BR', '19450720', '06004300306', '3247.6762', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('6651', 'MARIA DAS GRACAS MARTINS DOS SANTOS', 'RUA JUVENAL GALENO S/N', 'ALUNO@UFBA.BR', '19481218', '05715962315', '88 3624-1164', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('6661', 'MARIA DO CARMO CAVALCANTE CESAR', 'RUA CORONEL LINHARES, 1557 - APTO. 501', 'ALUNO@UFBA.BR', '19510426', '11022396315', '85 32614423', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('6701', 'FRANCISCO BEZERRA LIMA', 'RUA ANTONINA DO NORTE 351 APTO.104-BL.A', 'ALUNO@UFBA.BR', '19560720', '12394068353', '2140888', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('6741', 'MARIA DELMA PINTO DE MENEZES', 'RUA JOAQUIM EMIDIO DE CASTRO, 180', 'ALUNO@UFBA.BR', '19480916', '10170367304', '85 32711973', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('6781', 'MARIA DAS GRACAS CAMPELO GOMES', 'RUA CEL. GUILHERME ALENCAR, 942', 'ALUNO@UFBA.BR', '19550514', '06144721304', '3274-7255', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('6791', 'RAIMUNDO NONATO ALVES DE FREITAS', 'RUA DR. GILBERTO STUDART, 55 SALA 1118', 'ALUNO@UFBA.BR', '19500131', '04136136315', '85 8870-6635', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('6801', 'FRANCISCA HILDA MAGALHAES LOBO FURTADO', 'QUADRA H, CONJ. CASTELO BRANCO 204', 'ALUNO@UFBA.BR', '19500612', '22867848334', '85 3025-3477', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('6841', 'JOAO BATISTA VERAS', 'RUA 03 DE MAIO, 1514', 'ALUNO@UFBA.BR', '19511022', '05801818391', '3482.1042/3478.4998', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('6861', 'JOAO BOSCO COSTA LIMA PENHA', 'RUA CONSELHEIRO GALVAO, 405', 'ALUNO@UFBA.BR', '19520108', '05999260310', '85 34954709', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('6901', 'VICENTE DA COSTA CELEDONIO', 'RUA PERU, 31', 'ALUNO@UFBA.BR', '19470228', '04697065387', '85 32928895', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('6971', 'PERPETUA HELENA RIBEIRO RANGEL', 'RUA EMIDIO LOBO, 190 APTO 602', 'ALUNO@UFBA.BR', '19460206', '11910135372', '85 33617232', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('6991', 'FABIO SINEZIO DA SILVA', 'AV ULISSES BEZERRA 1254', 'ALUNO@UFBA.BR', '19580523', '10738940372', '2795674', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('7081', 'ELIZABETH DE ALBUQUERQUE E ARRAES', 'AV. ENG. SANTANA JUNIOR 303 APTO.303', 'ALUNO@UFBA.BR', '19540314', '04539966391', '3262-2034', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('7171', 'HUGO JOSE MELO BEZERRA', 'RUA ESIO LIMA VERDE 245 VILAGE AGUA FRIA', 'ALUNO@UFBA.BR', '19450714', '01883879353', '32393453', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('7181', 'LUSERO BRIGIDO DE ALMEIDA', 'RUA CARLOS VASCONCELOS, 2427 APTO. 802', 'ALUNO@UFBA.BR', '19510326', '02633647391', '85 32460898', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('902951', 'ALMIR FRANCISCO BRASIL', 'RUA PROFESSOR CARVALHO, 3175  APTO. 801', 'ALUNO@UFBA.BR', '19410604', '01678043320', '85 32575301', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('7241', 'ARISLY MARIA RIBEIRO MITOSO', 'RUA DOS TABAJARAS 138 BL A 138 AP 204', 'ALUNO@UFBA.BR', '19590526', '14196352391', '3267-6315', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('7261', 'ISLA MONICA MENESES ROLIM', 'RUA SOUSA GIRAO 410 APTO.302-BL.B', 'ALUNO@UFBA.BR', '19561128', '12254479334', '3226-9173', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('7321', 'ANISIO BASTOS PEREIRA', 'RUA SILVA PAULET 2140 APTO.903', 'ALUNO@UFBA.BR', '19561124', '12237981353', '3253-3542', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('7351', 'HENRIQUE JORGE VIANA BARROS', 'RUA 541 - B 145 2A. ETAPA', 'ALUNO@UFBA.BR', '19610213', '08841586320', '85 3294.0088', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('7361', 'RAIMUNDO SAVIO XAVIER GOMES', 'RUA CICERO ALVES DE SOUSA 136', 'ALUNO@UFBA.BR', '19611216', '08848890334', '2793782', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('7401', 'VERA LUCIA CABRAL HOLANDA SILVA', 'RUA AIRTON BORGES MARTINS, 153', 'ALUNO@UFBA.BR', '19560413', '11629363391', '4009-0027', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('7451', 'ELIONE ELSON SARAIVA DA COSTA', 'RUA PAULO FIRMEZA 793 APTO.402-BL.A', 'ALUNO@UFBA.BR', '19531220', '07383371372', '3227-6182', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('7541', 'MARIVALDO ANTONIO SIERRA', 'TRAVESSA SALVADOR MENDONCA, 58 CASA 81', 'ALUNO@UFBA.BR', '19470126', '28710614834', '85 30862830', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('7591', 'JOSE OSWALDO PONTES CASTELO BRANCO', 'RUA MARECHAL LOTT 20', 'ALUNO@UFBA.BR', '19630608', '11419369334', '2797470', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('7621', 'MARIA CLOTILDE DE OLIVEIRA FREITAS', 'RUA SILVIA PAULET, 665 TORRE F AP 1203', 'ALUNO@UFBA.BR', '19530313', '08125430334', '85 3264-5081', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('7651', 'LUCIA ELEIDE VIANA', 'RUA CARLOS VASCONCELOS 1290 APTO.202', 'ALUNO@UFBA.BR', '19480202', '07214480387', '3244-3929', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('7671', 'VULPIANO DE OLIVEIRA FALCAO', 'RUA RAIMUNDO FAÇANHA 120', 'ALUNO@UFBA.BR', '19530901', '08117209349', '3281-5564', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('7701', 'JOSE RIBAMAR URSULINO', 'RUA AROLDO TORRES, QUADRA F 173 CONJ. C. BRA', 'ALUNO@UFBA.BR', '19310315', '01887319387', '85 34785169', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('700261', 'FRANCISCO PINHEIRO DANTAS', 'RUA PEREIRA VALENTE, 610 APTO. 2000', 'ALUNO@UFBA.BR', '19571219', '09355570325', '85 3261-0169', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('7791', 'JOAQUIM TAVARES BRAGA FILHO', 'RUA F - CONJ. COHAB 54', 'ALUNO@UFBA.BR', '19570205', '07388594353', '3348-0711', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('7801', 'VICENTE FERREIRA DE SOUZA', 'RUA GONCALO LAGOS, 443 CASA 4', 'ALUNO@UFBA.BR', '19310821', '01659219353', '85 3223-8058', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('7851', 'JOAO DA COSTA FILHO', 'RUA MAXIMO LINHARES 670', 'ALUNO@UFBA.BR', '19491125', '04066197272', '3271 2455', NULL)");
    query.exec("INSERT INTO ALUNO(MATRICULA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('7881', 'MARIA DO SOCORRO MACEDO DOS SANTOS', 'RUA MONSENHOR CATÃO, 1494 AP 1102', 'ALUNO@UFBA.BR', '19571027', '11621761304', '3281.7525', NULL)");
    //fim da carga de alunos

    //carga de professores
    query.clear();
    query.exec("INSERT INTO PROFESSOR(MATRICULA,SENHA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('67381', '1234' , 'MARIA VERONICA FARIAS DE O. BASTOS', 'AV. SENADOR VIRGILIO TAVORA, 50/703', 'PROFESSOR@UFBA.BR', '19791019', '00000000000', '2446315', NULL)");
    query.exec("INSERT INTO PROFESSOR(MATRICULA,SENHA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('72621', '1234' , 'MAGNOLIA DE SOUSA ALEXANDRE', 'RUA ASSIS CHATEAUBRIAND, 260 APT§ 1002', 'PROFESSOR@UFBA.BR', '19780317', '58217444315', '2618253', NULL)");
    query.exec("INSERT INTO PROFESSOR(MATRICULA,SENHA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('72671', '1234' , 'SOCORRO MIRLANY MOREIRA COSTA', 'RUA GILBERTO CAMARA 561', 'PROFESSOR@UFBA.BR', '19780512', '54901995391', '2236795', NULL)");
    query.exec("INSERT INTO PROFESSOR(MATRICULA,SENHA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('72701', '1234' , 'MARCIO DE SOUSA CHAVES', 'RUA JOAQUIM NABUCO, 3246', 'PROFESSOR@UFBA.BR', '19780330', '56806183387', '85 3257-2294', NULL)");
    query.exec("INSERT INTO PROFESSOR(MATRICULA,SENHA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('72901', '1234' , 'LUCIANA ROCHA DE ARAUJO', 'RUA EFREN GONDIM, 326', 'PROFESSOR@UFBA.BR', '19790623', '61477990372', '2551830', NULL)");
    query.exec("INSERT INTO PROFESSOR(MATRICULA,SENHA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('72911', '1234' , 'ROMENIA IRLANDIA SOARES DUTRA', 'AV. VINTE DE JANEIRO 1573', 'PROFESSOR@UFBA.BR', '19790227', '61475734387', '34852693', NULL)");
    query.exec("INSERT INTO PROFESSOR(MATRICULA,SENHA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('72921', '1234' , 'ELAINE BARRETO MAGALHAES', 'RUA MUIRA, 975 C', 'PROFESSOR@UFBA.BR', '19790512', '61464856320', '2551890', NULL)");
    query.exec("INSERT INTO PROFESSOR(MATRICULA,SENHA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('72931', '1234' , 'LILYAN CORDEIRO MOURAO', 'RUA JUAZEIRO DO NORTE 100/301 B', 'PROFESSOR@UFBA.BR', '19790429', '61466751304', '2426896', NULL)");
    query.exec("INSERT INTO PROFESSOR(MATRICULA,SENHA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('72961', '1234' , 'LUCIANO MEDEIROS BERTINI', 'RUA 125 C. 141 1a.ETAPA', 'PROFESSOR@UFBA.BR', '19790624', '61462101372', '2551884', NULL)");
    query.exec("INSERT INTO PROFESSOR(MATRICULA,SENHA,NOME,ENDERECO,EMAIL,DATA_NASCIMENTO,CPF,TELEFONE,IMAGEM) VALUES ('72981', '1234' , 'JOEB BARBOSA GUIMARAES DE VASCONCELOS', 'RUA REPUBLICA DO LIBANO, 992 AP 901', 'PROFESSOR@UFBA.BR', '19790415', '61468614304', '(85) 3278-6897', NULL)");
    //fim da carga de professores

    //carga de exercicios
    query.clear();
    query.exec("INSERT INTO EXERCICIO(CODIGO, NOME, DESCRICAO, IMAGEM) VALUES ('001', 'SUPINO RETO', 'EXERCICIO PARA O PEITORAL SUPERIOR', '')");
    query.exec("INSERT INTO EXERCICIO(CODIGO, NOME, DESCRICAO, IMAGEM) VALUES ('002', 'SUPINO INCLINADO', 'EXERCICIO PARA O PEITORAL INFERIOR', '')");
    query.exec("INSERT INTO EXERCICIO(CODIGO, NOME, DESCRICAO, IMAGEM) VALUES ('003', 'SUPINO DECLINADO', 'EXERCICIO PARA O PEITORAL MEDIO', '')");
    query.exec("INSERT INTO EXERCICIO(CODIGO, NOME, DESCRICAO, IMAGEM) VALUES ('004', 'ROSCA DIRETA', 'EXERCICIO PARA O BÍCEPS', '')");
    query.exec("INSERT INTO EXERCICIO(CODIGO, NOME, DESCRICAO, IMAGEM) VALUES ('005', 'ROSCA INVERSA', 'EXERCICIO PARA O BÍCEPS', '')");
    query.exec("INSERT INTO EXERCICIO(CODIGO, NOME, DESCRICAO, IMAGEM) VALUES ('006', 'ROSCA ALTERNADA', 'EXERCICIO PARA O BÍCEPS', '')");
    query.exec("INSERT INTO EXERCICIO(CODIGO, NOME, DESCRICAO, IMAGEM) VALUES ('007', 'ROSCA SCOTT', 'EXERCICIO PARA O BÍCEPS', '')");
    query.exec("INSERT INTO EXERCICIO(CODIGO, NOME, DESCRICAO, IMAGEM) VALUES ('008', 'PUXADOR FRENTE', 'EXERCICIO PARA AS COSTAS', '')");
    query.exec("INSERT INTO EXERCICIO(CODIGO, NOME, DESCRICAO, IMAGEM) VALUES ('009', 'PUXADOR TRÁS', 'EXERCICIO PARA AS COSTAS', '')");
    query.exec("INSERT INTO EXERCICIO(CODIGO, NOME, DESCRICAO, IMAGEM) VALUES ('010', 'REMADA ALTA', 'EXERCICIO PARA AS COSTAS', '')");
    query.exec("INSERT INTO EXERCICIO(CODIGO, NOME, DESCRICAO, IMAGEM) VALUES ('011', 'REMADA CAVALINHO', 'EXERCICIO PARA AS COSTAS', '')");
    query.exec("INSERT INTO EXERCICIO(CODIGO, NOME, DESCRICAO, IMAGEM) VALUES ('012', 'LEG PRESS 45', 'EXERCICIO PARA AS PERNAS', '')");
    query.exec("INSERT INTO EXERCICIO(CODIGO, NOME, DESCRICAO, IMAGEM) VALUES ('013', 'LEG PRESS 180 ', 'EXERCICIO PARA AS PERNAS', '')");
    query.exec("INSERT INTO EXERCICIO(CODIGO, NOME, DESCRICAO, IMAGEM) VALUES ('014', 'LEG CARRINHO', 'EXERCICIO PARA AS PERNAS', '')");
    query.exec("INSERT INTO EXERCICIO(CODIGO, NOME, DESCRICAO, IMAGEM) VALUES ('015', 'AGACHAMENTO', 'EXERCICIO PARA AS PERNAS', '')");
    //fim da carga de exercicios
}
