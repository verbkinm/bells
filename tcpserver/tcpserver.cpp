#include "tcpserver.h"
#include <QMessageBox>
#include <QTime>

TcpServer::TcpServer(QObject *parent) : QObject(parent)
{
    m_ptcpServer = new QTcpServer(this);

    connect(m_ptcpServer, SIGNAL(newConnection()), this, SLOT(slotNewConnection()) );
    connect(&timerDataResend, SIGNAL(timeout()), this, SLOT(slotDataResend()));

    timerDataResend.start(4000);
}
void TcpServer::slotNewConnection()
{
    QTcpSocket* pClientSocket = m_ptcpServer->nextPendingConnection();
    clientsList << pClientSocket;
    qDebug() << pClientSocket->peerAddress() << pClientSocket->peerPort() << pClientSocket->peerName();

    connect(pClientSocket, SIGNAL(disconnected()),  this,   SLOT(disconnectClient()) );
//    connect(pClientSocket, SIGNAL(readyRead()),     this,   SLOT(slotReadClient()) );

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

}
void TcpServer::slotDataResend()
{
    foreach (QTcpSocket* client, clientsList) {
        pingClient(client);
    }
}
void TcpServer::pingClient(QTcpSocket *pSocket)
{
    QByteArray  arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_3);

    int typeData = 1;
    out <<typeData;

    pSocket->write(arrBlock);
}
void TcpServer::sendToClient(QTcpSocket* pSocket)
{
    QByteArray  arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_3);

    int typeData = 0;
    out << typeData;
    dataClass.send(out);

    pSocket->write(arrBlock);
}
void TcpServer::resendDataToServer()
{
    foreach (QTcpSocket* pClientSocket, clientsList) {
        sendToClient(pClientSocket);
        qDebug() << pClientSocket->peerAddress() << pClientSocket->peerPort() << pClientSocket->peerName();
    }
}
bool TcpServer::start(const QString address, quint16 nPort)
{
    if (!m_ptcpServer->listen(QHostAddress(address), nPort))
    {
        QMessageBox::critical(nullptr,
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
void TcpServer::createDataSendArray(bool changeOneEnable, int length1, bool changeTwoEnable, int length2)
{
    dataClass.createDataSendArray(changeOneEnable, length1, changeTwoEnable, length2);
}
void TcpServer::appendDataSendArray(int change, int lessonNumber, QString timeBegin, QString timeEnd, bool lessonEnable)
{
    dataClass.appendDataSendArray(change, lessonNumber, timeBegin, timeEnd, lessonEnable);
}
void TcpServer::printDataSendArray()
{
    dataClass.printDataSendArray();
}
