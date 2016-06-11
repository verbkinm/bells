#include "setdatetime.h"
#include "ui_setdatetime.h"

SetDateTime::SetDateTime(QLocale &locale, QWidget *parent) :
  QDialog(parent),chanched(true),
  ui(new Ui::SetDateTime)
{

  ui->setupUi(this);

  ui->calendarWidget->setLocale(locale);
  ui->calendarWidget->setSelectedDate(QDate::currentDate());

  tmpYear  = QDate::currentDate().year();
  tmpMonth = QDate::currentDate().month();

  chanched = false;

  ui->verticalLayout->insertWidget(1, &timeEdit);

  timer.start(1000);

  connect(ui->calendarWidget, SIGNAL(currentPageChanged(int,int)), SLOT(slotCurrentPageChanged(int,int)) );
  connect(ui->calendarWidget, SIGNAL(selectionChanged()),          SLOT(slotSelectionChanged()) );
}
QTime SetDateTime::getTime()
{
  return timeEdit.getTime();
}
QDate SetDateTime::getDate()
{
  return ui->calendarWidget->selectedDate();
}
void SetDateTime::slotCurrentPageChanged(int year, int month)
{
  if( year != tmpYear || month != tmpMonth )
      chanched = true;
  if( year == tmpYear && month == tmpMonth)
    chanched = false;
}
void SetDateTime::slotSelectionChanged()
{
  chanched = false;
}

/*virtual*/ void SetDateTime::accept()
{
  if( chanched ){
     QMessageBox::information(this, tr("Warning"), tr("Choose a day of the month!"));
     return;
    }
  this->hide();
  this->setResult(QDialog::Accepted);
}

SetDateTime::~SetDateTime()
{
  delete ui;
}
