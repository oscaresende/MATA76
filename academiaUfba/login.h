#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QMessageBox>
#include "dbmanager.h"


namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();
    QString usuario;

private slots:
    void autenticar();
    void cancelar();

signals:
    void autenticou(QString &usuario);

private:
    Ui::login *ui;
    DbManager *db;
};

#endif // LOGIN_H
