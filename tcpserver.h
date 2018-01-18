#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

class TcpServer : public QObject
{
    Q_OBJECT
public:
    TcpServer(QObject *parent = nullptr);

    bool        start           (const QString address, int nPort);
    void        close           ();
    bool        isListening     ();
    QString     currentAddress  ();
    QString     currentPort     ();

private:
    QTcpServer* m_ptcpServer;
    quint16     m_nNextBlockSize;

    void sendToClient(QTcpSocket* pSocket, const QString& str);

signals:

public slots:
    virtual void slotNewConnection();
            void slotReadClient   ();
};

#endif // TCPSERVER_H
