#ifndef GENERALS_SETTINGS_H
#define GENERALS_SETTINGS_H

#include <QWidget>
#include <QSettings>
#include <QFileDialog>
#include <QDir>
#include <QMediaPlayer>

#include "ui_generals_settings.h"
#include "settings/settings.h"
#include "ui_settings.h"

namespace Ui {
class Generals_Settings;
}

class Generals_Settings : public QWidget
{
    Q_OBJECT

public:
    QSettings   settings;
    int countTabs;
    Generals_Settings(QMediaPlayer *parentPlayer, int currentShedule);
    ~Generals_Settings();

    Ui::Generals_Settings *ui;

    void writeSettings();
    void stopSound();

private slots:
    void slot_set_numbers_of_lessons            (int shedul);
    void slot_save_numbers_of_lessons_change1   ();
    void slot_save_numbers_of_lessons_change2   ();
    void slotChooseDir                          ();

    void slotPlayStop();
    void slotPlayerStop(QMediaPlayer::State state);
    void slotGeneralPlayerStop();

    void slotCheckDir(QString dir);

private:
    QDir path_of_sounds_dir;
    QStringList nameFilter;

    QMediaPlayer player;
    QMediaPlayer *generalPlayer;

    int *pCountLessonChange1;
    int *pCountLessonChange2;
};

#endif // GENERALS_SETTINGS_H
