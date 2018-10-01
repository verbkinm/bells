#ifndef DATATOSEND_H
#define DATATOSEND_H

#include <QString>

class DataToSend
{
public:
    DataToSend();

    void    createDataSendArray (bool changeOneEnable, int length1, bool changeTwoEnable, int length2);
    void    appendDataSendArray (int change, int lessonNumber, QString timeBegin, QString timeEnd, bool lessonEnable);
    void    printDataSendArray  ();
    void    send                (QDataStream &dataStream);

private:

// contents protocol
// out << размер данных(quint16) << тип передаваемых данных (int 0 - send data, 1 - ping)
//    for (int i = 0; i < 2; ++i){
//      << состояние смены(bool) << кол-во уроков в смене(int)
//      for (int j = 0; j < кол-во уроков в смене[i]; ++j)
//          << начало урока(QString) << конец урока(QString)

    int numbersOfLessonInChange[2] = { 0, 0 };  //0 - 1-я смена, 1 - 2-я смена

    bool isChangesEnabled[2] = { false, false };

    struct lessonTime
    {
        bool    isLessonEnabled = false;
        QString begin = nullptr;
        QString end   = nullptr;
    };

    lessonTime**        pDoubleArray = nullptr;
};

#endif // DATATOSEND_H
