#include "tabtext.h"

TabText::TabText() :
    QDialog(),
    ui(new Ui::TabText)
{
    ui->setupUi(this);
}
QString TabText::getText()
{
    return ui->lineEdit->text();
}
void TabText::setText(QString string)
{
    ui->lineEdit->setText(string);
}

TabText::~TabText()
{
    delete ui;
}
