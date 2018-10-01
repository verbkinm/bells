#ifndef LISTLESSON_H
#define LISTLESSON_H

#include <QWidget>
#include <QPushButton>
#include <QCheckBox>
#include <QVBoxLayout>
#include <QDebug>
#include <QMessageBox>
#include <QMediaPlayer>

#include "left_panel/lesson.h"

#include "ui_lesson.h"


class ListLesson : public QWidget
{
    Q_OBJECT
public:

    ListLesson(QMediaPlayer *parentPlayer, int numbers_of_lessons_cange1 = 1, int numbers_of_lessons_cange2 = 1, QWidget *parent = 0);
    ~ListLesson();

    void setNumbersOfLesson             (int numbersOfLessonChange1, int numbersOfLessonChange2);
    void setTimeOfLesson                (int change, int numberOfLesson, QTime lessonBegin, QTime lessonEnd);
    void setSoundsOfLesson              (int change, int numberOfLesson, QString soundBegin, QString soundEnd);
    void setDisableLesson               (int change, int lesson, bool disable);
    void setDisableChange               (int change, bool disable);
    void setChangeVisible               (int change, bool visibility);

    int  getSize                        (int change);

    bool isChangeEnabled                (int change);
    bool isChangeVisible                (int change);
    bool isLessonEnabled                (int change, int lesson);

    QString getLessonTimeBegin          (int change, int numberOfLesson);
    QString getLessonTimeEnd            (int change, int numberOfLesson);

    QString getLessonSoundBegin         (int change, int numberOfLesson);
    QString getLessonSoundEnd           (int change, int numberOfLesson);
    QString getLessonSoundBeginToSave   (int change, int numberOfLesson);
    QString getLessonSoundEndToSave     (int change, int numberOfLesson);
    void retranslate                    ();

private:
    QList<lesson*> pListChange1, pListChange2;
    int count1,count2;
    QVBoxLayout *pVerticalLayout;
    QHBoxLayout *pChange1, *pChange2;
    QPushButton *pHide_show_change1,*pHide_show_change2;
    QCheckBox *pCheckbox_change1,*pCheckbox_change2;

    QMediaPlayer *generalPlayer;

    bool isTwoChangeDisable();
    void correctChange(int change);
signals:

private slots:
    void slot_hide_change1();
    void slot_hide_change2();

    void slot_on_or_off_change1();
    void slot_on_or_off_change2();
};

#endif // LISTLESSON_H
