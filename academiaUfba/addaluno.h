#ifndef ADDALUNO_H
#define ADDALUNO_H

#include <QWidget>

namespace Ui {
class AddAluno;
}

class AddAluno : public QWidget
{
    Q_OBJECT

public:
    explicit AddAluno(QWidget *parent = nullptr);
    ~AddAluno();
private slots:
    void cadastrar();

private:
    Ui::AddAluno *ui;
};

#endif // ADDALUNO_H
