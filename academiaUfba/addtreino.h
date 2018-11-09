#ifndef ADDTREINO_H
#define ADDTREINO_H

#include <QWidget>
#include "dbmanager.h"
#include "QSqlQueryModel"
#include <QSortFilterProxyModel>

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

private:
    Ui::addTreino *ui;
    QSqlQueryModel *model;
    QSqlQueryModel *model2;
    QSortFilterProxyModel *proxyModel;
};

#endif // ADDTREINO_H
