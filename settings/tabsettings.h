#ifndef TABSETTINGS_H
#define TABSETTINGS_H

#include <QTabWidget>
#include <QDialog>
#include <QDialogButtonBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QComboBox>
#include <QDir>
#include <QDate>
#include <QMediaPlayer>

#include "settings.h"
#include "generals_settings.h"
#include "execprograms.h"

#include "ui_generals_settings.h"
#include "ui_settings.h"

class TabSettings : public QDialog
{
    Q_OBJECT

public:
    QDialogButtonBox    *pButtonBox;
    QVBoxLayout         *pLayout;
    QTabWidget          *pTabs;
    Generals_Settings   *pGeneralSettings;
    ExecPrograms        *pExecPrograms;
    settings            *pTab_of_Day[7];
    int                 CurrentShedule;

    QMediaPlayer        *player;

    TabSettings(QMediaPlayer *parentPlayer, int currentShedule);
    ~TabSettings();

    void days();
    void daysDelete();
    void writeSettingsDays();

    void generals();
    void generalsDelete();
    void writeSettingsGenerals();

    void stopSoundGenerals();
    void stopSoundDays();
};

#endif // TABSETTINGS_H
