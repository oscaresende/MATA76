#include "aluno.h"

Aluno::Aluno(const QString& matricula, const QString& name, const QString& endereco, const QString& email,
             const QDateTime& data_nascimento, const QString& cpf, const QString& telefone)
{
    Aluno::id=NULL;
    Aluno::matricula=matricula;
    Aluno::nome=name;
    Aluno::endereco=endereco;
    Aluno::email=email;
    Aluno::data_nascimento=data_nascimento;
    Aluno::cpf=cpf;
    Aluno::telefone=telefone;
}
