#include "tabsettings.h"

TabSettings::TabSettings(QMediaPlayer *parentPlayer, int currentShedule) : QDialog()
{
    CurrentShedule = currentShedule;
    player = parentPlayer;
    pTabs = new QTabWidget;
    pButtonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
    pButtonBox->setToolTip(tr("Save\\Cancel"));
    pButtonBox->setWhatsThis(tr("Save\\Cancel"));

    connect(pButtonBox, SIGNAL(accepted()), SLOT(accept()) );
    connect(pButtonBox, SIGNAL(rejected()), SLOT(reject()) );
}
void TabSettings::writeSettingsDays()
{
    for( int i = 0; i < 7; i++){
        pTab_of_Day[i]->writeSettings();
    }
}
void TabSettings::days()
{
    for( int i = 0; i < 7; i++){
        pTab_of_Day[i] = new  settings(i+1, player);
    }

    pTabs->addTab(pTab_of_Day[0], tr("Mo."));
    pTabs->addTab(pTab_of_Day[1], tr("Tu."));
    pTabs->addTab(pTab_of_Day[2], tr("We."));
    pTabs->addTab(pTab_of_Day[3], tr("Th."));
    pTabs->addTab(pTab_of_Day[4], tr("Fr."));
    pTabs->addTab(pTab_of_Day[5], tr("Sa."));
    pTabs->addTab(pTab_of_Day[6], tr("Su."));

    for(int i = 0; i < 7; i++){
        pTabs->setTabToolTip(i,QDate::longDayName(i+1));
        pTabs->setTabWhatsThis(i,QDate::longDayName(i+1));
    }

    pTabs->setCurrentWidget(pTab_of_Day[QDate::currentDate().dayOfWeek()-1]);

    pLayout = new QVBoxLayout;

    pLayout->addWidget(pTabs);
    pLayout->addWidget(pButtonBox);

    this->setLayout(pLayout);
    this->setModal(true);
    this->setWindowTitle(tr("Days of the week"));
    this->setWindowIcon(QIcon(":/img/days.png"));
    this->adjustSize();
    this->setFixedSize(this->size());
}
void TabSettings::daysDelete()
{
    delete pLayout;

    for(int i = 0; i < 7; i++)
        delete pTab_of_Day[i];
}
void TabSettings::generals()
{
    pGeneralSettings = new Generals_Settings(player, CurrentShedule);
    pExecPrograms    = new ExecPrograms;
    pTabs->addTab(pGeneralSettings, tr("General"));
    pTabs->addTab(pExecPrograms,tr("Program"));

    pTabs->setTabToolTip(0,tr("General settings"));
    pTabs->setTabWhatsThis(0,tr("General settings"));
    pTabs->setTabToolTip(1,tr("Additional programs for calls"));
    pTabs->setTabWhatsThis(1,tr("Additional programs for calls"));

    pLayout = new QVBoxLayout;

    pLayout->addWidget(pTabs);
    pLayout->addWidget(pButtonBox);

    this->setLayout(pLayout);
    this->setModal(true);
    this->setWindowTitle(tr("General settings"));
    this->setWindowIcon(QIcon(":/img/settings.png"));
    this->adjustSize();
    this->setFixedSize(this->size());
}
void TabSettings::generalsDelete()
{
    delete pGeneralSettings;
    delete pExecPrograms;
    delete pLayout;
}
void TabSettings::writeSettingsGenerals()
{
    pGeneralSettings->writeSettings();
    pExecPrograms->writeSettings();
}
void TabSettings::stopSoundGenerals()
{
    pGeneralSettings->stopSound();
}
void TabSettings::stopSoundDays()
{
    for( int i = 0; i < 7; i++)
        pTab_of_Day[i]->stopSound();
}

TabSettings::~TabSettings()
{
    delete pButtonBox;
    delete pTabs;
}
