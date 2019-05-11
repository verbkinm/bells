#include "mainwindow.h"
#include "about.h"

#include <QToolBar>
#include <QDesktopServices>


#if defined (Q_OS_WIN)
#include <windows.h>
#endif

#include "settings/password.h"

#define dash "-- : --"
#define DEFAULT_SOUND "Повседневный.mp3"
#define timer 1000

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), settings("LYCEUM","Bells")
{
    server = new TcpServer;

    localeEN = new QLocale(QLocale::English);
    localeRU = new QLocale(QLocale::Russian);

    if(settings.value("Generals_settings/language").toString() == "ru_RU")
        locale = *localeRU;
    else if (settings.value("Generals_settings/language").toString() == "en_EN")
        locale = *localeEN;

    log.write(" - start program =))");
    firstStartProgram(); // if the program is started for the first time

    createActions();
    createMenu();
    createStatusBar();

    timerId = startTimer(timer);
    currentDayOfWeek = QDate::currentDate().dayOfWeek();
    timer_day_of_the_week.start(1000);

    pSplitter = new QSplitter(Qt::Horizontal);

    pLeftPanel = new LeftPanel(&player);

    pRightPanel = new RightPanel;

    pSplitter->addWidget(pLeftPanel);
    pSplitter->addWidget(pRightPanel);


    this->addToolBar(Qt::TopToolBarArea, createToolBar());
    this->setCentralWidget(pSplitter);

    this->setWindowIcon(QPixmap(":/img/callNow.png"));
    this->setWindowTitle(tr("School bell schedul"));

    this->show();

    if( settings.value("Generals_settings/on_or_off_server").toBool() )
        if( settings.value("Generals_settings/start_with_program").toBool() )
            startTcpServer(settings.value("Generals_settings/address_listen").toString(), settings.value("Generals_settings/port_listen").toInt() );

    readSettings();
    readSettingsCache();

    if(settings.value("Generals_settings/language").toString() != "en_EN"){
#if defined (Q_OS_WIN)
        qtTranslator.load(settings.value("Generals_settings/path_application").toString()+"\\translation\\arrowpad_"+settings.value("Generals_settings/language").toString());
#endif
#if defined (Q_OS_LINUX)
        qtTranslator.load(settings.value("Generals_settings/path_application").toString()+"/translation/arrowpad_"+settings.value("Generals_settings/language").toString());
#endif
#if defined (Q_OS_FREEBSD)
        qtTranslator.load(settings.value("Generals_settings/path_application").toString()+"/translation/arrowpad_"+settings.value("Generals_settings/language").toString());
#endif
        QApplication::installTranslator(&qtTranslator);
    }

    connect(&player, SIGNAL(stateChanged(QMediaPlayer::State)), SLOT(slotStatusChanged(QMediaPlayer::State)) );

    connect(&timer_day_of_the_week, SIGNAL(timeout()), SLOT(slotCheckDayOfWeek()) );

    setSheduleOfDay();
}
void MainWindow::firstStartProgram()
{
    if(settings.value("Generals_settings/count_of_program").toInt() < 1){
        settings.clear();
#if defined (Q_OS_WIN)
        settings.setValue("Generals_settings/path_application",QCoreApplication::applicationDirPath().replace("/","\\"));
#elif defined (Q_OS_LINUX)
        settings.setValue("Generals_settings/path_application",QCoreApplication::applicationDirPath());
#elif defined (Q_OS_FREEBSD)
        settings.setValue("Generals_settings/path_application",QCoreApplication::applicationDirPath());
#endif
        settings.setValue("Generals_settings/numbers_of_tabs",4);
        settings.setValue("Generals_settings/start_tab",0);

        for(int tab = 0; tab < 4; tab++){
            settings.setValue("Sheduls/shedul"+QString::number(tab)+"/change1/isEnabled",true);
            settings.setValue("Sheduls/shedul"+QString::number(tab)+"/change2/isEnabled",false);
            for(int change = 1; change < 3; change++){
                settings.setValue("Sheduls/shedul"+QString::number(tab)+"/change"+QString::number(change)+"/#numbers_of_lessons",8);
                settings.setValue("Sheduls/shedul"+QString::number(tab)+"/change"+QString::number(change)+"/isVisible",false);
                settings.setValue("Sheduls/shedul"+QString::number(tab)+"/name_of_shedul",tr("Shedule") + " " + QString::number(tab+1));
                for (int lesson = 0; lesson < 9; lesson++) {
                    settings.setValue("Sheduls/shedul"+QString::number(tab)+"/change"+QString::number(change)+"/lesson"+QString::number(lesson)+"/time_begin","00:00");
                    settings.setValue("Sheduls/shedul"+QString::number(tab)+"/change"+QString::number(change)+"/lesson"+QString::number(lesson)+"/time_end","00:00");
                    settings.setValue("Sheduls/shedul"+QString::number(tab)+"/change"+QString::number(change)+"/lesson"+QString::number(lesson)+"/sound_begin",DEFAULT_SOUND);
                    settings.setValue("Sheduls/shedul"+QString::number(tab)+"/change"+QString::number(change)+"/lesson"+QString::number(lesson)+"/sound_end",DEFAULT_SOUND);
                    settings.setValue("Sheduls/shedul"+QString::number(tab)+"/change"+QString::number(change)+"/lesson"+QString::number(lesson)+"/isEnabled",false);
                }
            }
        }

        settings.setValue("Generals_settings/language",QLocale::system().name());
        locale = QLocale::system().language();

        for (int lesson = 1; lesson < 8; lesson++)
            settings.setValue("Sheduls/shedul0/change1/lesson"+QString::number(lesson)+"/isEnabled",true);

        settings.setValue("Sheduls/shedul0/change1/isVisible",true);
        settings.setValue("Sheduls/shedul0/change1/lesson0/time_begin","00:00");
        settings.setValue("Sheduls/shedul0/change1/lesson0/time_end","00:00");

        settings.setValue("Sheduls/shedul0/change1/lesson1/time_begin","08:30");
        settings.setValue("Sheduls/shedul0/change1/lesson1/time_end","09:15");
        settings.setValue("Sheduls/shedul0/change1/lesson1/sound_begin", "Зарядка.mp3");
        settings.setValue("Sheduls/shedul0/change1/lesson1/sound_end",DEFAULT_SOUND);

        settings.setValue("Sheduls/shedul0/change1/lesson2/time_begin","09:30");
        settings.setValue("Sheduls/shedul0/change1/lesson2/time_end","10:10");
        settings.setValue("Sheduls/shedul0/change1/lesson2/sound_begin",DEFAULT_SOUND);
        settings.setValue("Sheduls/shedul0/change1/lesson2/sound_end",DEFAULT_SOUND);

        settings.setValue("Sheduls/shedul0/change1/lesson3/time_begin","10:30");
        settings.setValue("Sheduls/shedul0/change1/lesson3/time_end","11:10");
        settings.setValue("Sheduls/shedul0/change1/lesson3/sound_begin",DEFAULT_SOUND);
        settings.setValue("Sheduls/shedul0/change1/lesson3/sound_end",DEFAULT_SOUND);

        settings.setValue("Sheduls/shedul0/change1/lesson4/time_begin","11:30");
        settings.setValue("Sheduls/shedul0/change1/lesson4/time_end","12:10");
        settings.setValue("Sheduls/shedul0/change1/lesson4/sound_begin",DEFAULT_SOUND);
        settings.setValue("Sheduls/shedul0/change1/lesson4/sound_end",DEFAULT_SOUND);

        settings.setValue("Sheduls/shedul0/change1/lesson5/time_begin","12:25");
        settings.setValue("Sheduls/shedul0/change1/lesson5/time_end","13:05");
        settings.setValue("Sheduls/shedul0/change1/lesson5/sound_begin",DEFAULT_SOUND);
        settings.setValue("Sheduls/shedul0/change1/lesson5/sound_end",DEFAULT_SOUND);

        settings.setValue("Sheduls/shedul0/change1/lesson6/time_begin","13:15");
        settings.setValue("Sheduls/shedul0/change1/lesson6/time_end","13:55");
        settings.setValue("Sheduls/shedul0/change1/lesson6/sound_begin",DEFAULT_SOUND);
        settings.setValue("Sheduls/shedul0/change1/lesson6/sound_end",DEFAULT_SOUND);

        settings.setValue("Sheduls/shedul0/change1/lesson7/time_begin","14:05");
        settings.setValue("Sheduls/shedul0/change1/lesson7/time_end","14:45");
        settings.setValue("Sheduls/shedul0/change1/lesson7/sound_begin",DEFAULT_SOUND);
        settings.setValue("Sheduls/shedul0/change1/lesson7/sound_end",DEFAULT_SOUND);
#if defined (Q_OS_WIN)
        settings.setValue("Generals_settings/path_of_sounds_dir",QCoreApplication::applicationDirPath().replace("/","\\")+"\\sounds");
        settings.setValue("Generals_settings/path_save_and_open_file",QCoreApplication::applicationDirPath().replace("/","\\"));
#elif defined (Q_OS_LINUX)
        settings.setValue("Generals_settings/path_of_sounds_dir",QCoreApplication::applicationDirPath()+"/sounds");
        settings.setValue("Generals_settings/path_save_and_open_file",QCoreApplication::applicationDirPath());
#elif defined (Q_OS_FREEBSD)
        settings.setValue("Generals_settings/path_of_sounds_dir",QCoreApplication::applicationDirPath()+"/sounds");
        settings.setValue("Generals_settings/path_save_and_open_file",QCoreApplication::applicationDirPath());
#endif
        settings.setValue("Generals_settings/manual_ring",DEFAULT_SOUND);
        for (int day = 1; day < 8; day++) {
            settings.setValue("Days/"+QString::number(day)+"/on_or_off_before_lesson",true);
            settings.setValue("Days/"+QString::number(day)+"/on_or_off_day",true);
            settings.setValue("Days/"+QString::number(day)+"/on_or_off_shedule",false);
            settings.setValue("Days/"+QString::number(day)+"/shedul_of_day",0);
            settings.setValue("Days/"+QString::number(day)+"/sound_before_lesson",DEFAULT_SOUND);
            settings.setValue("Days/"+QString::number(day)+"/time_before_lesson",2);
          }
        settings.setValue("Generals_settings/on_or_off_server",false);
        settings.setValue("Generals_settings/address_listen","localhost");
        settings.setValue("Generals_settings/port_listen","83");
        settings.setValue("Generals_settings/start_with_program",false);
    }
    int count = settings.value("Generals_settings/count_of_program").toInt();
    settings.setValue("Generals_settings/count_of_program",++count);
}
void MainWindow::readSettings()
{
    for (int tabs = 0; tabs < pLeftPanel->getTabsCount(); tabs++){
        pLeftPanel->setTabTex(tabs,settings.value("Sheduls/shedul"+QString::number(tabs)+"/name_of_shedul").toString() );
        pLeftPanel->setCurrentTab(tabs);
        for (int change = 1; change < 3; change++){
            pLeftPanel->setNumbersOfLesson(tabs,\
                                           settings.value("Sheduls/shedul"+QString::number(tabs)+"/change1/#numbers_of_lessons").toInt(),\
                                           settings.value("Sheduls/shedul"+QString::number(tabs)+"/change2/#numbers_of_lessons").toInt() );
            pLeftPanel->setChangeVisible(tabs,change, settings.value("Sheduls/shedul"+QString::number(tabs)+"/change"+QString::number(change)+"/isVisible").toBool());
            for (int lesson = 0; lesson < pLeftPanel->getSize(tabs,change); lesson++){
                pLeftPanel->setTimeOfLesson(tabs,change,lesson,\
                                            settings.value("Sheduls/shedul"+QString::number(tabs)+"/change"+QString::number(change)+"/lesson"+QString::number(lesson)+"/time_begin").toTime(),\
                                            settings.value("Sheduls/shedul"+QString::number(tabs)+"/change"+QString::number(change)+"/lesson"+QString::number(lesson)+"/time_end").toTime() );
                pLeftPanel->setSoundsOfLesson(tabs, change, lesson,\
                                              settings.value("Sheduls/shedul"+QString::number(tabs)+"/change"+QString::number(change)+"/lesson"+QString::number(lesson)+"/sound_begin").toString(),
                                              settings.value("Sheduls/shedul"+QString::number(tabs)+"/change"+QString::number(change)+"/lesson"+QString::number(lesson)+"/sound_end").toString() );
                pLeftPanel->setDisableLesson(tabs,change,lesson,settings.value("Sheduls/shedul"+QString::number(tabs)+"/change"+QString::number(change)+"/lesson"+QString::number(lesson)+"/isEnabled").toBool());
            }
                pLeftPanel->setDisableChange(tabs,change,settings.value("Sheduls/shedul"+QString::number(tabs)+"/change"+QString::number(change)+"/isEnabled").toBool());
        }
    }
    pLeftPanel->setCurrentTab(settings.value("Generals_settings/start_tab").toInt());
}
void MainWindow::readSettingsCache()
{
    for(int i = 0; i < 7; i++){
        cacheSettingsDays[i][0] = settings.value("Days/" + QString::number(i+1) + "/on_or_off_before_lesson");
        cacheSettingsDays[i][1] = settings.value("Days/" + QString::number(i+1) + "/on_or_off_day");
        cacheSettingsDays[i][2] = settings.value("Days/" + QString::number(i+1) + "/shedul_of_day");
        cacheSettingsDays[i][3] = settings.value("Days/" + QString::number(i+1) + "/sound_before_lesson");
        cacheSettingsDays[i][4] = settings.value("Days/" + QString::number(i+1) + "/time_before_lesson");
        cacheSettingsDays[i][5] = settings.value("Days/" + QString::number(i+1) + "/on_or_off_shedule");
    }
    cacheSettingsGenerals[0] = settings.value("Generals_settings/manual_ring");
    cacheSettingsGenerals[1] = settings.value("Generals_settings/numbers_of_tabs");
    cacheSettingsGenerals[2] = settings.value("Generals_settings/path_of_sounds_dir");
    cacheSettingsGenerals[3] = settings.value("Generals_settings/program_end_1");
    cacheSettingsGenerals[4] = settings.value("Generals_settings/program_end_2");
    cacheSettingsGenerals[5] = settings.value("Generals_settings/program_start_1");
    cacheSettingsGenerals[6] = settings.value("Generals_settings/program_start_2");
    cacheSettingsGenerals[7] = settings.value("Generals_settings/start_tab");
    cacheSettingsGenerals[8] = settings.value("Generals_settings/path_save_and_open_file");
    cacheSettingsGenerals[9] = settings.value("Generals_settings/path_application");

    if( cacheSettingsGenerals[9].toString().isEmpty() )
        settings.setValue("Generals_settings/path_application", QCoreApplication::applicationDirPath());
}
void MainWindow::writeSettings(bool isSaveSheduls)
{
    int tmpCurrentTab = pLeftPanel->currentTab();

    for (int tab = 0; tab < pLeftPanel->getTabsCount(); tab++){
        pLeftPanel->setCurrentTab(tab);
        settings.setValue("Sheduls/shedul"+QString::number(tab)+"/name_of_shedul", pLeftPanel->getTabText(tab) );
        for (int change = 1; change < 3; change++){
            settings.setValue("Sheduls/shedul"+QString::number(tab)+"/change"+QString::number(change)+"/isVisible",pLeftPanel->isChangeVisible(tab,change) );
            settings.setValue("Sheduls/shedul"+QString::number(tab)+"/change"+QString::number(change)+"/isEnabled",pLeftPanel->isChangeEnabled(tab,change));
            for (int lesson = 0; lesson < pLeftPanel->getSize(tab,change); lesson++){
                settings.setValue("Sheduls/shedul"+QString::number(tab)+"/change"+QString::number(change)+"/lesson"+QString::number(lesson)+"/time_begin",  pLeftPanel->getLessonTimeBegin(tab, change,lesson) );
                settings.setValue("Sheduls/shedul"+QString::number(tab)+"/change"+QString::number(change)+"/lesson"+QString::number(lesson)+"/time_end",    pLeftPanel->getLessonTimeEnd(tab,change,lesson)    );
                settings.setValue("Sheduls/shedul"+QString::number(tab)+"/change"+QString::number(change)+"/lesson"+QString::number(lesson)+"/sound_begin", pLeftPanel->getLessonSoundBeginToSave(tab,change,lesson) );
                settings.setValue("Sheduls/shedul"+QString::number(tab)+"/change"+QString::number(change)+"/lesson"+QString::number(lesson)+"/sound_end",   pLeftPanel->getLessonSoundEndToSave(tab,change,lesson)   );
                settings.setValue("Sheduls/shedul"+QString::number(tab)+"/change"+QString::number(change)+"/lesson"+QString::number(lesson)+"/isEnabled",   pLeftPanel->isLessonEnabled(tab, change, lesson)   );
            }
        }
    }
    pLeftPanel->setCurrentTab(tmpCurrentTab);
    if(!isSaveSheduls)
        settings.setValue("Generals_settings/start_tab",pLeftPanel->currentTab());
}

void MainWindow::createActions()
{
    pActionCall = new QAction(tr("Call"));
    pActionCall->setText(tr("Call"));
    pActionCall->setIcon(QPixmap(":/img/callNow.png"));
    pActionCall->setShortcut(QKeySequence("CTRL+SHIFT+R"));
    connect(pActionCall, SIGNAL(triggered(bool)), SLOT(slotCallNow()) );

    pActionExit = new QAction("Exit");
    pActionExit->setText(tr("Exit"));
    pActionExit->setIcon(QPixmap(":/img/exit.png"));
    pActionExit->setShortcut(QKeySequence("CTRL+Q"));
    connect(pActionExit, SIGNAL(triggered(bool)), SLOT(close()) );

    pActionApply = new QAction("Save");
    pActionApply->setText(tr("Apply"));
    pActionApply->setIcon(QPixmap(":/img/apply.png"));
//    pActionApply->setShortcut(QKeySequence("CTRL+S"));
    connect(pActionApply, SIGNAL(triggered(bool)), SLOT(slotApply()) );

    pActionOpen = new QAction("Open");
    pActionOpen->setText(tr("Open template"));
    pActionOpen->setIcon(QPixmap(":/img/open.png"));
    pActionOpen->setShortcut(QKeySequence("CTRL+O"));
    connect(pActionOpen, SIGNAL(triggered(bool)), SLOT(slotOpen()) );

    pActionSaveSheduls = new QAction("SaveSheduls");
    pActionSaveSheduls->setText(tr("Save the template"));
    pActionSaveSheduls->setIcon(QPixmap(":/img/save_sheduls.png"));
    pActionSaveSheduls->setShortcut(QKeySequence("CTRL+S"));
    connect(pActionSaveSheduls, SIGNAL(triggered(bool)), SLOT(slotSaveTemplate()) );

    pActionSettingsDasy = new QAction("Settings");
    pActionSettingsDasy->setText(tr("Days of the week"));
    pActionSettingsDasy->setIcon(QPixmap(":/img/days.png"));
    pActionSettingsDasy->setShortcut(QKeySequence("ALT+D"));
    connect(pActionSettingsDasy, SIGNAL(triggered(bool)), SLOT(slotSettingsDays()) );

    pActionSettingsGenerals = new QAction("Settings");
    pActionSettingsGenerals->setText(tr("General"));
    pActionSettingsGenerals->setIcon(QPixmap(":/img/settings.png"));
    pActionSettingsGenerals->setShortcut(QKeySequence("ALT+G"));
    connect(pActionSettingsGenerals, SIGNAL(triggered(bool)), SLOT(slotSettingsGenerals()) );

    pActionAboutInstruction = new QAction("Instruction");
    pActionAboutInstruction->setText(tr("instruction"));
    pActionAboutInstruction->setIcon(QPixmap(":/img/instruction.png"));
    pActionAboutInstruction->setShortcut(QKeySequence("F1"));
    connect(pActionAboutInstruction, SIGNAL(triggered(bool)), SLOT(slotAboutInstruction()) );

    pActionAboutAuthor = new QAction("About");
    pActionAboutAuthor->setText(tr("About"));
    pActionAboutAuthor->setIcon(QPixmap(":/img/callNow.png"));
    connect(pActionAboutAuthor, SIGNAL(triggered(bool)), SLOT(slotAbout()) );

    pActionSetDateTime = new QAction("SetDateTime");
    pActionSetDateTime->setText(tr("Date and time"));
    pActionSetDateTime->setIcon(QPixmap(":/img/clock.png"));
    pActionSetDateTime->setShortcut(QKeySequence("ALT+T"));
    connect(pActionSetDateTime, SIGNAL(triggered(bool)), SLOT(slotSetDateTime()) );

    pActionSetLanguageRu = new QAction("SetLanguage");
    pActionSetLanguageRu->setText(tr("Russian"));
    pActionSetLanguageRu->setIcon(QPixmap(":img/ru.png"));
    connect(pActionSetLanguageRu, SIGNAL(triggered(bool)), SLOT(slotSetLanguageRu()) );

    pActionSetLanguageEn = new QAction("SetLanguage");
    pActionSetLanguageEn->setText(tr("English"));
    pActionSetLanguageEn->setIcon(QPixmap(":img/en.png"));
    connect(pActionSetLanguageEn, SIGNAL(triggered(bool)), SLOT(slotSetLanguageEn()) );

    pActionResetSettings = new QAction();
    pActionResetSettings->setText(tr("Default settings"));
    pActionResetSettings->setIcon(QPixmap(":/img/reload.png"));
    connect(pActionResetSettings, SIGNAL(triggered(bool)), SLOT(slotResetSettings()) );
}
void MainWindow::createMenu()
{
    pMenuFile = new QMenu(tr("File"));
    pMenuFile->addAction(pActionApply);
    pMenuFile->addSeparator();
    pMenuFile->addAction(pActionOpen);
    pMenuFile->addAction(pActionSaveSheduls);
    pMenuFile->addSeparator();
    pMenuFile->addAction(pActionExit);

    pMenuBell = new QMenu(tr("Call"));
    pMenuBell->addAction(pActionCall);

    pMenuSettings = new QMenu(tr("Settings"));
    pMenuSettings->addAction(pActionSettingsDasy);
    pMenuSettings->addAction(pActionSettingsGenerals);
    pMenuSettings->addSeparator();
    pMenuSettings->addAction(pActionSetDateTime);

    pMenuLanguage = new QMenu(tr("Language"));
    pMenuLanguage->setIcon(QPixmap(":/img/locale.png"));
    pMenuLanguage->addAction(pActionSetLanguageEn);
    pMenuLanguage->addAction(pActionSetLanguageRu);

    pMenuSettings->addMenu(pMenuLanguage);
    pMenuSettings->addSeparator();
    pMenuSettings->addAction(pActionResetSettings);

    pMenuAbout = new QMenu(tr("Help"));
    pMenuAbout->addAction(pActionAboutInstruction);
    pMenuAbout->addSeparator();
    pMenuAbout->addAction(pActionAboutAuthor);

    this->menuBar()->addMenu(pMenuFile);
    this->menuBar()->addMenu(pMenuBell);
    this->menuBar()->addMenu(pMenuSettings);
    this->menuBar()->addMenu(pMenuAbout);
}
void MainWindow::createStatusBar()
{
    this->setStatusBar(new QStatusBar);
    statusBarTimeLabel = new StatusBarTime(pActionSetDateTime);
    statusBarTimeLabel->setText(QDate::currentDate().toString("dd-MM-yyyy")\
                                + " - "\
                                +QTime::currentTime().toString("hh:mm:ss")\
                                + " (" + locale.dayName(QDate::currentDate().dayOfWeek()) \
                                + ")" );
    statusBarTimeLabel->setAlignment(Qt::AlignCenter | Qt::AlignHCenter);
    statusBar()->addWidget(statusBarTimeLabel);
}
QToolBar* MainWindow::createToolBar()
{
    pToolbar = new QToolBar(tr("Toolbar"));

    pToolbar->addAction(pActionApply);
    pToolbar->addAction(pActionOpen);
    pToolbar->addAction(pActionSaveSheduls);
    pToolbar->addSeparator();
    pToolbar->addAction(pActionCall);
    pToolbar->addSeparator();
    pToolbar->addAction(pActionSettingsDasy);
    pToolbar->addAction(pActionSettingsGenerals);
    pToolbar->addSeparator();
    pToolbar->addAction(pActionSetDateTime);
    pToolbar->addSeparator();
    pToolbar->addAction(pActionAboutInstruction);
    pToolbar->addSeparator();
    pToolbar->addAction(pActionExit);

    pToolbar->setMovable(false);

    return pToolbar;
}
void MainWindow::rightPanelSet()
{
    killTimer(timerId);

    int currentTab = pLeftPanel->currentTab();

    pRightPanel->setNumberOfShedul(pLeftPanel->currentTabText(), currentTab);

    int lessonsNumbersChange1 = pLeftPanel->getSize(currentTab,1);
    int lessonsNumbersChange2 = pLeftPanel->getSize(currentTab,2);
    bool isChangeOneEnabled   = pLeftPanel->isChangeEnabled(currentTab,1);
    bool isChangeTwoEnabled   = pLeftPanel->isChangeEnabled(currentTab,2);

    pRightPanel->setNumbersOfLesson(lessonsNumbersChange1,\
                                    isChangeOneEnabled,\
                                    lessonsNumbersChange2,\
                                    isChangeTwoEnabled);

    server->createDataSendArray(isChangeOneEnabled, \
                                lessonsNumbersChange1, \
                                isChangeTwoEnabled, \
                                lessonsNumbersChange2);

    for(int change = 1; change < 3; change++){
        for(int lesson = 0; lesson < pLeftPanel->getSize(currentTab,change); lesson++){

            QString timeBegin = pLeftPanel->getLessonTimeBegin(currentTab, change,lesson);
            QString timeEnd = pLeftPanel->getLessonTimeEnd(currentTab, change,lesson);

            pRightPanel->setLesson(change,\
                                   lesson,\
                                   timeBegin,\
                                   timeEnd,\
                                   pLeftPanel->getLessonSoundBegin(currentTab, change,lesson),\
                                   pLeftPanel->getLessonSoundEnd(currentTab, change,lesson));

            server->appendDataSendArray(change, \
                                        lesson, \
                                        timeBegin, \
                                        timeEnd, \
                                        pLeftPanel->isLessonEnabled(currentTab, change, lesson) );
        }
    }
//    server->printDataSendArray();
//перемены
    int end_this_lesson,recess,begin_next_lesson;
    QString result;
    bool last_lesson;

    for (int change = 1; change < 3; change++){
        for (int lesson = 0; lesson < pLeftPanel->getSize(pLeftPanel->currentTab(),change)-1; lesson++){
            last_lesson = false;
            if(!pLeftPanel->isLessonEnabled(pLeftPanel->currentTab(), change,lesson)){
                pRightPanel->setRecess(change,lesson,dash);
                continue;
            }
            end_this_lesson = pLeftPanel->getLessonTimeEnd(pLeftPanel->currentTab(), change,lesson).mid(0,2).toInt()*3600\
                            + pLeftPanel->getLessonTimeEnd(pLeftPanel->currentTab(), change,lesson).mid(3,2).toInt()*60;
            begin_next_lesson = pLeftPanel->getLessonTimeBegin(pLeftPanel->currentTab(), change,lesson+1).mid(0,2).toInt()*3600\
                              + pLeftPanel->getLessonTimeBegin(pLeftPanel->currentTab(), change,lesson+1).mid(3,2).toInt()*60;

            if(!pLeftPanel->isLessonEnabled(pLeftPanel->currentTab(), change,lesson+1)){
                if(lesson+2 == pLeftPanel->getSize(pLeftPanel->currentTab(),change)){
                    pRightPanel->setRecess(change,lesson,dash);
                    break;
                }
                for (int nextLesson = lesson+2; nextLesson < pLeftPanel->getSize(pLeftPanel->currentTab(),change); nextLesson++){
                    if(pLeftPanel->isLessonEnabled(pLeftPanel->currentTab(), change, nextLesson)){
                        begin_next_lesson = pLeftPanel->getLessonTimeBegin(pLeftPanel->currentTab(), change,nextLesson).mid(0,2).toInt()*3600\
                                          + pLeftPanel->getLessonTimeBegin(pLeftPanel->currentTab(), change,nextLesson).mid(3,2).toInt()*60;
                        break;
                    }
                    if(nextLesson+1 ==  pLeftPanel->getSize(pLeftPanel->currentTab(),change))
                        last_lesson = true;
                }
            }
            if(last_lesson){
                pRightPanel->setRecess(change,lesson,dash);
                continue;
            }
            recess = begin_next_lesson - end_this_lesson;
            if( recess < 0)
                recess += 86400;
            result = QString::number(recess / 60) + tr(" min.");
            pRightPanel->setRecess(change,lesson,result);
        }
    }
    timerId = startTimer(timer);

    pRightPanel->setTableToolTip();

//    qDebug() << "end rigth";
}
void MainWindow::retranslate()
{
    this->setWindowTitle(tr("School bell schedul"));
    //Menu
    pMenuFile->setTitle(tr("&File"));
    pMenuBell->setTitle(tr("&Call"));
    pMenuSettings->setTitle(tr("&Settings"));
    pMenuLanguage->setTitle(tr("Language"));
    pMenuAbout->setTitle(tr("&Help"));
    //Actions
    pActionCall->setText(tr("Call"));
    pActionExit->setText(tr("Exit"));
    pActionApply->setText(tr("Apply"));
    pActionOpen->setText(tr("Open template"));
    pActionSaveSheduls->setText(tr("Save the template"));
    pActionSettingsDasy->setText(tr("Days of the week"));
    pActionSettingsGenerals->setText(tr("General"));
    pActionResetSettings->setText(tr("Default settings"));
    pActionAboutInstruction->setText(tr("instruction"));
    pActionAboutAuthor->setText(tr("About..."));
    pActionSetDateTime->setText(tr("Date and time"));
    pActionSetLanguageRu->setText(tr("Russian"));
    pActionSetLanguageEn->setText(tr("English"));
    //RightPanel
    int tmpCurrentTab = pLeftPanel->currentTab();
    pLeftPanel->setCurrentTab(pRightPanel->getNumberOfInstalTab());
    rightPanelSet();
    pLeftPanel->setCurrentTab(tmpCurrentTab);
    //LeftPanel
    pLeftPanel->retranslate();

    this->removeToolBar(pToolbar);
    this->addToolBar(Qt::TopToolBarArea, createToolBar());
}
QString MainWindow::callNow(QString sound)
{
    if(sound == dash)
        return "\0";

#if defined (Q_OS_WIN)
  if( !QFile(cacheSettingsGenerals[2].toString() + "\\" + sound).exists() ){
      QMessageBox::warning(this,tr("Warning"),tr("The file ") + cacheSettingsGenerals[2].toString() + "\\" + sound + tr(" - not exist!"),QMessageBox::Ok);
      return "error, file \"" + cacheSettingsGenerals[2].toString() + "\\" + sound + "\" - not exist!";
  }
#elif defined (Q_OS_LINUX)
    if( !QFile(cacheSettingsGenerals[2].toString() + "/" + sound).exists() ){
        QMessageBox::warning(this,tr("Warning"),tr("The file ") + cacheSettingsGenerals[2].toString() + "\\" + sound + tr(" - not exist!"),QMessageBox::Ok);
        return "error, file \"" + cacheSettingsGenerals[2].toString() + "/" + sound + " - not exist!";
    }
#elif defined (Q_OS_FREEBSD)
    if( !QFile(cacheSettingsGenerals[2].toString() + "/" + sound).exists() ){
        QMessageBox::warning(this,tr("Warning"),tr("The file ") + cacheSettingsGenerals[2].toString() + "\\" + sound + tr(" - not exist!"),QMessageBox::Ok);
        return "error, file \"" + cacheSettingsGenerals[2].toString() + "/" + sound + "\" - not exist!";
    }
#endif
  if( player.state() == QMediaPlayer::PlayingState )
    return " error, melody is already playing" ;

    QStringList tmpArgs;
    cmdProgramStart[0].close();
    cmdProgramStart[1].close();

#if defined (Q_OS_WIN)
    if(!cacheSettingsGenerals[5].toString().isEmpty())
      cmdProgramStart[0].start("\"" + cacheSettingsGenerals[5].toString() + "\"");
    if(!cacheSettingsGenerals[6].toString().isEmpty())
      cmdProgramStart[1].start("\"" + cacheSettingsGenerals[6].toString() + "\"");

    tmpArgs << cacheSettingsGenerals[2].toString() + "\\" + sound;
#elif defined (Q_OS_LINUX)
    if(!cacheSettingsGenerals[5].toString().isEmpty())
       cmdProgramStart[0].start(cacheSettingsGenerals[5].toString());
    if(!cacheSettingsGenerals[6].toString().isEmpty())
      cmdProgramStart[1].start(cacheSettingsGenerals[6].toString());

    tmpArgs << cacheSettingsGenerals[2].toString() + "/" + sound;
#elif defined (Q_OS_FREEBSD)
    if(!cacheSettingsGenerals[5].toString().isEmpty())
       cmdProgramStart[0].start(cacheSettingsGenerals[5].toString());
    if(!cacheSettingsGenerals[6].toString().isEmpty())
      cmdProgramStart[1].start(cacheSettingsGenerals[6].toString());

    tmpArgs << cacheSettingsGenerals[2].toString() + "/" + sound;
#endif

    log.write(" - program 1 before call - " + cacheSettingsGenerals[5].toString());
    log.write(" - program 2 before call - " + cacheSettingsGenerals[6].toString());

    player.setMedia(QUrl::fromLocalFile(tmpArgs[0]) );
    player.setVolume(100);
    player.play();

    return tmpArgs[0];
}
bool MainWindow::callBeforeLesson(int change, int lessons)
{
    int currentDay = QDate::currentDate().dayOfWeek()-1;
    if(cacheSettingsDays[currentDay][0].toBool()){
        QTime timeTmp = QTime::fromString(pRightPanel->getLessonTimeBegin(change, lessons));
        int h = timeTmp.hour();
        int m = timeTmp.minute();
        m = m - cacheSettingsDays[currentDay][4].toInt();
        if(m < 0){
            m = m + 60;
            h = h - 1;
        }
        timeTmp.setHMS(h,m,0);
        if(QTime::currentTime().toString("hh:mm:ss") == timeTmp.toString("hh:mm:ss"))
            return true;
    }
    return false;
}
void MainWindow::startTcpServer(QString address, quint16 port)
{
    server->start(address, port);
}
void MainWindow::stopTcpServer()
{
    server->close();
}
void MainWindow::resendDataToServer()
{
    server->resendDataToServer();
}
//###################
//#     SLOTS       #
//###################
void MainWindow::slotApply()
{
    writeSettings(false);
    rightPanelSet();
    readSettingsCache();
    resendDataToServer();
}
void MainWindow::slotSaveTemplate()
{
  QString FILE_NAME = QFileDialog::getSaveFileName(this,tr("Save the template"),cacheSettingsGenerals[8].toString(),"*.bells");

  if ( !FILE_NAME.isEmpty() ){
      if( FILE_NAME.mid(FILE_NAME.length()-6) != ".bells")
          FILE_NAME.append(".bells");

      QFile out( FILE_NAME );
      if( out.open( QIODevice::WriteOnly ) ) {
          QTextStream stream( &out );
          stream.setCodec( "UTF-8 ");
          foreach (QString str, settings.allKeys()) {
              stream << str << "=" << settings.value(str).toString() << "\n";
          }
          settings.setValue("Generals_settings/path_save_and_open_file",QFileInfo(out).path().replace("/","\\"));
          cacheSettingsGenerals[8] = QFileInfo(out).path().replace("/","\\");
          out.close();
       }
  }
}
void MainWindow::slotOpen()
{
  QFileDialog openFile;
  QString tmpPath(openFile.getOpenFileName(this,tr("Open template"),cacheSettingsGenerals[8].toString(),"*.bells"));
  QFile fileOpen(tmpPath);
  if(fileOpen.open(QIODevice::ReadOnly) ){
      QApplication::setOverrideCursor(Qt::WaitCursor);
      QString tmp = settings.value("Generals_settings/path_application").toString();
      while(!fileOpen.atEnd()){
          QString line = fileOpen.readLine();
          QString key, value;
          QString spliter = "=";
          int spliterPos = line.indexOf(spliter);
          key = line.mid(0,spliterPos);
          value = line.mid(spliterPos+1);
          value.remove("\n");
          settings.setValue(key,value);
      }
      settings.setValue("Generals_settings/path_application",tmp);
      QApplication::setOverrideCursor(Qt::ArrowCursor);
      settings.setValue("Generals_settings/path_save_and_open_file",QFileInfo(fileOpen).path().replace("/","\\"));
      readSettings();
      readSettingsCache();
      rightPanelSet();
  }
  fileOpen.close();

}

void MainWindow::slotCallNow()
{
    if ( player.state() == 0){
        log.write(" - call now manual - " + callNow(cacheSettingsGenerals[0].toString()));
        return;
      }
    if ( player.state() == 1 )
        slotCallStop();
}
void MainWindow::slotCallStop()
{
    player.stop();
}
void MainWindow::slotSettingsDays()
{
    TabSettings *pSettingsWindow = new TabSettings(&player, pLeftPanel->currentTab(), server);
    pSettingsWindow->days();
    pSettingsWindow->show();
    if (pSettingsWindow->exec() == QDialog::Accepted){
        pSettingsWindow->writeSettingsDays();
        this->readSettingsCache();
        setSheduleOfDay();
        resendDataToServer();
    }
    pSettingsWindow->stopSoundDays();
    pSettingsWindow->daysDelete();
    delete pSettingsWindow;
}
void MainWindow::slotSettingsGenerals()
{
    TabSettings *pSettingsWindow = new TabSettings(&player, pLeftPanel->currentTab(), server);
    pSettingsWindow->generals();
    pSettingsWindow->show();
    if (pSettingsWindow->exec() == QDialog::Accepted){
        pSettingsWindow->writeSettingsGenerals();
        int tmpCurrerntTab = pLeftPanel->currentTab();
        this->readSettingsCache();
        for (int tabs = 0; tabs < pLeftPanel->getTabsCount(); tabs++){
            pLeftPanel->setCurrentTab(tabs);
            for (int change = 1; change < 3; change++){
                pLeftPanel->setNumbersOfLesson(tabs,\
                                               settings.value("Sheduls/shedul"+QString::number(tabs)+"/change1/#numbers_of_lessons").toInt(),\
                                               settings.value("Sheduls/shedul"+QString::number(tabs)+"/change2/#numbers_of_lessons").toInt() );
            }
        }
        pLeftPanel->setCurrentTab(tmpCurrerntTab);
    }
    pSettingsWindow->stopSoundGenerals();
    pSettingsWindow->generalsDelete();
    delete pSettingsWindow;
}
void MainWindow::slotAboutInstruction()
{
    QDesktopServices::openUrl(QUrl("https://bells.litsey-yugorsk.ru/главная/документация"));
}
void MainWindow::slotSetDateTime()
{
#if defined (Q_OS_FREEBSD)
    QMessageBox* pmbxUnix =
                        new QMessageBox(tr("Warning"),
                        tr("In Unix system you can't change time and date in this program!"),
                        QMessageBox::Warning,
                        QMessageBox::Ok,
                        QMessageBox::NoButton, QMessageBox::NoButton);
    if( pmbxUnix->exec() == QMessageBox::Ok){
        delete pmbxUnix;
        return;
    }
#endif
  QMessageBox* pmbx =
                      new QMessageBox(tr("Warning"),
                      tr("These settings change the date and time system! Continue?"),
                      QMessageBox::Information,
                      QMessageBox::Yes,
                      QMessageBox::No,QMessageBox::NoButton);
      if( pmbx->exec() == QMessageBox::Yes){
          SetDateTime *dateTime = new SetDateTime(locale);
          dateTime->show();
          if( dateTime->exec() == QDialog::Accepted ){
#if defined (Q_OS_WIN)
          SYSTEMTIME lt;
          GetLocalTime(&lt);
          lt.wDay = dateTime->getDate().day();

          if(dateTime->getDate().dayOfWeek() == 0)
              lt.wDayOfWeek = 7;
          else
            lt.wDayOfWeek = dateTime->getDate().dayOfWeek();

          lt.wMonth         = dateTime->getDate().month();
          lt.wYear          = dateTime->getDate().year();
          lt.wHour          = dateTime->getTime().hour();
          lt.wMinute        = dateTime->getTime().minute();
          lt.wSecond        = dateTime->getTime().second();
          lt.wMilliseconds  = dateTime->getTime().msec();

          if( SetLocalTime(&lt) == 0 )
              QMessageBox::information(dateTime, tr("Warning"), tr("To change the date and time you need to run a program as a local administrator!"));
#elif defined (Q_OS_LINUX)
        QString month = QString::number(dateTime->getDate().month());
        QString day   = QString::number(dateTime->getDate().day());
        QString hour  = QString::number(dateTime->getTime().hour());
        QString minute= QString::number(dateTime->getTime().minute());
        QString year  = QString::number(dateTime->getDate().year());
        QString second= QString::number(dateTime->getTime().second());

        if(month.toInt() < 10)  {month  = "0" + month;}
        if(day.toInt() < 10)    {day    = "0" + day;}
        if(hour.toInt() < 10)   {hour   = "0" + hour;}
        if(minute.toInt() < 10) {minute = "0" + minute;}
        if(second.toInt() < 10) {second = "0" + second;}

        QString date_and_time = month+day+hour+minute+year+"."+second;

    qDebug() << system(QString("gksu date "+date_and_time).toLocal8Bit() );
        Password *password = new Password(date_and_time);
    password->show();
#endif
        dateTime->close();
        }
        delete dateTime;
    }
    delete pmbx;
}
void MainWindow::slotAbout()
{
//    QDesktopServices::openUrl(QUrl("https://bells.litsey-yugorsk.ru"));

    About *about = new About();

    if (about->exec() == QDialog::Accepted){
        ;
    }
    delete about;
}
void MainWindow::slotStatusChanged(QMediaPlayer::State state)
{
  if ( state == 0 ){
      pActionCall->setIcon(QPixmap(":img/callNow.png"));
      pActionCall->setText(tr("Call"));

      log.write(" - call end");

      cmdProgramEnd[0].close();
      cmdProgramEnd[1].close();

#if defined (Q_OS_WIN)
      cmdProgramEnd[0].start("\"" + cacheSettingsGenerals[3].toString() + "\"");
      cmdProgramEnd[1].start("\"" + cacheSettingsGenerals[4].toString() + "\"");
#elif defined (Q_OS_LINUX)
      cmdProgramEnd[0].start(cacheSettingsGenerals[3].toString());
      cmdProgramEnd[1].start(cacheSettingsGenerals[4].toString());
#elif defined (Q_OS_FREEBSD)
      cmdProgramEnd[0].start(cacheSettingsGenerals[3].toString());
      cmdProgramEnd[1].start(cacheSettingsGenerals[4].toString());
#endif
      log.write(" - program 1 after call - " + cacheSettingsGenerals[3].toString());
      log.write(" - program 2 after call - " + cacheSettingsGenerals[4].toString());
      log.write(" ===============================================================");
      return;
  }
    if ( state == 1){
        pActionCall->setIcon(QPixmap(":img/callStop.png"));
        pActionCall->setText(tr("Turn the ringer off"));
        return;
    }
}
void MainWindow::slotSetLanguageRu()
{
#if defined (Q_OS_WIN)
    qtTranslator.load(cacheSettingsGenerals[9].toString()+"\\translation\\arrowpad_ru_RU");
#elif defined (Q_OS_LINUX)
    qtTranslator.load(cacheSettingsGenerals[9].toString()+"/translation/arrowpad_ru_RU");
#elif defined (Q_OS_FREEBSD)
    qtTranslator.load(cacheSettingsGenerals[9].toString()+"/translation/arrowpad_ru_RU");
#endif
    QApplication::installTranslator(&qtTranslator);
    settings.setValue("Generals_settings/language","ru_RU");
    locale = *localeRU;
    statusBarTimeLabel->setText(QDate::currentDate().toString("dd-MM-yyyy")\
                                + " - "\
                                +QTime::currentTime().toString("hh:mm:ss")\
                                + " (" + locale.dayName(QDate::currentDate().dayOfWeek()) \
                                + ")" );
}
void MainWindow::slotSetLanguageEn()
{
    QCoreApplication::removeTranslator(&qtTranslator);
    settings.setValue("Generals_settings/language","en_EN");
    locale = *localeEN;
    statusBarTimeLabel->setText(QDate::currentDate().toString("dd-MM-yyyy")\
                                + " - "\
                                +QTime::currentTime().toString("hh:mm:ss")\
                                + " (" + locale.dayName(QDate::currentDate().dayOfWeek()) \
                                + ")" );
}
void MainWindow::slotCheckDayOfWeek()
{
  if( currentDayOfWeek != QDate::currentDate().dayOfWeek() ){
      currentDayOfWeek = QDate::currentDate().dayOfWeek();
      setSheduleOfDay();
    }
}
void MainWindow::slotResetSettings()
{
  QMessageBox* pmbx =
                      new QMessageBox(tr("Warning"),
                      tr("Are you sure?"),
                      QMessageBox::Information,
                      QMessageBox::Ok,
                      QMessageBox::Cancel,QMessageBox::NoButton);
  if (pmbx->exec() == QMessageBox::Ok){
      settings.clear();
      firstStartProgram();
      readSettings();
      readSettingsCache();
      slotApply();
  }
  delete pmbx;
}
/*virtual*/void MainWindow::timerEvent(QTimerEvent*)
{
    statusBarTimeLabel->setText(QDate::currentDate().toString("dd-MM-yyyy")\
                                + " - "\
                                +QTime::currentTime().toString("hh:mm:ss")\
                                + " (" + locale.dayName(QDate::currentDate().dayOfWeek()) \
                                + ")" );
    if(cacheSettingsDays[QDate::currentDate().dayOfWeek()-1][1].toBool()){
        for(int change = 1; change < 3; change++){
            if(pRightPanel->_isTabEnabled(change))
                for(int lessons = 0; lessons < pRightPanel->getCountOfLessons(change); lessons++){
                    if(callBeforeLesson(change, lessons))
                        log.write(" - call now before lesson - "+ callNow(cacheSettingsDays[QDate::currentDate().dayOfWeek()-1][3].toString()) );
                    if(QTime::currentTime().toString("hh:mm:ss") == pRightPanel->getLessonTimeBegin         (change, lessons)+":00")
                        log.write(" - call now begin lesson - " + callNow(pRightPanel->getLessonSoundBegin  (change, lessons))     );
                    if(QTime::currentTime().toString("hh:mm:ss") == pRightPanel->getLessonTimeEnd           (change, lessons)+":00")
                        log.write(" - call now end lesson - "   + callNow(pRightPanel->getLessonSoundEnd    (change, lessons))     );
                }
        }
    }
}
void MainWindow::setSheduleOfDay()
{
  if( cacheSettingsDays[QDate::currentDate().dayOfWeek()-1][1].toBool() ){
      if( cacheSettingsDays[QDate::currentDate().dayOfWeek() - 1][5].toBool() ){
          pLeftPanel->setCurrentTab(cacheSettingsDays[QDate::currentDate().dayOfWeek() - 1][2].toInt() );
          rightPanelSet();
      }
  }
}
/*virtual*/void MainWindow::closeEvent(QCloseEvent *)
{
    log.write(" - exit program =((");
}
void MainWindow::changeEvent(QEvent *event)
{
    if (event->type() == QEvent::LanguageChange) {
        retranslate();
    } else
        QWidget::changeEvent(event);
}
