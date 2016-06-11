#include "scrollarea.h"

ScrollArea::ScrollArea()
{
    this->setWidgetResizable(true);
}
void ScrollArea::setList(ListLesson *list)
{
    this->setWidget(list);
}

ScrollArea::~ScrollArea()
{

}
