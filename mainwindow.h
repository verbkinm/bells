#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QSplitter>
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>
#include <QToolBar>
#include <QAction>
#include <QDir>
#include <QProcess>
#include <QFile>
#include <QTranslator>

#include "leftpanel.h"
#include "settings/setdatetime.h"
#include "right_panel/rightpanel.h"
#include "log.h"
#include "settings/tabsettings.h"
#include "statusbar/statusbartime.h"
//#include "tcpserver.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);

private:
    QSettings           settings;
    Log                 log;
    QAction             *pActionCall, *pActionExit, *pActionApply, *pActionOpen, \
                        *pActionSaveSheduls, *pActionReadSettings, \
                        *pActionSettingsDasy, *pActionSettingsGenerals,\
                        *pActionAboutInstruction, *pActionAboutAuthor,\
                        *pActionSetDateTime, *pActionSetLanguageRu, *pActionSetLanguageEn,\
                        *pActionResetSettings;

    QMenu               *pMenuFile, *pMenuBell, *pMenuSettings, *pMenuAbout, *pMenuLanguage;
    QToolBar            *pToolbar;

    QSplitter           *pSplitter;
    LeftPanel           *pLeftPanel;
    RightPanel          *pRightPanel;

    QLabel              *statusBarTimeLabel;

    QMediaPlayer        player;

    QProcess            cmdProgramStart[2]; // prgram_start_1 and prgram_start_2
    QProcess            cmdProgramEnd[2];   // prgram_end_1 and prgram_end_2
    QProcess            cmdAssistant;
    QProcess            cmdSetDateTime;

    int                 timerId;
    QTimer              timer_day_of_the_week;

    int                 currentDayOfWeek;

    QTranslator         qtTranslator;
    QLocale             *localeEN, *localeRU, locale;

// Cache
    QVariant cacheSettingsDays[7][6];
                            // cacheSettingsDays[0 - 6][x]  - day of week               - int
                            // cacheSettingsDays[x][0]      - on_or_off_before_lesson   - bool
                            // cacheSettingsDays[x][1]      - on_or_off_day             - bool
                            // cacheSettingsDays[x][2]      - shedul_of_day             - int
                            // cacheSettingsDays[x][3]      - sound_before_lesson       - QString
                            // cacheSettingsDays[x][4]      - time_before_lesson        - QString
                            // cacheSettingsDays[x][5]      - on_or_off_shedule         - QString
    QVariant cacheSettingsGenerals[10];
                            // cacheSettingsGenerals[0]     - manual_ring               - QString
                            // cacheSettingsGenerals[1]     - numbers_of_tabs           - int
                            // cacheSettingsGenerals[2]     - path_of_sounds_dir        - QString
                            // cacheSettingsGenerals[3]     - prgram_end_1              - QString
                            // cacheSettingsGenerals[4]     - prgram_end_2              - QString
                            // cacheSettingsGenerals[5]     - prgram_start_1            - QString
                            // cacheSettingsGenerals[6]     - prgram_start_2            - QString
                            // cacheSettingsGenerals[7]     - start_tab                 - int
                            // cacheSettingsGenerals[8]     - path_save_and_open_file   - QString
                            // cacheSettingsGenerals[9]     - path_application          - QString

    TcpServer*          server;

    void                startTcpServer      (QString address, int port);
    void                stopTcpServer       ();
    void                resendDataToServer  ();

    void                firstStartProgram   ();

    void                readSettings        ();
    void                readSettingsCache   ();
    void                writeSettings       (bool isSaveSheduls);

    void                createActions       ();
    void                createMenu          ();
    void                createStatusBar     ();

    void                rightPanelSet       ();

    QString             callNow             (QString sound);
    bool                callBeforeLesson    (int change, int lessons);
    void                setSheduleOfDay     ();
    QToolBar*           createToolBar       ();
    void                retranslate         ();

    virtual void        timerEvent          (QTimerEvent*);
    virtual void        closeEvent          (QCloseEvent*);
    virtual void        changeEvent         (QEvent *event);

private slots:
    void                slotApply           ();
    void                slotOpen            ();
    void                slotSaveTemplate    ();

    void                slotCallNow         ();
    void                slotCallStop        ();
    void                slotSetLanguageRu   ();
    void                slotSetLanguageEn   ();

    void                slotSettingsDays    ();
    void                slotSettingsGenerals();

    void                slotResetSettings   ();

    void                slotAboutInstruction();
    void                slotAbout           ();

    void                slotSetDateTime     ();

    void                slotStatusChanged   (QMediaPlayer::State state);

    void                slotCheckDayOfWeek  ();

};

#endif // MAINWINDOW_H
