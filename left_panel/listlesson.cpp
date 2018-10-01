#include "listlesson.h"

ListLesson::ListLesson(QMediaPlayer *parentPlayer, int numbers_of_lessons_cange1, int numbers_of_lessons_cange2, QWidget *parent) : QWidget(parent)
{
    generalPlayer = parentPlayer;

    if(numbers_of_lessons_cange1 < 1 || numbers_of_lessons_cange2 < 1){
        qDebug() << "ListLesson constructor:";
        qDebug() << "numbers_of_lessons_cange1 = " << numbers_of_lessons_cange1;
        qDebug() << "numbers_of_lessons_cange2 = " << numbers_of_lessons_cange2;
        qDebug() << "error 100";
        exit(100);
    }

    count1 = numbers_of_lessons_cange1;
    count2 = numbers_of_lessons_cange2;

    pVerticalLayout  = new QVBoxLayout;
    pChange1         = new QHBoxLayout;
    pChange2         = new QHBoxLayout;
//------------------------------------------------------------
    pHide_show_change1 = new QPushButton;
    pHide_show_change1->setIcon(QPixmap(":/img/expand.png"));
    pHide_show_change1->setFixedSize(20,20);
    pHide_show_change1->setToolTip(tr("hide\\show lessons in change #1"));
    pCheckbox_change1 = new QCheckBox(tr("Change #1"));
    pCheckbox_change1->setChecked(true);
    pCheckbox_change1->setToolTip(tr("On\\Off calls for change #1"));

    pChange1->setContentsMargins(5,0,0,0);
    pChange1->addWidget(pHide_show_change1);
    pChange1->addWidget(pCheckbox_change1,0,Qt::AlignCenter);
//------------------------------------------------------------
    pHide_show_change2 = new QPushButton;
    pHide_show_change2->setIcon(QPixmap(":img/expand.png"));
    pHide_show_change2->setFixedSize(20,20);
    pHide_show_change2->setToolTip(tr("hide\\show lessons in change #2"));
    pCheckbox_change2 = new QCheckBox(tr("Change #2"));
    pCheckbox_change2->setChecked(true);
    pCheckbox_change2->setToolTip(tr("On\\Off calls for change #2"));

    pChange2->setContentsMargins(5,0,0,0);
    pChange2->addWidget(pHide_show_change2);
    pChange2->addWidget(pCheckbox_change2, 0, Qt::AlignCenter);
//------------------------------------------------------------
    pVerticalLayout->addLayout(pChange1);
    for(int i = 0; i < count1; i++){
        pListChange1.push_back(new lesson(generalPlayer));
        pListChange1.at(i)->setNubmer(i);
        pVerticalLayout->addWidget(pListChange1.at(i));
    }

    pVerticalLayout->addWidget(new QLabel("<hr>"));

    pVerticalLayout->addLayout(pChange2);
    for(int i = 0; i < count2; i++){
        pListChange2.push_back(new lesson(generalPlayer));
        pListChange2.at(i)->setNubmer(i);
        pVerticalLayout->addWidget(pListChange2.at(i));
    }

    this->setLayout(pVerticalLayout);

    connect(pHide_show_change1, SIGNAL(clicked(bool)), SLOT(slot_hide_change1()) );
    connect(pHide_show_change2, SIGNAL(clicked(bool)), SLOT(slot_hide_change2()) );

    connect(pCheckbox_change1,  SIGNAL(clicked(bool)), SLOT(slot_on_or_off_change1()) );
    connect(pCheckbox_change2,  SIGNAL(clicked(bool)), SLOT(slot_on_or_off_change2()) );
}
void ListLesson::setNumbersOfLesson(int numbersOfLessonChange1, int numbersOfLessonChange2)
{
    if(numbersOfLessonChange1 < 1 || numbersOfLessonChange2 < 1){
        numbersOfLessonChange1 = 1;
        numbersOfLessonChange2 = 1;
    }
//------------------------------------------------------------
    if(numbersOfLessonChange1 > pListChange1.size()){
        int tmp = numbersOfLessonChange1 - pListChange1.size();
        for(int i = 0; i < tmp; i++){
            pListChange1.push_back(new lesson(generalPlayer));
            pListChange1.back()->setNubmer(pListChange1.size()-1);
            pVerticalLayout->insertWidget(pListChange1.size(), pListChange1.back());
            if(!this->pCheckbox_change1->isChecked())
                pListChange1.back()->setEnabled(false);
            if(!this->isChangeVisible(1))
                pListChange1.back()->hide();
        }
    }
    if(numbersOfLessonChange1 < pListChange1.size()){
        int tmp = pListChange1.size() - numbersOfLessonChange1;
        for(int i = 0; i < tmp; i++)
            delete pListChange1.takeLast();
    }
//------------------------------------------------------------
    if(numbersOfLessonChange2 > pListChange2.size()){
        int tmp = numbersOfLessonChange2 - pListChange2.size();
        for(int i = 0; i < tmp; i++){
            pListChange2.push_back(new lesson(generalPlayer));
            pListChange2.back()->setNubmer(pListChange2.size()-1);
            pVerticalLayout->addWidget(pListChange2.back());
            if(!this->pCheckbox_change2->isChecked())
                pListChange2.back()->setEnabled(false);
            if(!this->isChangeVisible(2))
                pListChange2.back()->hide();
        }
    }
    if(numbersOfLessonChange2 < pListChange2.size()){
        int tmp = pListChange2.size() - numbersOfLessonChange2;
        for(int i = 0; i < tmp; i++)
            delete pListChange2.takeLast();
    }
//------------------------------------------------------------
    adjustSize();
}
void ListLesson::setDisableLesson(int change, int lesson, bool disable)
{
    if(change == 1)
        pListChange1.at(lesson)->setDisableLesson(disable);
    if(change == 2)
        pListChange2.at(lesson)->setDisableLesson(disable);
    correctChange(change);
}
void ListLesson::setDisableChange(int change, bool disable)
{
    correctChange(change);
    if(!disable){
        if(change == 1){
            pCheckbox_change1->setChecked(false);
            slot_on_or_off_change1();
        }
        if(change == 2){
            pCheckbox_change2->setChecked(false);
            slot_on_or_off_change2();
        }
    }
//------------------------------------------------------------
    if(disable){
        if(change == 1)
            pCheckbox_change1->setChecked(true);
        if(change == 2)
            pCheckbox_change2->setChecked(true);
    }
}
void ListLesson::setChangeVisible(int change, bool visibility)
{
    if(visibility){
        if(change == 1){
            if(pListChange1.at(0)->isVisible())
                return;
            if(!pListChange1.at(0)->isVisible())
                slot_hide_change1();
        }
        if(change == 2){
            if(pListChange2.at(0)->isVisible())
                return;
            if(!pListChange2.at(0)->isVisible())
                slot_hide_change2();
        }
    }
    if(!visibility){
        if(change == 1){
            if(pListChange1.at(0)->isVisible())
                slot_hide_change1();
            if(!pListChange1.at(0)->isVisible())
                return;
        }
        if(change == 2){
            if(pListChange2.at(0)->isVisible())
                slot_hide_change2();
            if(!pListChange2.at(0)->isVisible())
                return;
        }
    }
    correctChange(change);
}
void ListLesson::correctChange(int change)
{
    if(change > 2 || change < 1){
        qDebug() << "error 101  change = " << change;
        exit(101);
    }
}
void ListLesson::setTimeOfLesson(int change, int numberOfLesson, QTime lessonBegin, QTime lessonEnd)
{
    if(change == 1)
        pListChange1.at(numberOfLesson)->setTimeOfLesson(lessonBegin, lessonEnd);
    if(change == 2)
        pListChange2.at(numberOfLesson)->setTimeOfLesson(lessonBegin, lessonEnd);
    correctChange(change);
}
void ListLesson::setSoundsOfLesson(int change, int numberOfLesson, QString soundBegin, QString soundEnd)
{
    if(change == 1)
        pListChange1.at(numberOfLesson)->setSoundsOfLesson(soundBegin, soundEnd);
    if(change == 2)
        pListChange2.at(numberOfLesson)->setSoundsOfLesson(soundBegin, soundEnd);
    correctChange(change);
}
int ListLesson::getSize(int change)
{
    if(change == 1)
        return pListChange1.size();
    if(change == 2)
       return pListChange2.size();
    return -1;
}

bool ListLesson::isChangeEnabled(int change)
{
    if(change == 1)
        return pCheckbox_change1->isChecked();
    if(change == 2)
        return pCheckbox_change2->isChecked();

    return 0;
}
bool ListLesson::isChangeVisible(int change)
{
    if(change == 1)
        return pListChange1.at(0)->isVisible();
    if(change == 2)
        return pListChange2.at(0)->isVisible();
    correctChange(change);

    return 0;
}
bool ListLesson::isLessonEnabled(int change, int lesson)
{
    if(change == 1)
        return pListChange1.at(lesson)->isLessonEnabled();
    if(change == 2)
        return pListChange2.at(lesson)->isLessonEnabled();
    correctChange(change);

    return 0;
}
QString ListLesson::getLessonTimeBegin(int change, int numberOfLesson)
{
    if(change == 1)
        return pListChange1.at(numberOfLesson)->getLessonTimeBegin();
    if(change == 2)
        return pListChange2.at(numberOfLesson)->getLessonTimeBegin();
    correctChange(change);

    return 0;
}
QString ListLesson::getLessonTimeEnd(int change, int numberOfLesson)
{
    if(change == 1)
        return pListChange1.at(numberOfLesson)->getLessonTimeEnd();
    if(change == 2)
        return pListChange2.at(numberOfLesson)->getLessonTimeEnd();
    correctChange(change);

    return 0;
}
QString ListLesson::getLessonSoundBegin(int change, int numberOfLesson)
{
    if(change == 1)
        return pListChange1.at(numberOfLesson)->getLessonSoundBegin();
    if(change == 2)
        return pListChange2.at(numberOfLesson)->getLessonSoundBegin();
    correctChange(change);

    return 0;
}
QString ListLesson::getLessonSoundEnd(int change, int numberOfLesson)
{
    if(change == 1)
        return pListChange1.at(numberOfLesson)->getLessonSoundEnd();
    if(change == 2)
        return pListChange2.at(numberOfLesson)->getLessonSoundEnd();
    correctChange(change);

    return 0;
}
QString ListLesson::getLessonSoundBeginToSave(int change, int numberOfLesson)
{
    if(change == 1)
        return pListChange1.at(numberOfLesson)->getLessonSoundBeginToSave();
    if(change == 2)
        return pListChange2.at(numberOfLesson)->getLessonSoundBeginToSave();
    correctChange(change);

    return 0;
}
QString ListLesson::getLessonSoundEndToSave(int change, int numberOfLesson)
{
    if(change == 1)
        return pListChange1.at(numberOfLesson)->getLessonSoundEndToSave();
    if(change == 2)
        return pListChange2.at(numberOfLesson)->getLessonSoundEndToSave();
    correctChange(change);

    return 0;
}
void ListLesson::slot_hide_change1()
{
    if(pListChange1.at(0)->isVisible()){
        foreach (lesson* tmp, pListChange1) {tmp->hide();}
        pHide_show_change1->setIcon(QPixmap(":img/collapse.png"));
    }
    else{
        foreach (lesson* lesson, pListChange1) {lesson->setVisible(true);}
        pHide_show_change1->setIcon(QPixmap(":img/expand.png"));
    }
}
void ListLesson::slot_hide_change2()
{
    if(pListChange2.at(0)->isVisible()){
        foreach (lesson* tmp, pListChange2) {tmp->hide();}
        pHide_show_change2->setIcon(QPixmap(":img/collapse.png"));
    }
    else{
        foreach (lesson* tmp, pListChange2) {tmp->setVisible(true);}
        pHide_show_change2->setIcon(QPixmap(":img/expand.png"));
    }
}
void ListLesson::slot_on_or_off_change1()
{
    if(isTwoChangeDisable()){
        pCheckbox_change1->setChecked(true);
        QMessageBox::information(this,tr("Error"),tr("Must be enabled on at least one change!"));
        return;
    }
    if( pCheckbox_change1->isChecked()){
        foreach (lesson* tmp, pListChange1) {tmp->setEnabled(true);}
    }
    else{
        foreach (lesson* tmp, pListChange1) {tmp->setEnabled(false);}
    }
}
void ListLesson::slot_on_or_off_change2()
{
    if(isTwoChangeDisable()){
        pCheckbox_change2->setChecked(true);
        QMessageBox::information(this,tr("Error"),tr("Must be enabled on at least one change!"));
        return;
    }
    if( pCheckbox_change2->isChecked()){
        foreach (lesson* tmp, pListChange2) {tmp->setEnabled(true);}
    }
    else{
        foreach (lesson* tmp, pListChange2) {tmp->setEnabled(false);}
    }
}
bool ListLesson::isTwoChangeDisable()
{
    if( (!pCheckbox_change1->isChecked()) && (!pCheckbox_change2->isChecked()) )
        return true;
    return false;
}
void ListLesson::retranslate()
{
    pCheckbox_change1->setText(tr("Change #1"));
    pCheckbox_change1->setToolTip(tr("On\\Off calls for change #1"));
    pCheckbox_change2->setText(tr("Change #2"));
    pCheckbox_change2->setToolTip(tr("On\\Off calls for change #2"));
    pHide_show_change1->setToolTip(tr("hide\\show lessons in change #1"));
    pHide_show_change2->setToolTip(tr("hide\\show lessons in change #2"));

    for(int i = 0; i < pListChange1.length(); i++){
        pListChange1.at(i)->retranslate(i);
    }
    for(int i = 0; i < pListChange2.length(); i++){
        pListChange2.at(i)->retranslate(i);
    }
}

ListLesson::~ListLesson()
{
    for(int i = 0; i < pListChange1.size(); i++){
        delete pListChange1.takeLast();
    }
    for(int i = 0; i < pListChange2.size(); i++){
        delete pListChange2.takeLast();
    }
    delete pChange1;
    delete pChange2;
    delete pHide_show_change1;
    delete pHide_show_change2;
    delete pCheckbox_change1;
    delete pCheckbox_change2;
    delete pVerticalLayout;
}
