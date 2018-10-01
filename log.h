#ifndef LOG_H
#define LOG_H

#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <QDir>

class Log
{
public:
    Log();
    void write(QString stringLog);
};

#endif // LOG_H
