#include "tcpserver.h"
#include <QMessageBox>
#include <QTime>

TcpServer::TcpServer(QObject *parent) : QObject(parent)
{
    m_ptcpServer = new QTcpServer(this);

    connect(m_ptcpServer, SIGNAL(newConnection()), this, SLOT(slotNewConnection()) );

//    dataSend = new lesson[1];
}
void TcpServer::slotNewConnection()
{
    QTcpSocket* pClientSocket = m_ptcpServer->nextPendingConnection();

    connect(pClientSocket, SIGNAL(disconnected()),  pClientSocket,  SLOT(deleteLater()) );
    connect(pClientSocket, SIGNAL(readyRead()),     this,           SLOT(slotReadClient()) );

//    data[0].beginH  = (quint8)8;//QTime(8,30,0);
//    data[0].beginM  = (quint8)30;//QTime(9,15,0);
//    data[0].endH    = (quint8)9;
//    data[0].endM    = (quint8)15;

//    sendToClient( pClientSocket, data, (quint8)(sizeof(data)/sizeof(data[0])) );

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
void TcpServer::sendToClient(QTcpSocket* pSocket, lesson *data, quint8 numbersLessons)
{
    QByteArray  arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_3);

    out << numbersLessons;
    for (int i = 0; i < numbersLessons; ++i);
//        out << data[i].beginH << data[i].beginM << data[i].endH << data[i].endM;

//    out.device()->seek(0);
//    out << quint16(arrBlock.size() - sizeof(quint16));

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
void TcpServer::createDataSendArray(unsigned short change, unsigned short length)
{
    if(dataSendArray != 0)
        for (int i = 0; i < 2; ++i)
            delete []dataSendArray[i];

    dataSendArray = new lesson* [2];
    for (int i = 0; i < 2; ++i)
        dataSendArray[i] = new lesson[length];

    change == 1 ? lengthArray1=length : lengthArray2=length;
}
void TcpServer::appendDataSendArray(unsigned short change, unsigned short lessonNumber, QString timeBegin, QString timeEnd)
{
//    qDebug() << change << lessonNumber << timeBegin << timeEnd;

    dataSendArray[change-1][lessonNumber].begin = timeBegin;
    dataSendArray[change-1][lessonNumber].end   = timeEnd;



}
void TcpServer::printDataSendArray()
{
    //  1-я смена
    for (int lessons = 0; lessons < lengthArray1; ++lessons)
        qDebug() << dataSendArray[0][lessons].begin << dataSendArray[0][lessons].end;
    //  2-я смена
    for (int lessons = 0; lessons < lengthArray1; ++lessons)
        qDebug() << dataSendArray[1][lessons].begin << dataSendArray[0][lessons].end;
}
