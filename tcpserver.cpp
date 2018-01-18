#include "tcpserver.h"
#include <QMessageBox>
#include <QTime>

TcpServer::TcpServer(QObject *parent) : QObject(parent)
{
    m_ptcpServer = new QTcpServer(this);

    connect(m_ptcpServer, SIGNAL(newConnection()), this, SLOT(slotNewConnection()) );
}
void TcpServer::slotNewConnection()
{
    QTcpSocket* pClientSocket = m_ptcpServer->nextPendingConnection();

    quint8 x = 65;

    sendToClient(pClientSocket, QString::number(x) );

    connect(pClientSocket, SIGNAL(disconnected()),  pClientSocket,  SLOT(deleteLater()) );
    connect(pClientSocket, SIGNAL(readyRead()),     this,           SLOT(slotReadClient()) );

}
void TcpServer::slotReadClient()
{
    QTcpSocket* pClientSocket = (QTcpSocket*)sender();
    QDataStream in(pClientSocket);
    in.setVersion(QDataStream::Qt_5_3);
    for (;;) {
        if (!m_nNextBlockSize) {
            if (pClientSocket->bytesAvailable() < (int)sizeof(quint16)) {
                break;
            }
            in >> m_nNextBlockSize;
        }

        if (pClientSocket->bytesAvailable() < m_nNextBlockSize) {
            break;
        }
        QTime   time;
        QString str;
        in >> time >> str;

        QString strMessage;// =
//            time.toString() + " " + "Client has sent - " + str;
//        m_ptxt->append(strMessage);

        m_nNextBlockSize = 0;

//        sendToClient(pClientSocket, "Server Response: Received \"" + str + "\"" );
    }
}
void TcpServer::sendToClient(QTcpSocket* pSocket, const QString& str)
{
    QByteArray  arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_3);
//    out << quint16(0) << QTime::currentTime() << str;

    out.device()->seek(0);
    out << quint16(arrBlock.size() - sizeof(quint16));

    pSocket->write(arrBlock);
}
bool TcpServer::start(const QString address, int nPort)
{
    if (!m_ptcpServer->listen(QHostAddress(address), nPort))
    {
        QMessageBox::critical(0,
                              tr("Server Error"),
                              tr("Unable to start the server: ")
                              + m_ptcpServer->errorString()
                             );
        m_ptcpServer->close();
        return false;
    }
    return true;
}
void TcpServer::close()
{
    m_ptcpServer->close();
}
bool TcpServer::isListening()
{
    return m_ptcpServer->isListening();
}
QString TcpServer::currentAddress()
{
    return m_ptcpServer->serverAddress().toString();
}
QString TcpServer::currentPort()
{
    return QString::number(m_ptcpServer->serverPort());
}
