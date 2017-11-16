#include "settings.h"
#include <QDebug>

settings::settings(int numberOfDay, QMediaPlayer *parentPlayer) :
    QDialog(),setting("LYCEUM","Bells"),
    ui(new Ui::settings)
{
    ui->setupUi(this);

    generalPlayer = parentPlayer;

    day = numberOfDay;

    countTabs = setting.value("Generals_settings/numbers_of_tabs").toInt();

    nameFilter << "*.mp3" << "*.ogg" << "*.wav" << "*.mp2";

//on_or_off_before_lesson
    if(setting.value("Days/"+QString::number(day)+"/on_or_off_before_lesson").toBool() ){
        ui->on_or_off_before_lesson->setChecked(true);
        slot_on_or_off_before_lesson();
    }else{slot_on_or_off_before_lesson();}
//on_or_off_shedule
    if(setting.value("Days/"+QString::number(day)+"/on_or_off_shedule").toBool() ){
        ui->sheduleOfDay->setChecked(true);
        slot_on_or_off_shedule();
    }else{slot_on_or_off_shedule();    }
//on_or_off_day
    if(setting.value("Days/"+QString::number(day)+"/on_or_off_day").toBool() ){
        ui->on_or_off_day->setChecked(true);
        slot_on_or_off_day();
    }else{slot_on_or_off_day();}
//name_of_shedul
    for (int tab = 0; tab < countTabs; tab++) {
        ui->shedul_of_day->addItem(setting.value("Sheduls/shedul"+QString::number(tab)+"/name_of_shedul").toString());
    }
    ui->shedul_of_day->setCurrentIndex(setting.value("Days/"+QString::number(day)+"/shedul_of_day").toInt());
//path_of_sounds_dir
    path_of_sounds_dir.setPath(setting.value("Generals_settings/path_of_sounds_dir").toString());
    ui->ring_before_lesson->addItems(path_of_sounds_dir.entryList(nameFilter,QDir::Files) );
//time_before_lessoon
    ui->time_before_lesson->setValue(setting.value("Days/"+QString::number(day)+"/time_before_lesson").toInt());
//sound_before_lesson
    ui->ring_before_lesson->setCurrentText(setting.value("Days/"+QString::number(day)+"/sound_before_lesson").toString());

    if(generalPlayer->state() == QMediaPlayer::PlayingState)
        ui->buttonPlayStop->setEnabled(false);
    connect(ui->on_or_off_day,           SIGNAL(stateChanged(int)), SLOT(slot_on_or_off_day())           );
    connect(ui->sheduleOfDay,            SIGNAL(stateChanged(int)), SLOT(slot_on_or_off_shedule())       );
    connect(ui->on_or_off_before_lesson, SIGNAL(stateChanged(int)), SLOT(slot_on_or_off_before_lesson()) );

    connect(ui->buttonPlayStop,          SIGNAL(clicked(bool)),      SLOT(slotPlayStop())                 );
    connect(&player,       SIGNAL(stateChanged(QMediaPlayer::State)),SLOT(slotPlayerStop(QMediaPlayer::State)));
    connect(generalPlayer, SIGNAL(stateChanged(QMediaPlayer::State)),SLOT(slotGeneralPlayerStop()) );
}
void settings::writeSettings()
{
    setting.setValue("Days/"+QString::number(day)+"/on_or_off_day",ui->on_or_off_day->isChecked());
    setting.setValue("Days/"+QString::number(day)+"/on_or_off_shedule",ui->sheduleOfDay->isChecked());
    setting.setValue("Days/"+QString::number(day)+"/shedul_of_day",ui->shedul_of_day->currentIndex() );
    setting.setValue("Days/"+QString::number(day)+"/on_or_off_before_lesson",ui->on_or_off_before_lesson->isChecked());
    setting.setValue("Days/"+QString::number(day)+"/time_before_lesson",ui->time_before_lesson->value());
    setting.setValue("Days/"+QString::number(day)+"/sound_before_lesson",ui->ring_before_lesson->currentText());
}

//#########################
//#########################
//#         SLOTS         #
//#########################
//#########################
//-------------------------
//###############################
//#       SLOT PLAY AND STOP    #
//###############################
void settings::slotPlayStop()
{
    if( ui->ring_before_lesson->currentText().isEmpty() )
        return;
#if defined (Q_OS_WIN)
    QString sound = path_of_sounds_dir.path().replace("/","\\")+"\\"+ui->ring_before_lesson->currentText();
#elif defined (Q_OS_LINUX)
    QString sound = path_of_sounds_dir.path()+"/"+ui->ring_before_lesson->currentText();
#elif defined (Q_OS_UNIX)
    QString sound = path_of_sounds_dir.path()+"/"+ui->ring_before_lesson->currentText();
#endif

  player.setVolume(100);

  if( player.state() == QMediaPlayer::PlayingState ){
      ui->buttonPlayStop->setIcon(QPixmap(":/img/play.png"));
      player.setMedia(QUrl::fromLocalFile(sound));
      player.stop();
      return;
  }
  if( player.state() == QMediaPlayer::StoppedState ){
      ui->buttonPlayStop->setIcon(QPixmap(":/img/stop.png"));
      player.setMedia(QUrl::fromLocalFile(sound));
      player.play();
      return;
  }
}
//###############################
//#       SLOT PLAYER STOP      #
//###############################
void settings::slotPlayerStop(QMediaPlayer::State state)
{
  if( state == QMediaPlayer::StoppedState ){
      player.stop();
      ui->buttonPlayStop->setIcon(QPixmap(":/img/play.png"));
  }
}
//###############################
//#     SLOT GENERAL PLAYER     #
//###############################
void settings::slotGeneralPlayerStop()
{
  if( generalPlayer->state() == QMediaPlayer::PlayingState ){
    ui->buttonPlayStop->setEnabled(false);
    player.pause();
    return;
  }
  if( generalPlayer->state() == QMediaPlayer::StoppedState ){
      ui->buttonPlayStop->setEnabled(true);
      if( player.state() == QMediaPlayer::PausedState )
          player.play();
    }
}
//###############################
//#       SLOT ON OR OFF DAY    #
//###############################
void settings::slot_on_or_off_day()
{
  if(!ui->on_or_off_day->isChecked()){
    ui->sheduleOfDay->setEnabled(false);
    ui->shedul_of_day->setEnabled(false);
    ui->on_or_off_before_lesson->setEnabled(false);
    ui->label_2->setEnabled(false);
    ui->time_before_lesson->setEnabled(false);
    ui->label_3->setEnabled(false);
    ui->ring_before_lesson->setEnabled(false);
    ui->buttonPlayStop->setEnabled(false);
    }
  else{
    ui->sheduleOfDay->setEnabled(true);
    slot_on_or_off_shedule();
    ui->on_or_off_before_lesson->setEnabled(true);
    slot_on_or_off_before_lesson();
    }
}
//###############################
//# SLOT ON OR OFF SHEDULE      #
//###############################
void settings::slot_on_or_off_shedule()
{
  ui->shedul_of_day->setEnabled(ui->sheduleOfDay->isChecked());
}
//###############################
//# SLOT ON OR OFF BEFORE LESSON#
//###############################
void settings::slot_on_or_off_before_lesson()
{
    ui->label_2->setEnabled(ui->on_or_off_before_lesson->isChecked());
    ui->label_3->setEnabled(ui->on_or_off_before_lesson->isChecked());
    ui->time_before_lesson->setEnabled(ui->on_or_off_before_lesson->isChecked());
    ui->ring_before_lesson->setEnabled(ui->on_or_off_before_lesson->isChecked());
    ui->buttonPlayStop->setEnabled(ui->on_or_off_before_lesson->isChecked());
}
void settings::stopSound()
{
    player.stop();
}

settings::~settings()
{
    delete ui;
}
