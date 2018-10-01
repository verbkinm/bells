#ifndef SERVER_H
#define SERVER_H

#include <QWidget>
#include <QSettings>

#include "tcpserver/tcpserver.h"

namespace Ui {
class Server;
}

class Server : public QWidget
{
    Q_OBJECT

public:
    QSettings   settings;
    TcpServer *pTcpServer;

    Server(TcpServer *server, QWidget *parent = 0);
    ~Server();

    void writeSettings();

private:
    Ui::Server *ui;

private slots:
    void slot_on_or_off_server();
    void slot_start_or_stop_tcpServer();
};

#endif // SERVER_H
