#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlQueryModel>
#include <QSortFilterProxyModel>

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

private:
    Ui::MainWindow *ui;
    QSqlQueryModel *model;
    QSortFilterProxyModel *proxyModel;
};

#endif // MAINWINDOW_H
