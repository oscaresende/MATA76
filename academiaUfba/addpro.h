#ifndef ADDPRO_H
#define ADDPRO_H

#include <QWidget>
#include "professor.h"
#include "dbmanager.h"

namespace Ui {
class addpro;
}

class addpro : public QWidget
{
    Q_OBJECT

public:
    explicit addpro(QWidget *parent = nullptr, Professor *professor = nullptr);
    ~addpro();

private slots:
    void cadastrar();
    void cancelar();
    void escolher_arquivo();

private:
    Ui::addpro *ui;
    QString imagePath;
    QImage imageFile;
    DbManager *db;
};

#endif // ADDPRO_H
