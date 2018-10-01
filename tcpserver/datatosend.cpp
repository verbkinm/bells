#include "datatosend.h"
#include <QDataStream>
#include <QDebug>

DataToSend::DataToSend()
{

}
void DataToSend::createDataSendArray(bool changeOneEnable, int length1, bool changeTwoEnable, int length2)
{
    if(pDoubleArray != nullptr)
        for (int i = 0; i < 2; ++i)
            delete []pDoubleArray[i];

    pDoubleArray                = new lessonTime* [2];

    pDoubleArray[0]             = new lessonTime[length1];
    pDoubleArray[1]             = new lessonTime[length2];

    numbersOfLessonInChange[0]  = length1;
    numbersOfLessonInChange[1]  = length2;

    isChangesEnabled[0]         = changeOneEnable;
    isChangesEnabled[1]         = changeTwoEnable;
}
void DataToSend::appendDataSendArray(int change, int lessonNumber, QString timeBegin, QString timeEnd, bool lessonEnable)
{
//    qDebug() << change << lessonNumber << timeBegin << timeEnd;
    pDoubleArray[change-1][lessonNumber].begin          = timeBegin;
    pDoubleArray[change-1][lessonNumber].end            = timeEnd;
    pDoubleArray[change-1][lessonNumber].isLessonEnabled= lessonEnable;
}
void DataToSend::printDataSendArray()
{
    for (int i = 0; i < 2; ++i)
        for (int lessons = 0; lessons < numbersOfLessonInChange[i]; ++lessons)
            qDebug() << "Смена №" << i << isChangesEnabled[i] << " - " << pDoubleArray[i][lessons].begin << pDoubleArray[i][lessons].end << "урок " << pDoubleArray[i][lessons].isLessonEnabled;
}
void DataToSend::send(QDataStream &dataStream)
{
    for (int i = 0; i < 2; ++i){
        dataStream << /*i << */isChangesEnabled[i] << numbersOfLessonInChange[i];
        for (int j = 0; j < numbersOfLessonInChange[i]; ++j)
            dataStream << pDoubleArray[i][j].begin << pDoubleArray[i][j].end;
    }
}
