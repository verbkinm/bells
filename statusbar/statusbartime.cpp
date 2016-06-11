#include "statusbartime.h"
#include <QDebug>

StatusBarTime::StatusBarTime(QAction *pAction)
{
    pActionLabel = pAction;
}
void StatusBarTime::mouseDoubleClickEvent(QMouseEvent *event)
{
  if (event->buttons() == Qt::LeftButton)
    pActionLabel->triggered(true);
}
