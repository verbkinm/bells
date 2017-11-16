#ifndef SETDATETIME_H
#define SETDATETIME_H

#include <QDialog>
#include <QTimer>
#include <QMessageBox>

#include "mytimeedit.h"

namespace Ui {
  class SetDateTime;
}

class SetDateTime : public QDialog
{
  Q_OBJECT

public:
  SetDateTime(QLocale locale, QWidget *parent = 0);
  ~SetDateTime();

  QDate getDate();
  QTime getTime();

private:
  int tmpYear;
  int tmpMonth;
  bool chanched;

  Ui::SetDateTime *ui;

  QTimer timer;
  MyTimeEdit timeEdit;

private slots:
  void slotCurrentPageChanged(int year, int month);
  void slotSelectionChanged();

  virtual void accept();

};

#endif // SETDATETIME_H
