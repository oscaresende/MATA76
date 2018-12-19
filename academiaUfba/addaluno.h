#ifndef ADDALUNO_H
#define ADDALUNO_H

#include <QWidget>
#include "aluno.h"
#include "dbmanager.h"

namespace Ui {
class AddAluno;
}

class AddAluno : public QWidget
{
    Q_OBJECT

public:
    explicit AddAluno(QWidget *parent = nullptr, Aluno *aluno = nullptr, const QString& operacao = "");
    ~AddAluno();
private slots:
    void cadastrar();
    void cancelar();
    void escolher_arquivo();

signals:
    void recarrega();

private:
    Ui::AddAluno *ui;        
    QImage imageFile;
    QString imagePath;
    DbManager *db;
    QString op;

};

#endif // ADDALUNO_H
