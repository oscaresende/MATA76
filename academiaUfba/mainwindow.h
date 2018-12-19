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
#include "removeraluno.h"
#include "removerexercicio.h"
#include "removerprofessor.h"
#include "atualizaraluno.h"
#include "atualizarprofessor.h"
#include "atualizarexercicio.h"
#include "login.h"




namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void desautenticar();

private slots:    
    void busca_aluno_por_matricula();
    void busca_professor_por_matricula();
    void busca_exercicio_por_codigo();
    void abrir_tela_cadastro_aluno();
    void abrir_tela_cadastro_professor();
    void abrir_tela_cadastro_exercicio();
    void abrir_tela_cadastro_treino();
    void abrir_tela_remover_aluno();
    void abrir_tela_remover_exercicio();
    void abrir_tela_remover_professor();
    void abrir_tela_atualizar_aluno();
    void abrir_tela_atualizar_professor();
    void abrir_tela_atualizar_exercicio();
    void carregarTableView();
    void logar();

public slots:
    void autenticar(QString &usuario);

private:
    Ui::MainWindow *ui;
    QSqlQueryModel *model;
    QSortFilterProxyModel *proxyModel;
    DbManager *dbm;
    AddAluno *addInstAluno;
    addpro *addInstProfessor;
    addexercicio *addInstExercicio;
    addTreino *addInstTreino;
    removeraluno * remInstAluno;
    removerExercicio * remInstExercicio;
    removerProfessor * remInstProfessor;
    atualizarAluno * atuInstAluno;
    atualizarProfessor * atuInstProfessor;
    atualizarExercicio * atuInstExercicio;
    login * addInstlogin;
    bool autenticado;
};

#endif // MAINWINDOW_H
