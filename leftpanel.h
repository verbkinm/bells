#ifndef LEFTPANEL_H
#define LEFTPANEL_H

#include <QFrame>
#include <QMediaPlayer>

#include "left_panel/tabofsheduls.h"

class LeftPanel : public QFrame
{
    Q_OBJECT

public:

    QSettings settings;

    LeftPanel(QMediaPlayer *parentPlayer);
    ~LeftPanel();

    void setNumbersOfLesson             (int numberOfTab,int numbersOfLessonChange1, int numbersOfLessonChange2);
    void setTimeOfLesson                (int numberOfTab, int change, int numberOfLesson, QTime lessonBegin, QTime lessonEnd);
    void setSoundsOfLesson              (int numberOfTab, int change, int numberOfLesson, QString soundBegin, QString soundEnd);
    void setDisableLesson               (int numberOfTab, int change, int numberOfLesson,bool disable);
    void setDisableChange               (int numberOfTab, int change, bool disable);
    void setChangeVisible               (int numberOfTab, int change, bool visibility);
    void setTabTex                      (int numberOfTab, QString text);

    int getSize                         (int numberOfTab, int change);
    int getTabsCount                    ();
    QString getTabText                  (int numberOfTab);

    QString getLessonTimeBegin          (int numberOfTab, int change, int numberOfLesson);
    QString getLessonTimeEnd            (int numberOfTab, int change, int numberOfLesson);

    QString getLessonSoundBegin         (int numberOfTab, int change, int numberOfLesson);
    QString getLessonSoundEnd           (int numberOfTab, int change, int numberOfLesson);
    QString getLessonSoundBeginToSave   (int numberOfTab, int change, int numberOfLesson);
    QString getLessonSoundEndToSave     (int numberOfTab, int change, int numberOfLesson);

    int currentTab                      ();

    QString currentTabText              ();

    bool isChangeEnabled                (int tab, int change);
    bool isChangeVisible                (int tab, int change);
    bool isLessonEnabled                (int tab, int change, int lesson);

    void setCurrentTab                  (int tab);
    void retranslate                    ();

private:
    QVBoxLayout*    pVerticalLayout;
    TabOfSheduls*   pTabsOfSheduls;
};

#endif // LEFTPANEL_H
