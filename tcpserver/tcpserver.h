#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QTime>
#include <QTimer>

#include "datatosend.h"

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

    void        createDataSendArray (bool changeOneEnable, unsigned short length1, bool changeTwoEnable, unsigned short length2);
    void        appendDataSendArray (unsigned short change, unsigned short lessonNumber, QString timeBegin, QString timeEnd, bool lessonEnable);
    void        printDataSendArray  ();

    void        resendDataToServer  ();

private:
    QTcpServer* m_ptcpServer;
    quint16     m_nNextBlockSize;

    DataToSend  dataClass;

    QList<QTcpSocket*>  clientsList;
    QTimer      timerDataResend;

    void        sendToClient        (QTcpSocket* pSocket);
    void        pingClient          (QTcpSocket* pSocket);
signals:

private slots:
    virtual void slotNewConnection  ();
            void slotReadClient     ();
            void disconnectClient   ();
            void slotDataResend     ();

};

#endif // TCPSERVER_H
