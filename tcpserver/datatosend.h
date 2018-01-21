#ifndef DATATOSEND_H
#define DATATOSEND_H

#include <QString>

class DataToSend
{
public:
    DataToSend();

    void    createDataSendArray (bool changeOneEnable, unsigned short length1, bool changeTwoEnable, unsigned short length2);
    void    appendDataSendArray (unsigned short change, unsigned short lessonNumber, QString timeBegin, QString timeEnd, bool lessonEnable);
    void    printDataSendArray  ();
    void    send                (QDataStream &dataStream);

private:

// contents protocol
// out << размер данных(quint16)
//    for (int i = 0; i < 2; ++i){
//      << состояние смены(bool) << кол-во уроков в смене(int)
//      for (int j = 0; j < кол-во уроков в смене[i]; ++j)
//          << начало урока(QString) << конец урока(QString)

    unsigned short numbersOfLessonInChange[2] = { 0, 0 };  //0 - 1-я смена, 1 - 2-я смена

    bool isChangesEnabled[2] = { false, false };

    struct lessonTime
    {
        bool    isLessonEnabled = false;
        QString begin = 0;
        QString end   = 0;
    };

    lessonTime**        pDoubleArray = 0;
};

#endif // DATATOSEND_H
