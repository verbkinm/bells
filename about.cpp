#include "about.h"
#include "ui_about.h"

#include <QDialog>

About::About(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::About)
{
    ui->setupUi(this);

    ui->label_text->setText(" \
                        <p align='center' style='font-size:16px;'><b>\"Школьное расписание звонков - Сервер\"<b></p> \
                        <p>Версия продукта: <b>1.0</b></p> \
                        <p>Программа создана на базе <b>Qt " + QString(QT_VERSION_STR) + "</b></p> \
                        <p>Сайт програмы: <a href='https://bells.litsey-yugorsk.ru'>https://bells.litsey-yugorsk.ru</a></p> \
                        ");
}

About::~About()
{
    delete ui;
}
