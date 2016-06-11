#include "mytimeedit.h"

#include <QDebug>
#include <QLineEdit>

MyTimeEdit::MyTimeEdit(QWidget *parent) : QTimeEdit(parent)
{
  this->setTime(QTime::currentTime());

  this->setAlignment(Qt::AlignCenter | Qt::AlignHCenter);
  this->setFixedHeight(35);
  QFont font;
  font.setPixelSize(26);
  this->setFont(font);

  this->setDisplayFormat("HH:mm:ss");

  timer.start(1000);

  connect(&timer, SIGNAL(timeout()), SLOT(slotSetCurrentTime()) );
}
QTime MyTimeEdit::getTime()
{
  return this->time();
}
void MyTimeEdit::slotSetCurrentTime()
{
  this->setTime(QTime::currentTime());
}
/*virtual*/bool MyTimeEdit::event(QEvent *event)
{
  if( event->type() == QEvent::FocusIn )
    timer.stop();
  QWidget::event(event);
}
MyTimeEdit::~MyTimeEdit()
{

}
