#ifndef ABOUTPROGRAM_H
#define ABOUTPROGRAM_H

#include <QDialog>
#include "ui_aboutprogram.h"

namespace Ui {
  class AboutProgram;
}

class AboutProgram : public QDialog
{
  Q_OBJECT

public:
  AboutProgram(QWidget *parent = 0);
  ~AboutProgram();

private:
  Ui::AboutProgram *ui;
};

#endif // ABOUTPROGRAM_H
