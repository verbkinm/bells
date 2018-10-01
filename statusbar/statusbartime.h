#ifndef STATUSBARTIME_H
#define STATUSBARTIME_H

#include <QLabel>
#include <QEvent>
#include <QActionEvent>
#include <QAction>

class StatusBarTime : public QLabel
{
      Q_OBJECT

public:
  StatusBarTime( QAction *pAction );

private:
  QAction *pActionLabel;
  virtual void mouseDoubleClickEvent(QMouseEvent * event);
};

#endif // STATUSBARTIME_H
