#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlQueryModel>
#include <QSortFilterProxyModel>
#include "dbmanager.h"
#include "addaluno.h"
#include "addpro.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void add_aluno();
    void busca_aluno_por_matricula();

    //void add_professor();
    void busca_professor_por_matricula();



private:
    Ui::MainWindow *ui;
    QSqlQueryModel *model;
    QSortFilterProxyModel *proxyModel;

    AddAluno *addInstAluno;
    addpro *addInstProfessor;
};

#endif // MAINWINDOW_H
