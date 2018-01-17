#ifndef SERVER_H
#define SERVER_H

#include <QWidget>
#include <QSettings>

namespace Ui {
class Server;
}

class Server : public QWidget
{
    Q_OBJECT

public:
    QSettings   settings;

    Server(QWidget *parent = 0);
    ~Server();

    void writeSettings();

private:
    Ui::Server *ui;

private slots:

    void slot_on_or_off_server();
};

#endif // SERVER_H
