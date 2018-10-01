#include "leftpanel.h"

LeftPanel::LeftPanel(QMediaPlayer *parentPlayer) : QFrame(), settings("LYCEUM","Bells")
{
    pTabsOfSheduls = new TabOfSheduls(settings.value("Generals_settings/numbers_of_tabs").toInt(), parentPlayer);

    pVerticalLayout = new QVBoxLayout;

    pVerticalLayout->addWidget(pTabsOfSheduls);

    this->setLayout(pVerticalLayout);

    this->setLineWidth(1);
    this->setFrameStyle(QFrame::WinPanel | Sunken);
}
int LeftPanel::getSize(int numberOfTab, int change)
{
    return pTabsOfSheduls->getSize(numberOfTab,change);
}
int LeftPanel::getTabsCount()
{
    return pTabsOfSheduls->getTabsCount();
}
QString LeftPanel::getTabText(int numberOfTab)
{
    return pTabsOfSheduls->tabBar()->tabText(numberOfTab);
}
int LeftPanel::currentTab()
{
    return pTabsOfSheduls->currentIndex();
}
QString LeftPanel::currentTabText()
{
    return pTabsOfSheduls->tabText(pTabsOfSheduls->currentIndex());
}
bool LeftPanel::isChangeEnabled(int tab, int change)
{
    return pTabsOfSheduls->isChangeEnabled(tab,change);
}
bool LeftPanel::isChangeVisible(int tab, int change)
{
    return pTabsOfSheduls->isChangeVisible(tab, change);
}
bool LeftPanel::isLessonEnabled(int tab, int change, int lesson)
{
    return pTabsOfSheduls->isLessonEnabled(tab, change, lesson);
}
QString LeftPanel::getLessonTimeBegin(int numberOfTab, int change, int numberOfLesson)
{
    return pTabsOfSheduls->getLessonTimeBegin(numberOfTab, change,numberOfLesson);
}
QString LeftPanel::getLessonTimeEnd(int numberOfTab, int change, int numberOfLesson)
{
    return pTabsOfSheduls->getLessonTimeEnd(numberOfTab, change,numberOfLesson);
}
QString LeftPanel::getLessonSoundBegin(int numberOfTab, int change, int numberOfLesson)
{
    return pTabsOfSheduls->getLessonSoundBegin(numberOfTab, change,numberOfLesson);
}
QString LeftPanel::getLessonSoundEnd(int numberOfTab, int change, int numberOfLesson)
{
    return pTabsOfSheduls->getLessonSoundEnd(numberOfTab, change,numberOfLesson);
}
QString LeftPanel::getLessonSoundBeginToSave(int numberOfTab, int change, int numberOfLesson)
{
    return pTabsOfSheduls->getLessonSoundBeginToSave(numberOfTab, change,numberOfLesson);
}
QString LeftPanel::getLessonSoundEndToSave(int numberOfTab, int change, int numberOfLesson)
{
    return pTabsOfSheduls->getLessonSoundEndToSave(numberOfTab, change,numberOfLesson);
}
void LeftPanel::setCurrentTab(int tab)
{
    pTabsOfSheduls->setCurrentIndex(tab);
}
void LeftPanel::setNumbersOfLesson(int numberOfTab, int numbersOfLessonChange1, int numbersOfLessonChange2)
{
    pTabsOfSheduls->setNumbersOfLesson(numberOfTab, numbersOfLessonChange1, numbersOfLessonChange2);
}
void LeftPanel::setTimeOfLesson(int numberOfTab, int change, int numberOfLesson, QTime lessonBegin, QTime lessonEnd)
{
    pTabsOfSheduls->setTimeOfLesson(numberOfTab, change, numberOfLesson, lessonBegin, lessonEnd);
}
void LeftPanel::setSoundsOfLesson(int numberOfTab, int change, int numberOfLesson, QString soundBegin, QString soundEnd)
{
    pTabsOfSheduls->setSoundsOfLesson(numberOfTab, change, numberOfLesson, soundBegin, soundEnd);
}
void LeftPanel::setDisableLesson(int numberOfTab, int change, int numberOfLesson, bool disable)
{
    pTabsOfSheduls->setDisableLesson(numberOfTab, change, numberOfLesson, disable);
}
void LeftPanel::setDisableChange(int numberOfTab, int change, bool disable)
{
    pTabsOfSheduls->setDisableChange(numberOfTab, change, disable);
}
void LeftPanel::setChangeVisible(int numberOfTab, int change, bool visibility)
{
    pTabsOfSheduls->setChangeVisible(numberOfTab, change, visibility);
}
void LeftPanel::setTabTex(int numberOfTab, QString text)
{
    pTabsOfSheduls->setTabText(numberOfTab, text);
    if(text.isEmpty())
        pTabsOfSheduls->setTabText(numberOfTab, tr("Shedule") + " " + QString::number(numberOfTab+1));
}
void LeftPanel::retranslate()
{
  pTabsOfSheduls->retranslate();
}

LeftPanel::~LeftPanel()
{

}
