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
    clientsList << pClientSocket;
    qDebug() << pClientSocket->peerAddress() << pClientSocket->peerPort() << pClientSocket->peerName();

    connect(pClientSocket, SIGNAL(disconnected()),  this,   SLOT(disconnectClient()) );
    connect(pClientSocket, SIGNAL(readyRead()),     this,   SLOT(slotReadClient()) );

    sendToClient(pClientSocket);

}
void TcpServer::disconnectClient()
{
    QTcpSocket *pClientSocket = qobject_cast<QTcpSocket *>(QObject::sender());

    int idx = clientsList.indexOf(pClientSocket);
    if (idx!=-1)
        clientsList.removeAt(idx);

    pClientSocket->deleteLater();

    qDebug() << clientsList.size();
}
void TcpServer::slotReadClient()
{
//    QTcpSocket* pClientSocket = (QTcpSocket*)sender();
//    QDataStream in(pClientSocket);
//    in.setVersion(QDataStream::Qt_5_3);
//    for (;;) {
//        if (!m_nNextBlockSize) {
//            if (pClientSocket->bytesAvailable() < (int)sizeof(quint16)) {
//                break;
//            }
//            in >> m_nNextBlockSize;
//        }

//        if (pClientSocket->bytesAvailable() < m_nNextBlockSize) {
//            break;
//        }
//        QTime   time;
//        QString str;
//        in >> time >> str;

//        QString strMessage;// =
////            time.toString() + " " + "Client has sent - " + str;
////        m_ptxt->append(strMessage);

//        m_nNextBlockSize = 0;

////        sendToClient(pClientSocket, "Server Response: Received \"" + str + "\"" );
//    }
}
void TcpServer::sendToClient(QTcpSocket* pSocket)
{
    QByteArray  arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);
//    qDebug() << "send address = " << &out;
    out.setVersion(QDataStream::Qt_5_3);

//    out << quint16(0);
    dataClass.send(out);

//    out.device()->seek(0);
//    out << quint16(arrBlock.size() - sizeof(quint16));

    pSocket->write(arrBlock);

//    qDebug() << quint16(arrBlock.size() - sizeof(quint16));
//    qDebug() << quint16(arrBlock.size());
}
void TcpServer::resendDataToServer()
{
    qDebug() << "resendDataToServer";
    foreach (QTcpSocket* pClientSocket, clientsList) {
        sendToClient(pClientSocket);
        qDebug() << pClientSocket->peerAddress() << pClientSocket->peerPort() << pClientSocket->peerName();
    }
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
    foreach (QTcpSocket* pClientSocket, clientsList){
        int idx = clientsList.indexOf(pClientSocket);
        if (idx!=-1)
            clientsList.removeAt(idx);
        pClientSocket->deleteLater();
    }

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
void TcpServer::createDataSendArray(bool changeOneEnable, unsigned short length1, bool changeTwoEnable, unsigned short length2)
{
    dataClass.createDataSendArray(changeOneEnable, length1, changeTwoEnable, length2);
}
void TcpServer::appendDataSendArray(unsigned short change, unsigned short lessonNumber, QString timeBegin, QString timeEnd, bool lessonEnable)
{
    dataClass.appendDataSendArray(change, lessonNumber, timeBegin, timeEnd, lessonEnable);
}
void TcpServer::printDataSendArray()
{
    dataClass.printDataSendArray();
}
