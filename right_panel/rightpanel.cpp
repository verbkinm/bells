#include "rightpanel.h"

RightPanel::RightPanel(int numbersOfLessonsChange1, int numbersOfLessonsChange2) : QFrame()//, settings("LYCEUM","Bells")
{
    pLabel = new QLabel;
    pLabel->setAlignment(Qt::AlignCenter);

    tabs = new QTabWidget;

    tabs->setTabPosition(QTabWidget::North);

    createTables(numbersOfLessonsChange1,numbersOfLessonsChange2);

    pLayout = new QVBoxLayout;
    pLayout->addWidget(pLabel);
    pLayout->addWidget(tabs);

    this->setLayout(pLayout);
    this->setLineWidth(1);
    this->setFrameStyle(QFrame::WinPanel | Sunken);
}
void RightPanel::setNumberOfShedul(QString numberOfShedul, int numberOfTab)
{
    pLabel->setText(tr("Installed: \"")+numberOfShedul+"\"");
    numberOfInstalTab = numberOfTab;
}

void RightPanel::setNumbersOfLesson(int numbersOfLessonChange1, bool enabledChange1, int numbersOfLessonChange2, bool enabledChange2)
{
    if(numbersOfLessonChange1 < 1 || numbersOfLessonChange2 < 1){
        qDebug() << "numbers_of_lessons_cange1 = " << numbersOfLessonChange1;
        qDebug() << "numbers_of_lessons_cange2 = " << numbersOfLessonChange2;
        qDebug() << "error 100";
        exit(100);
    }
    delete pTable.at(0);
    delete pTable.at(1);
    pTable.clear();

    createTables(numbersOfLessonChange1,numbersOfLessonChange2);

    tabs->tabBar()->setTabEnabled(0,enabledChange1);
    tabs->tabBar()->setTabEnabled(1,enabledChange2);
}
void RightPanel::createTables(int numbersOfLessonsChange1, int numbersOfLessonsChange2)
{
    QStringList headers;
    headers << tr("# lesson") << tr("beginning of the lesson") << tr("end of the lesson");

    pTable.push_back(new QTableWidget(numbersOfLessonsChange1*3-1,3) );
    pTable.push_back(new QTableWidget(numbersOfLessonsChange2*3-1,3) );

    for(int i = 0; i < 2; i++){
        pTable.at(i)->setHorizontalHeaderLabels(headers);
//Для маленького монитора
//        QFont font = pTable.at(i)->horizontalHeader()->font();
//        font.setPixelSize(10);
//        pTable.at(i)->horizontalHeader()->setFont(font);

        pTable.at(i)->verticalHeader()->hide();
        pTable.at(i)->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);
        pTable.at(i)->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        pTable.at(i)->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        pTable.at(i)->setEditTriggers(0);
        pTable.at(i)->setSelectionBehavior(QAbstractItemView::SelectRows);

        pTable.at(i)->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
        pTable.at(i)->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);

        for(int j = 0; j < pTable[i]->rowCount(); j++){
            pTable.at(i)->verticalHeader()->setSectionResizeMode(j, QHeaderView::Stretch);
        }
    }

    for(int tab = 0; tab < 2; tab++){
        for (int column = 0; column < pTable.at(tab)->columnCount(); column++){
            for (int row = 0; row < pTable.at(tab)->rowCount(); row++){
                pTable.at(tab)->setItem(row,column,new QTableWidgetItem);
                pTable.at(tab)->item(row,column)->setTextAlignment(Qt::AlignCenter);
            }
        }
    }
    for (int tab = 0; tab < 2; tab++){
        for(int column = 0; column < pTable.at(tab)->columnCount(); column++){
            int numberOfLesson = 0;
            for (int row = 0; row < pTable.at(tab)->rowCount();){
                pTable.at(tab)->item(row,0)->setText(QString::number(numberOfLesson)+":");
                pTable.at(tab)->item(row,column)->setBackground(Qt::lightGray);

                pTable.at(tab)->item(row+1,0)->setText(tr("melody:"));

                if(row+2 == pTable.at(tab)->rowCount()){break;}
                pTable.at(tab)->item(row+2,0)->setText(tr("break:"));
                pTable.at(tab)->setSpan(row+2,1, 1,2);

                numberOfLesson += 1;
                row += 3;
            }
        }
    }

    tabs->addTab(pTable.at(0), tr("Change #1"));
    tabs->tabBar()->setTabToolTip(0,tr("Change #1"));
    tabs->addTab(pTable.at(1), tr("Change #2"));
    tabs->tabBar()->setTabToolTip(1,tr("Change #2"));
}
void RightPanel::setLesson(int change, int numberOfLesson, QString timeBegin, QString timeEnd, QString soundBegin, QString soundEnd)
{
    if(change < 1 || change > 2){
        qDebug() << "error 101 \nchange = " << change;
        exit(102);
    }
    change = change - 1;

    pTable.at(change)->item(numberOfLesson * 3, 1)->setText(timeBegin);
    pTable.at(change)->item(numberOfLesson * 3, 2)->setText(timeEnd);

    pTable.at(change)->item(numberOfLesson * 3 + 1,1)->setText(soundBegin);
    pTable.at(change)->item(numberOfLesson * 3 + 1,2)->setText(soundEnd);
}
void RightPanel::setTableToolTip()
{
    for (int tab = 0; tab < pTable.length(); tab++) {
        for (int column = 0; column < pTable.at(tab)->columnCount(); column++) {
            for (int row = 0; row < pTable.at(tab)->rowCount(); row++) {
                pTable.at(tab)->item(row,column)->setToolTip(pTable.at(tab)->item(row,column)->text());
            }
        }
    }
}
void RightPanel::setRecess(int change, int lesson, QString result)
{
    pTable.at(change-1)->item(lesson*3+2,1)->setText(result);
}
int RightPanel::getCountOfLessons(int change)
{
    correctChange(change);
    return pTable.at(change-1)->rowCount()/3+1;
}
QString RightPanel::getLessonTimeBegin(int change, int numberOfLesson)
{
    correctChange(change);
    return pTable.at(change-1)->item(numberOfLesson * 3, 1)->text();
}
QString RightPanel::getLessonTimeEnd(int change, int numberOfLesson)
{
    correctChange(change);
    return pTable.at(change-1)->item(numberOfLesson * 3, 2)->text();
}
QString RightPanel::getLessonSoundBegin(int change, int numberOfLesson)
{
    correctChange(change);
    return pTable.at(change-1)->item(numberOfLesson * 3 + 1,1)->text();
}
QString RightPanel::getLessonSoundEnd(int change, int numberOfLesson)
{
    correctChange(change);
    return pTable.at(change-1)->item(numberOfLesson * 3 + 1,2)->text();
}
int RightPanel::getNumberOfInstalTab()
{
  return numberOfInstalTab;
}

void RightPanel::correctChange(int change)
{
    if(change > 2 || change < 1){
        qDebug() << "error 101  change = " << change;
        exit(101);
    }
}
bool RightPanel::_isTabEnabled(int change)
{
    if(this->tabs->isTabEnabled(change - 1))
        return true;
    return false;
}

RightPanel::~RightPanel()
{
    delete pTable.takeFirst();
    delete pTable.takeLast();
}
