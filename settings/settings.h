#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#include <QSettings>
#include <QCheckBox>
#include <QDir>
#include <QMediaPlayer>

#include "ui_settings.h"

namespace Ui {
class settings;
}

class settings : public QDialog
{
    Q_OBJECT

public:
    QSettings setting;
    settings(int numberOfDay, QMediaPlayer *parentPlayer);
    ~settings();

    void writeSettings();

    void stopSound();

private:
    Ui::settings *ui;

    int countTabs;
    int day;

    QStringList nameFilter;

    QDir path_of_sounds_dir;

    QMediaPlayer player;
    QMediaPlayer *generalPlayer;

private slots:
    void slot_on_or_off_day();
    void slot_on_or_off_shedule();
    void slot_on_or_off_before_lesson();

    void slotPlayStop();
    void slotPlayerStop(QMediaPlayer::State state);

    void slotGeneralPlayerStop();
};

#endif // SETTINGS_H
