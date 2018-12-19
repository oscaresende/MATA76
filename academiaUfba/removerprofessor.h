#ifndef REMOVERPROFESSOR_H
#define REMOVERPROFESSOR_H

#include <QDialog>
#include "dbmanager.h"
#include "QSqlQueryModel"
#include <QSortFilterProxyModel>
#include "QMessageBox"

namespace Ui {
class removerProfessor;
}

class removerProfessor : public QDialog
{
    Q_OBJECT

public:
    explicit removerProfessor(QWidget *parent = nullptr);
    ~removerProfessor();

private slots:
    void remove_professor();

private:
    Ui::removerProfessor *ui;
    DbManager *dbm;
    QSqlQueryModel *model;
    QSortFilterProxyModel *proxyModel;
};

#endif // REMOVERPROFESSOR_H
