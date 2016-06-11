#include "generals_settings.h"

Generals_Settings::Generals_Settings(QMediaPlayer *parentPlayer, int currentShedule) :
    QWidget(), settings("LYCEUM","Bells"),
    ui(new Ui::Generals_Settings)
{
    generalPlayer = parentPlayer;

    nameFilter << "*.mp3" << "*.ogg" << "*.wav" << "*.mp2";

    ui->setupUi(this);

    ui->pathToSoundsDir->setText(settings.value("Generals_settings/path_of_sounds_dir").toString());

    path_of_sounds_dir.setPath(ui->pathToSoundsDir->text());

    ui->pathToSoundsDir->setToolTip(tr("Path to the directory of tunes - ") + ui->pathToSoundsDir->text());
    ui->pathToSoundsDir->setWhatsThis(tr("Path to the directory of tunes - ") + ui->pathToSoundsDir->text());

    pCountLessonChange1 = new int[(settings.value("Generals_settings/numbers_of_tabs").toInt())];
    pCountLessonChange2 = new int[(settings.value("Generals_settings/numbers_of_tabs").toInt())];

    countTabs = settings.value("Generals_settings/numbers_of_tabs").toInt();

    for (int tab = 0; tab < countTabs; tab++){
        ui->shedul->addItem(settings.value("Sheduls/shedul"+QString::number(tab)+"/name_of_shedul").toString());
        pCountLessonChange1[tab] = settings.value("Sheduls/shedul"+QString::number(tab)+"/change1/#numbers_of_lessons").toInt();
        pCountLessonChange2[tab] = settings.value("Sheduls/shedul"+QString::number(tab)+"/change2/#numbers_of_lessons").toInt();
    }
    slot_set_numbers_of_lessons(0);

    if(generalPlayer->state() == QMediaPlayer::PlayingState)
        ui->buttonPlayStop->setEnabled(false);

    connect(ui->shedul,     SIGNAL(currentIndexChanged(int)),   SLOT(slot_set_numbers_of_lessons(int))          );

    connect(ui->change_1,   SIGNAL(valueChanged(int)),          SLOT(slot_save_numbers_of_lessons_change1())    );
    connect(ui->change_2,   SIGNAL(valueChanged(int)),          SLOT(slot_save_numbers_of_lessons_change2())    );

    connect(ui->choseDir,   SIGNAL(clicked(bool)),              SLOT(slotChooseDir())                           );

    connect(ui->buttonPlayStop,          SIGNAL(clicked(bool)),      SLOT(slotPlayStop())                       );
    connect(&player,       SIGNAL(stateChanged(QMediaPlayer::State)),SLOT(slotPlayerStop(QMediaPlayer::State))  );
    connect(generalPlayer, SIGNAL(stateChanged(QMediaPlayer::State)),SLOT(slotGeneralPlayerStop())              );

    connect(ui->pathToSoundsDir, SIGNAL(textChanged(QString)),       SLOT(slotCheckDir(QString))                );

    ui->shedul->setCurrentIndex(currentShedule);

    slotCheckDir(ui->pathToSoundsDir->text());
}
void Generals_Settings::slot_save_numbers_of_lessons_change1()
{
    pCountLessonChange1[ui->shedul->currentIndex()] = ui->change_1->value();
}
void Generals_Settings::slot_save_numbers_of_lessons_change2()
{
    pCountLessonChange2[ui->shedul->currentIndex()] = ui->change_2->value();
}
void Generals_Settings::slot_set_numbers_of_lessons(int shedul)
{
    ui->change_1->setValue(pCountLessonChange1[shedul]);
    ui->change_2->setValue(pCountLessonChange2[shedul]);
}
void Generals_Settings::slotChooseDir()
{
    QString tmpPath = QFileDialog::getExistingDirectory(this,tr("Select the directory with the ringtones"),QDir::homePath());
    if( !tmpPath.isEmpty() ){
#if defined (Q_OS_WIN)
        ui->pathToSoundsDir->setText(tmpPath.replace("/","\\"));
#elif defined (Q_OS_LINUX)
        ui->pathToSoundsDir->setText(tmpPath);
#endif
        ui->manual_ring->clear();

        path_of_sounds_dir.setPath(ui->pathToSoundsDir->text());

        ui->manual_ring->addItems(path_of_sounds_dir.entryList(nameFilter, QDir::Files));
        ui->manual_ring->setCurrentText(settings.value("Generals_settings/manual_ring").toString());
    }
}
void Generals_Settings::writeSettings()
{
    settings.setValue("Generals_settings/path_of_sounds_dir",ui->pathToSoundsDir->text());
    settings.setValue("Generals_settings/manual_ring",ui->manual_ring->currentText());
    for (int tab = 0; tab < countTabs; tab++) {
        settings.setValue("Sheduls/shedul"+QString::number(tab)+"/change1/#numbers_of_lessons",pCountLessonChange1[tab]);
        settings.setValue("Sheduls/shedul"+QString::number(tab)+"/change2/#numbers_of_lessons",pCountLessonChange2[tab]);
    }
}
void Generals_Settings::stopSound()
{
    player.stop();
}

void Generals_Settings::slotPlayStop()
{
    if(ui->manual_ring->currentText().isEmpty() && player.state() == QMediaPlayer::StoppedState)
        return;
#if defined (Q_OS_WIN)
    QString sound = path_of_sounds_dir.path().replace("/","\\")+"\\"+ui->manual_ring->currentText();
#elif defined (Q_OS_LINUX)
    QString sound = path_of_sounds_dir.path()+"/"+ui->manual_ring->currentText();
#endif

  player.setVolume(100);

  if( player.state() == QMediaPlayer::PlayingState ){
      ui->buttonPlayStop->setIcon(QPixmap(":/img/play.png"));
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
void Generals_Settings::slotPlayerStop(QMediaPlayer::State state)
{
  if( state == QMediaPlayer::StoppedState ){
      player.stop();
      ui->buttonPlayStop->setIcon(QPixmap(":/img/play.png"));
  }
}
void Generals_Settings::slotGeneralPlayerStop()
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
void Generals_Settings::slotCheckDir(QString dir)
{
  QPalette paletteRed = ui->pathToSoundsDir->palette();
  QPalette paletteNorm = ui->pathToSoundsDir->palette();

  paletteRed.setColor(QPalette::Text, Qt::red);
  paletteNorm.setColor(QPalette::Text, Qt::black);
  QDir pathToSoundDir(dir);

  if(pathToSoundDir.exists()){
    ui->pathToSoundsDir->setPalette(paletteNorm);
    path_of_sounds_dir.setPath(ui->pathToSoundsDir->text());
    ui->manual_ring->clear();
    ui->manual_ring->addItems(path_of_sounds_dir.entryList(nameFilter, QDir::Files) );
    ui->manual_ring->setCurrentText(settings.value("Generals_settings/manual_ring").toString());
  }
  else{
    ui->pathToSoundsDir->setPalette(paletteRed);
    ui->manual_ring->clear();
  }
}

Generals_Settings::~Generals_Settings()
{
    delete ui;
    delete[] pCountLessonChange1;
    delete[] pCountLessonChange2;
}
