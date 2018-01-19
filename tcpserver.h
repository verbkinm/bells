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

    void        createDataSendArray (int length);
    void        appendDataSendArray (int lessonNumber, QString timeBegin, QString timeEnd);
    void        printDataSendArray  ();

private:
    QTcpServer* m_ptcpServer;
    quint16     m_nNextBlockSize;

    unsigned short length;

    struct lesson {
        QString begin;
        QString end;
    };

    lesson*     dataSend = 0;

    void sendToClient(QTcpSocket* pSocket, lesson* data, quint8 numbersLessons);

signals:

public slots:
    virtual void slotNewConnection();
            void slotReadClient   ();
};

#endif // TCPSERVER_H
