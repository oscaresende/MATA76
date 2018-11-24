#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlQueryModel>
#include <QSortFilterProxyModel>
#include "dbmanager.h"
#include "addaluno.h"
#include "addpro.h"
#include "addexercicio.h"
#include "addtreino.h"


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
    void busca_aluno_por_matricula();
    void busca_professor_por_matricula();
    void busca_exercicio_por_codigo();
    void abrir_tela_cadastro_aluno();
    void abrir_tela_cadastro_professor();
    void abrir_tela_cadastro_exercicio();
    void abrir_tela_cadastro_treino();
    void carregarTableView();



private:
    Ui::MainWindow *ui;
    QSqlQueryModel *model;
    QSortFilterProxyModel *proxyModel;
    DbManager *dbm;
    AddAluno *addInstAluno;
    addpro *addInstProfessor;
    addexercicio *addInstExercicio;
    addTreino *addInstTreino;
};

#endif // MAINWINDOW_H
