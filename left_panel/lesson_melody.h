#ifndef LESSON_MELODY_H
#define LESSON_MELODY_H

#include <QDialog>
#include <QDir>
#include <QSettings>
#include <QMediaPlayer>

#include "ui_lesson_melody.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    QSettings settings;
    Dialog(QMediaPlayer *parentPlayer);
    ~Dialog();

    void setLessonSoundBegin(QString* sound);
    void setLessonSoundEnd(QString* sound);

    const QString getLessonSoundBegin();
    const QString getLessonSoundEnd();

    void stopSound();

private:
    QDir dir;
    Ui::Dialog *ui;

    QStringList nameFilter;

    QMediaPlayer player;
    QMediaPlayer *generalPlayer;

    bool beginSoundPlaying, endSoundPlaying;

private slots:
    void slotPlayStop1();
    void slotPlayStop2();

    void slotPlayerStop(QMediaPlayer::State state);

    void slotGeneralPlayerStop();
};

#endif // lesson_melody_H
