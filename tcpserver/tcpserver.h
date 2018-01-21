#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QTime>

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

private:
    QTcpServer* m_ptcpServer;
    quint16     m_nNextBlockSize;

    DataToSend  dataClass;

    void sendToClient(QTcpSocket* pSocket);

signals:

public slots:
    virtual void slotNewConnection();
            void slotReadClient   ();
};

#endif // TCPSERVER_H