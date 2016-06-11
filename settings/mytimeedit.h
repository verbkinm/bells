#ifndef MYTIMEEDIT_H
#define MYTIMEEDIT_H

#include <QTimeEdit>
#include <QTimer>
#include <QFont>
#include <QEvent>
#include <QMouseEvent>

class MyTimeEdit : public QTimeEdit
{
    Q_OBJECT

public:
  MyTimeEdit(QWidget *parent = 0);
  ~MyTimeEdit();

  QTime getTime();

private:
    QTimer timer;

    virtual bool event(QEvent *event);

private slots:
    void slotSetCurrentTime();
};

#endif // MYTIMEEDIT_H
