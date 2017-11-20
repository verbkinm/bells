#include "log.h"

Log::Log()
{}
void Log::write(QString stringLog)
{
    QDir dir;
#if defined (Q_OS_WIN)
    if( !dir.exists(QDir::homePath().replace("/","\\")+"\\"+".LYCEUM\\Bells") )
        dir.mkpath(QDir::homePath().replace("/","\\")+"\\"+".LYCEUM\\Bells");
    dir.setPath(QDir::homePath().replace("/","\\")+"\\"+".LYCEUM\\Bells");
    QString fileName = dir.path()+"\\"+"bells.log";
#elif defined (Q_OS_LINUX)
    if( !dir.exists(QDir::homePath()+"/"+".LYCEUM/Bells") )
        dir.mkpath(QDir::homePath()+"/"+".LYCEUM/Bells");
    dir.setPath(QDir::homePath()+"/"+".LYCEUM/Bells");
    QString fileName = dir.path()+"/"+"bells.log";
#elif defined (Q_OS_FREEBSD)
    if( !dir.exists(QDir::homePath()+"/"+".LYCEUM/Bells") )
        dir.mkpath(QDir::homePath()+"/"+".LYCEUM/Bells");
    dir.setPath(QDir::homePath()+"/"+".LYCEUM/Bells");
    QString fileName = dir.path()+"/"+"bells.log";
#endif
    QFile log(fileName);
    log.open(QIODevice::WriteOnly | QIODevice::Append);
    if( log.size() / 1024 > 1024 * 10){
        log.close();
        QFile::rename(fileName,fileName+"-"+QDateTime::currentDateTime().toString("dd-MM-yy hh-mm-ss") );
        log.open(QIODevice::WriteOnly | QIODevice::Append);
      }
    QTextStream ts(&log);
    ts << QDateTime::currentDateTime().toString("dd.MM.yy hh:mm:ss") <<  stringLog << endl;
    log.close();
}

