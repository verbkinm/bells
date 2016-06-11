#include "lesson.h"

#define dash "-- : --"

lesson::lesson(QMediaPlayer *parentPlayer, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::lesson)
{
    lessonSoundBegin    = dash;
    lessonSoundEnd      = dash;

    generalPlayer       = parentPlayer;

    ui->setupUi(this);

    layout = new QHBoxLayout;
    vLayout = new QVBoxLayout;

    layout->addWidget(ui->lessonNumber);
    layout->addWidget(ui->lessonBegin);
    layout->addWidget(ui->label);
    layout->addWidget(ui->lessonEnd);
    layout->addWidget(ui->lessonRing);
    layout->addWidget(ui->lessonOnOrOff);

    vLayout->addLayout(layout);

    this->setLayout(vLayout);

    vLayout->setContentsMargins(0,3,0,0);

    connect(ui->lessonRing, SIGNAL(clicked()),
            this, SLOT(slotDialogOpen()) );
    connect(ui->lessonOnOrOff, SIGNAL(stateChanged(int)),
            this, SLOT(slotOnOrOff()) );
}
void lesson::setNubmer(int number)
{
    ui->lessonNumber->setText(QString::number(number) + ":");
}
void lesson::setTimeOfLesson(QTime lessonBegin, QTime lessonEnd)
{
    ui->lessonBegin->setTime(lessonBegin);
    ui->lessonEnd->setTime(lessonEnd);
}
void lesson::setSoundsOfLesson(QString soundBegin, QString soundEnd)
{
    lessonSoundBegin    = soundBegin;
    lessonSoundEnd      = soundEnd;
}

void lesson::setDisableLesson(bool disable)
{
    ui->lessonOnOrOff->setChecked(disable);
    ui->lessonNumber->setEnabled(disable);
    ui->lessonBegin->setEnabled(disable);
    ui->label->setEnabled(disable);
    ui->lessonEnd->setEnabled(disable);
    ui->lessonRing->setEnabled(disable);
}

QString lesson::getLessonTimeBegin()
{
    if(!ui->lessonOnOrOff->isChecked()){
        return dash;
    }
    return ui->lessonBegin->time().toString("hh:mm");
}
QString lesson::getLessonTimeEnd()
{
    if(!ui->lessonOnOrOff->isChecked()){
        return dash;
    }
    return ui->lessonEnd->time().toString("hh:mm");
}
QString lesson::getLessonSoundBegin()
{
    if(!ui->lessonOnOrOff->isChecked()){
        return dash;
    }
    if(lessonSoundBegin.isEmpty())
        return dash;
    return lessonSoundBegin;
}
QString lesson::getLessonSoundEnd()
{
    if(!ui->lessonOnOrOff->isChecked()){
        return dash;
    }
    if(lessonSoundEnd.isEmpty())
        return dash;
    return lessonSoundEnd;
}
QString lesson::getLessonSoundBeginToSave()
{
    return lessonSoundBegin;
}
QString lesson::getLessonSoundEndToSave()
{
    return lessonSoundEnd;
}

void lesson::slotOnOrOff()
{
    if(!ui->lessonOnOrOff->isChecked())
    {
        ui->lessonNumber->setEnabled(false);
        ui->lessonBegin->setEnabled(false);
        ui->label->setEnabled(false);
        ui->lessonEnd->setEnabled(false);
        ui->lessonRing->setEnabled(false);
        return;
    }
    else
    {
        ui->lessonNumber->setEnabled(true);
        ui->lessonBegin->setEnabled(true);
        ui->label->setEnabled(true);
        ui->lessonEnd->setEnabled(true);
        ui->lessonRing->setEnabled(true);
        return;
    }
    return;
}
void lesson::slotDialogOpen()
{
    Dialog *dialog = new Dialog(generalPlayer);

    dialog->setLessonSoundBegin(&lessonSoundBegin);
    dialog->setLessonSoundEnd(&lessonSoundEnd);

    if (dialog->exec() == QDialog::Accepted){
        lessonSoundBegin  = dialog->getLessonSoundBegin();
        lessonSoundEnd    = dialog->getLessonSoundEnd();
    }
    dialog->stopSound();
    delete dialog;
}
bool lesson::isLessonEnabled()
{
    return (ui->lessonOnOrOff->isChecked());
}
void lesson::retranslate(int numberOfLesson)
{
    ui->retranslateUi(this);
    ui->lessonNumber->setText(QString::number(numberOfLesson)+":");
}

lesson::~lesson()
{
    delete ui;
    delete layout;
    delete vLayout;
}
