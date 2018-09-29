/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "calculatorform.h"
#include "ui_calculatorform.h"

CalculatorForm::CalculatorForm(QWidget *parent)
    : QWidget(parent), ui(new Ui::CalculatorForm)
{
    ui->setupUi(this);
    //connect(ui->number2_lineEdit, SIGNAL(textChanged(QString)), this, SLOT(number2_textChanged(QString)));

    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(pushbutton_1_click()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(pushbutton_2_click()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(pushbutton_3_click()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(pushbutton_4_click()));
}

void CalculatorForm::on_number1_lineEdit_textChanged(const QString &arg1)
{
   /* if (ui->opr_lineEdit->text().compare("+") == 0)
    {
         ui->result_lcdNumber->display(QString::number(arg1.toDouble() + ui->number2_lineEdit->text().toDouble()));
    }

    else if (ui->opr_lineEdit->text().compare("-") == 0)
    {
        ui->result_lcdNumber->display(QString::number(arg1.toDouble() - ui->number2_lineEdit->text().toDouble()));
    }

    else if (ui->opr_lineEdit->text().compare("*") == 0)
    {
        ui->result_lcdNumber->display(QString::number(arg1.toDouble() * ui->number2_lineEdit->text().toDouble()));
    }

    else if (ui->opr_lineEdit->text().compare("/") == 0)
    {
        ui->result_lcdNumber->display(QString::number(arg1.toDouble() / ui->number2_lineEdit->text().toDouble()));
    }*/
}

void CalculatorForm::number2_textChanged(const QString &arg1)
{
    /*if (ui->opr_lineEdit->text().compare("+") == 0)
    {
         ui->result_lcdNumber->display(QString::number(arg1.toDouble() + ui->number1_lineEdit->text().toDouble()));
    }

    else if (ui->opr_lineEdit->text().compare("-") == 0)
    {
        ui->result_lcdNumber->display(QString::number(ui->number1_lineEdit->text().toDouble()-arg1.toDouble()));
    }

    else if (ui->opr_lineEdit->text().compare("*") == 0)
    {
        ui->result_lcdNumber->display(QString::number(arg1.toDouble() * ui->number1_lineEdit->text().toDouble()));
    }

    else if (ui->opr_lineEdit->text().compare("/") == 0)
    {
        ui->result_lcdNumber->display(QString::number(ui->number1_lineEdit->text().toDouble()/arg1.toDouble()));
    }*/
}


void CalculatorForm::pushbutton_1_click()
{
    ui->result_lcdNumber->display(QString::number(ui->number1_lineEdit->text().toDouble()+ui->number2_lineEdit->text().toDouble()));
}


void CalculatorForm::pushbutton_2_click()
{
    ui->result_lcdNumber->display(QString::number(ui->number1_lineEdit->text().toDouble()-ui->number2_lineEdit->text().toDouble()));
}

void CalculatorForm::pushbutton_3_click()
{
    ui->result_lcdNumber->display(QString::number(ui->number1_lineEdit->text().toDouble()*ui->number2_lineEdit->text().toDouble()));
}


void CalculatorForm::pushbutton_4_click()
{
    ui->result_lcdNumber->display(QString::number(ui->number1_lineEdit->text().toDouble()/ui->number2_lineEdit->text().toDouble()));
}
