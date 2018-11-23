#ifndef REMOVERALUNO_H
#define REMOVERALUNO_H

#include <QDialog>
#include "dbmanager.h"
#include "QSqlQueryModel"
#include <QSortFilterProxyModel>
#include "QMessageBox"

namespace Ui {
class removeraluno;
}

class removeraluno : public QDialog
{
    Q_OBJECT

public:
    explicit removeraluno(QWidget *parent = nullptr);
    ~removeraluno();
private slots:
    void remove_aluno();

signals:
    void recarrega();


private:
    Ui::removeraluno *ui;
    DbManager *dbm;
    QSqlQueryModel *model;
    QSortFilterProxyModel *proxyModel;
};

#endif // REMOVERALUNO_H
