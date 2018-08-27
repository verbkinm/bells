#ifndef TABOFSHEDULS_H
#define TABOFSHEDULS_H

#include <QTabWidget>
#include <QSettings>
#include <QMediaPlayer>

#include "left_panel/scrollarea.h"
#include "left_panel/listlesson.h"
#include "left_panel/tabtext.h"

class TabOfSheduls : public QTabWidget
{
    Q_OBJECT

public:
    int tabs;

    TabOfSheduls(int numbers_of_tabs, QMediaPlayer *parentPlayer);
//    QSettings   settings;
    ~TabOfSheduls();

    void setNumbersOfLesson             (int numberOfTab, int numbersOfLessonChange1, int numbersOfLessonChange2);
    void setTimeOfLesson                (int numberOfTab, int change, int numberOfLesson, QTime lessonBegin, QTime lessonEnd);
    void setSoundsOfLesson              (int numberOfTab, int change, int numberOfLesson, QString soundBegin, QString soundEnd);
    void setDisableLesson               (int numberOfTab, int change, int numberOfLesson, bool disable);
    void setDisableChange               (int numberOfTab, int change, bool disable);
    void setChangeVisible               (int numberOfTab, int change, bool visibility);

    int getSize                         (int numberOfTab, int change);
    int getTabsCount                    ();

    QString getLessonTimeBegin          (int numberOfTtab, int change, int numberOfLesson);
    QString getLessonTimeEnd            (int numberOfTtab, int change, int numberOfLesson);

    QString getLessonSoundBegin         (int numberOfTtab, int change, int numberOfLesson);
    QString getLessonSoundEnd           (int numberOfTtab, int change, int numberOfLesson);
    QString getLessonSoundBeginToSave   (int numberOfTtab, int change, int numberOfLesson);
    QString getLessonSoundEndToSave     (int numberOfTtab, int change, int numberOfLesson);

    bool isChangeEnabled                (int tab, int change);
    bool isChangeVisible                (int tab, int change);
    bool isLessonEnabled                (int tab, int change, int lesson);

    void setCurrentTab                  (int tab);
    void retranslate                    ();

    QPushButton* p;

private:
    QList<ListLesson*> pTabs;
    QList<ScrollArea*> pScrollArea;

private slots:
    void slotSetTabText                 (int numberOfTab);

};

#endif // TABOFSHEDULS_H
