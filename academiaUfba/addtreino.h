#ifndef ADDTREINO_H
#define ADDTREINO_H

#include <QWidget>
#include "dbmanager.h"
#include "QSqlQueryModel"
#include <QSortFilterProxyModel>
#include "QSqlRecord"
#include "QDebug"
#include "QMessageBox"
#include "treino.h"
#include "exercicio.h"




namespace Ui {
class addTreino;
}

class addTreino : public QWidget
{
    Q_OBJECT

public:
    explicit addTreino(QWidget *parent = nullptr);
    ~addTreino();
private slots:
    void cancelar();
    void carregarTableViewDisponiveis();
    void carregarTableViewUsados();
    void cadastrar();
    void adicionar_exercicio();
    void remover_exercicio();    

private:
    Ui::addTreino *ui;
    DbManager *db;
    QSqlQueryModel *model;
    QSqlQueryModel *model2;


    QSortFilterProxyModel *proxyModel;
    QSortFilterProxyModel *proxyModel2;
    QSqlQueryModel *model3;
    QSqlQueryModel *model4;
};

#endif // ADDTREINO_H
