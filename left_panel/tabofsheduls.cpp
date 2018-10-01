#include "left_panel/tabofsheduls.h"

TabOfSheduls::TabOfSheduls(int numbers_of_tabs, QMediaPlayer *parentPlayer) : QTabWidget()
{
    tabs = numbers_of_tabs;

    for(int i = 0; i < tabs; i++){
        pScrollArea.push_back(new ScrollArea);
        pTabs.push_back(new ListLesson(parentPlayer));
        pScrollArea.at(i)->setWidget(pTabs.at(i));
        this->addTab(pScrollArea.at(i),tr("Shedule ") + QString::number(i + 1) );
    }

    this->setContentsMargins(0,0,0,0);

    connect(this, SIGNAL(tabBarDoubleClicked(int)), SLOT(slotSetTabText(int)) );
}
void TabOfSheduls::setNumbersOfLesson(int numberOfTab, int numbersOfLessonChange1, int numbersOfLessonChange2)
{
    pTabs.at(numberOfTab)->setNumbersOfLesson(numbersOfLessonChange1, numbersOfLessonChange2);
}
void TabOfSheduls::setDisableLesson(int numberOfTab, int change, int numberOfLesson, bool disable)
{
    pTabs.at(numberOfTab)->setDisableLesson(change,numberOfLesson,disable);
}
void TabOfSheduls::setDisableChange(int numberOfTab, int change, bool disable)
{
    pTabs.at(numberOfTab)->setDisableChange(change, disable);
}
void TabOfSheduls::setChangeVisible(int numberOfTab, int change, bool visibility)
{
    pTabs.at(numberOfTab)->setChangeVisible(change, visibility);
}
int TabOfSheduls::getSize(int numberOfTab, int change)
{
    return pTabs.at(numberOfTab)->getSize(change);
}
int TabOfSheduls::getTabsCount()
{
    return this->tabBar()->count();
}
void TabOfSheduls::setTimeOfLesson(int numberOfTab, int change, int numberOfLesson, QTime lessonBegin, QTime lessonEnd)
{
    pTabs.at(numberOfTab)->setTimeOfLesson(change,numberOfLesson,lessonBegin,lessonEnd);
}
void TabOfSheduls::setSoundsOfLesson(int numberOfTab, int change, int numberOfLesson, QString soundBegin, QString soundEnd)
{
    pTabs.at(numberOfTab)->setSoundsOfLesson(change, numberOfLesson, soundBegin, soundEnd);
}
bool TabOfSheduls::isChangeEnabled(int tab, int change)
{
    return pTabs.at(tab)->isChangeEnabled(change);
}
bool TabOfSheduls::isChangeVisible(int tab, int change)
{
    return pTabs.at(tab)->isChangeVisible(change);
}
bool TabOfSheduls::isLessonEnabled(int tab, int change, int lesson)
{
    return pTabs.at(tab)->isLessonEnabled(change, lesson);
}
QString TabOfSheduls::getLessonTimeBegin(int numberOfTtab, int change, int numberOfLesson)
{
    return pTabs.at(numberOfTtab)->getLessonTimeBegin(change,numberOfLesson);
}
QString TabOfSheduls::getLessonTimeEnd(int numberOfTab, int change, int numberOfLesson)
{
    return pTabs.at(numberOfTab)->getLessonTimeEnd(change,numberOfLesson);
}
QString TabOfSheduls::getLessonSoundBegin(int numberOfTab, int change, int numberOfLesson)
{
    return pTabs.at(numberOfTab)->getLessonSoundBegin(change,numberOfLesson);
}
QString TabOfSheduls::getLessonSoundEnd(int numberOfTab, int change, int numberOfLesson)
{
    return pTabs.at(numberOfTab)->getLessonSoundEnd(change,numberOfLesson);
}
QString TabOfSheduls::getLessonSoundBeginToSave(int numberOfTab, int change, int numberOfLesson)
{
    return pTabs.at(numberOfTab)->getLessonSoundBeginToSave(change,numberOfLesson);
}
QString TabOfSheduls::getLessonSoundEndToSave(int numberOfTab, int change, int numberOfLesson)
{
    return pTabs.at(numberOfTab)->getLessonSoundEndToSave(change,numberOfLesson);
}
void TabOfSheduls::setCurrentTab(int tab)
{
    this->setCurrentIndex(tab);
}
void TabOfSheduls::slotSetTabText(int numberOfTab)
{
    TabText *tabText = new TabText;
    tabText->setText(this->tabText(numberOfTab) );
    if(tabText->exec() == QDialog::Accepted){
        this->setTabText(numberOfTab,tabText->getText());
    }
    delete tabText;
}
void TabOfSheduls::retranslate()
{
    for(int i = 0; i < pTabs.length(); i++){
        pTabs.at(i)->retranslate();
    }
}

TabOfSheduls::~TabOfSheduls()
{

}
