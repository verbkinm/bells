#ifndef SCROLLAREA_H
#define SCROLLAREA_H

#include <QScrollArea>

#include "left_panel/listlesson.h"

class ScrollArea : public QScrollArea
{
public:
    ScrollArea();
    ~ScrollArea();

    void setList(ListLesson *list);
};

#endif // SCROLLAREA_H
