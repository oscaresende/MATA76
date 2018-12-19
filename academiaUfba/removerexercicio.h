#ifndef REMOVEREXERCICIO_H
#define REMOVEREXERCICIO_H

#include <QDialog>
#include "dbmanager.h"
#include "QSqlQueryModel"
#include <QSortFilterProxyModel>
#include "QMessageBox"

namespace Ui {
class removerExercicio;
}

class removerExercicio : public QDialog
{
    Q_OBJECT

public:
    explicit removerExercicio(QWidget *parent = nullptr);
    ~removerExercicio();

private slots:
    void remove_exercicio();

private:
    Ui::removerExercicio *ui;
    DbManager *dbm;
    QSqlQueryModel *model;
    QSortFilterProxyModel *proxyModel;

};

#endif // REMOVEREXERCICIO_H
