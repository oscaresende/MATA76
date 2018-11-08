#ifndef ADDPROFESSOR_H
#define ADDPROFESSOR_H

#include <QWidget>
#include "professor.h"
#include "dbmanager.h"

namespace Ui {
class AddProfessor;
}

class AddProfessor : public QWidget
{
    Q_OBJECT

public:
    explicit AddProfessor(QWidget *parent = nullptr, Professor *professor = nullptr);
    ~AddProfessor();
private slots:
    void cadastrar();
    void cancelar();
    void escolher_arquivo();

private:
    Ui::AddProfessor *ui;
    QImage imageFile;
    DbManager *db;

};

#endif // ADDPROFESSOR_H
