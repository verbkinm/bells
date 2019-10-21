#include "lesson_melody.h"

#define DASH "-- : --"

Dialog::Dialog(QMediaPlayer *parentPlayer) :
    QDialog(),settings("LYCEUM","Bells"),
    ui(new Ui::Dialog)
{
    nameFilter << "*.mp3" << "*.ogg" << "*.wav" << "*.mp2";

    generalPlayer = parentPlayer;

    ui->setupUi(this);

    dir.setPath( settings.value("Generals_settings/path_of_sounds_dir").toString() );

    ui->dialogBeginSound->addItem(DASH);
    ui->dialogBeginSound->addItems( dir.entryList(nameFilter, QDir::Files) );
    ui->dialogEndSound->addItem(DASH);
    ui->dialogEndSound->addItems( dir.entryList(nameFilter, QDir::Files) );

    if(generalPlayer->state() == QMediaPlayer::PlayingState){
        ui->buttonPlayStop1->setEnabled(false);
        ui->buttonPlayStop2->setEnabled(false);
    }

    beginSoundPlaying = false;
    endSoundPlaying   = false;

    connect(ui->buttonPlayStop1,          SIGNAL(clicked(bool)),                    SLOT(slotPlayStop1())                     );
    connect(ui->buttonPlayStop2,          SIGNAL(clicked(bool)),                    SLOT(slotPlayStop2())                     );

    connect(&player,                      SIGNAL(stateChanged(QMediaPlayer::State)),SLOT(slotPlayerStop(QMediaPlayer::State)) );
    connect(generalPlayer,                SIGNAL(stateChanged(QMediaPlayer::State)),SLOT(slotGeneralPlayerStop())             );
}
void Dialog::setLessonSoundBegin(QString *sound)
{
    ui->dialogBeginSound->setCurrentText(*sound);
}
void Dialog::setLessonSoundEnd(QString *sound)
{
    ui->dialogEndSound->setCurrentText(*sound);
}
const QString Dialog::getLessonSoundBegin()
{
    return ui->dialogBeginSound->currentText();
}
const QString Dialog::getLessonSoundEnd()
{
    return ui->dialogEndSound->currentText();
}
void Dialog::stopSound()
{
    player.stop();
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
void Dialog::slotPlayStop1()
{
    if( ui->dialogBeginSound->currentText() == DASH )
        return;
#if defined (Q_OS_WIN)
    QString sound = dir.path().replace("/","\\")+"\\"+ui->dialogBeginSound->currentText();
#elif defined (Q_OS_LINUX)
    QString sound = dir.path()+"/"+ui->dialogBeginSound->currentText();
#elif defined (Q_OS_FREEBSD)
    QString sound = dir.path()+"/"+ui->dialogBeginSound->currentText();
#endif
    player.setVolume(100);

    if( player.state() == QMediaPlayer::PlayingState ){
        ui->buttonPlayStop1->setIcon(QPixmap(":/img/play.png"));
        ui->buttonPlayStop2->setEnabled(true);
        player.setMedia(QUrl::fromLocalFile(sound));
        player.stop();
        return;
    }
    if( player.state() == QMediaPlayer::StoppedState ){
        beginSoundPlaying = true;
        ui->buttonPlayStop1->setIcon(QPixmap(":/img/stop.png"));
        ui->buttonPlayStop2->setEnabled(false);
        player.setMedia(QUrl::fromLocalFile(sound));
        player.play();
        return;
    }
}
void Dialog::slotPlayStop2()
{
    if( ui->dialogEndSound->currentText() == DASH )
        return;
#if defined (Q_OS_WIN)
    QString sound = dir.path().replace("/","\\")+"\\"+ui->dialogEndSound->currentText();
#elif defined (Q_OS_LINUX)
    QString sound = dir.path()+"/"+ui->dialogEndSound->currentText();
#elif defined (Q_OS_FREEBSD)
    QString sound = dir.path()+"/"+ui->dialogEndSound->currentText();
#endif

    player.setVolume(100);

    if( player.state() == QMediaPlayer::PlayingState ){
        ui->buttonPlayStop2->setIcon(QPixmap(":/img/play.png"));
        ui->buttonPlayStop1->setEnabled(true);
        player.setMedia(QUrl::fromLocalFile(sound));
        player.stop();
        return;
    }
    if( player.state() == QMediaPlayer::StoppedState ){
        endSoundPlaying = true;
        ui->buttonPlayStop2->setIcon(QPixmap(":/img/stop.png"));
        ui->buttonPlayStop1->setEnabled(false);
        player.setMedia(QUrl::fromLocalFile(sound));
        player.play();
        return;
    }
}
//###############################
//#       SLOT PLAYER STOP      #
//###############################
void Dialog::slotPlayerStop(QMediaPlayer::State state)
{
    if( state == QMediaPlayer::StoppedState ){
        player.stop();
        beginSoundPlaying = false;
        endSoundPlaying   = false;
        ui->buttonPlayStop1->setIcon(QPixmap(":/img/play.png"));
        ui->buttonPlayStop2->setIcon(QPixmap(":/img/play.png"));
        ui->buttonPlayStop1->setEnabled(true);
        ui->buttonPlayStop2->setEnabled(true);
    }
}
//###############################
//#     SLOT GENERAL PLAYER     #
//###############################
void Dialog::slotGeneralPlayerStop()
{
    if( generalPlayer->state() == QMediaPlayer::PlayingState ){
        ui->buttonPlayStop1->setEnabled(false);
        ui->buttonPlayStop2->setEnabled(false);
        player.pause();
        return;
    }
    if( generalPlayer->state() == QMediaPlayer::StoppedState )
    {
        ui->buttonPlayStop1->setEnabled(true);
        ui->buttonPlayStop2->setEnabled(true);
        if( player.state() == QMediaPlayer::PausedState )
            player.play();
        if( beginSoundPlaying )
            ui->buttonPlayStop2->setEnabled(false);
        if( endSoundPlaying )
            ui->buttonPlayStop1->setEnabled(false);
    }
}
Dialog::~Dialog()
{
    ui->dialogBeginSound->clear();
    ui->dialogEndSound->clear();
    delete ui;
}
