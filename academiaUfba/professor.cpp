#include "professor.h"

Professor::Professor()
{

}

Professor::Professor(const QString& matricula, const QString& name, const QString& endereco, const QString& email,
             const QDateTime& data_nascimento, const QString& cpf, const QString& telefone, const QString& imagem)
{
    Professor::id=NULL;
    Professor::matricula=matricula;
    Professor::nome=name;
    Professor::endereco=endereco;
    Professor::email=email;
    Professor::data_nascimento=data_nascimento;
    Professor::cpf=cpf;
    Professor::telefone=telefone;
    Professor::imagem=imagem;
}
