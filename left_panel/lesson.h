#ifndef LESSON_H
#define LESSON_H

#include <QWidget>
#include <QHBoxLayout>
#include <QMediaPlayer>

#include "lesson_melody.h"

#include "ui_lesson.h"
#include "ui_lesson_melody.h"


namespace Ui {
class lesson;
}

class lesson : public QWidget
{
    Q_OBJECT

public:

    QString lessonSoundBegin,
            lessonSoundEnd;

    QHBoxLayout *layout;
    QVBoxLayout *vLayout;

    lesson(QMediaPlayer *parentPlayer, QWidget *parent = 0);
    ~lesson();

    void setNubmer                      (int number);
    void setTimeOfLesson                (QTime lessonBegin, QTime lessonEnd);
    void setSoundsOfLesson              (QString soundBegin, QString soundEnd);
    void setDisableLesson               (bool disable);

    QString getLessonTimeBegin          ();
    QString getLessonTimeEnd            ();

    QString getLessonSoundBegin         ();
    QString getLessonSoundEnd           ();
    QString getLessonSoundBeginToSave   ();
    QString getLessonSoundEndToSave     ();

    bool isLessonEnabled                ();

    void retranslate                    (int numberOfLesson);

private:
    Ui::lesson *ui;

    QMediaPlayer *generalPlayer;

private slots:
    void slotDialogOpen();
    void slotOnOrOff();
};

#endif // LESSON_H
