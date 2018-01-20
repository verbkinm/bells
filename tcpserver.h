#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QTime>

class TcpServer : public QObject
{
    Q_OBJECT
public:
    TcpServer(QObject *parent = nullptr);

    bool        start               (const QString address, int nPort);
    void        close               ();
    bool        isListening         ();

    QString     currentAddress      ();
    QString     currentPort         ();

    void        createDataSendArray (unsigned short change, unsigned short length);
    void        appendDataSendArray (unsigned short change, unsigned short lessonNumber, QString timeBegin, QString timeEnd);
    void        printDataSendArray  ();

private:
    QTcpServer* m_ptcpServer;
    quint16     m_nNextBlockSize;

    unsigned short lengthArray1;
    unsigned short lengthArray2;


    struct lesson {
        QString begin;
        QString end;
//        quint8 beginH;
//        quint8 beginM;
//        quint8 endH;
//        quint8 endM;
    };


    lesson**        dataSendArray = 0;

    void sendToClient(QTcpSocket* pSocket, lesson* data, quint8 numbersLessons);

signals:

public slots:
    virtual void slotNewConnection();
            void slotReadClient   ();
};

#endif // TCPSERVER_H
