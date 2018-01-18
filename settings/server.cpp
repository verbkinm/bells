#include "server.h"
#include "ui_server.h"

Server::Server(TcpServer *server, QWidget *parent) :
    QWidget(parent), settings("LYCEUM","Bells"),
    ui(new Ui::Server)
{
    ui->setupUi(this);

    pTcpServer = server;

    ui->on_or_off_server->setChecked(settings.value("Generals_settings/on_or_off_server").toBool());
    ui->start_with_program->setChecked(settings.value("Generals_settings/start_with_program").toBool());
    if(pTcpServer->isListening()){
        ui->address_listen->setText(pTcpServer->currentAddress());
        ui->port_listen->setText(pTcpServer->currentPort());
    }
    else{
        ui->address_listen->setText(settings.value("Generals_settings/address_listen").toString());
        ui->port_listen->setText(settings.value("Generals_settings/port_listen").toString());
    }

    if(server->isListening()){
        ui->status->setText(tr("started"));
        ui->start_stop_server->setIcon(QIcon(":/img/stop.png"));
    }
    else{
        ui->status->setText(tr("stopped"));
        ui->start_stop_server->setIcon(QIcon(":/img/play.png"));
    }

    if(ui->on_or_off_server)
        slot_on_or_off_server();

    connect(ui->on_or_off_server, SIGNAL(toggled(bool)), SLOT(slot_on_or_off_server()));

    connect(ui->start_stop_server, SIGNAL(clicked(bool)), SLOT(slot_start_or_stop_tcpServer()) ) ;
}

Server::~Server()
{
    delete ui;
}

void Server::writeSettings()
{
    settings.setValue("Generals_settings/on_or_off_server",ui->on_or_off_server->isChecked());
    settings.setValue("Generals_settings/address_listen",ui->address_listen->text());
    settings.setValue("Generals_settings/port_listen",ui->port_listen->text());
    settings.setValue("Generals_settings/start_with_program",ui->start_with_program->isChecked());
}
//###############################
//#       SLOT ON OR OFF SERVER #
//###############################
void Server::slot_on_or_off_server()
{
  if(!ui->on_or_off_server->isChecked()){
    ui->address_listen->setEnabled(false);
    ui->port_listen->setEnabled(false);
    ui->status->setEnabled(false);
    ui->label_address->setEnabled(false);
    ui->label_listen->setEnabled(false);
    ui->label_status->setEnabled(false);
    ui->start_stop_server->setEnabled(false);
    ui->start_with_program->setEnabled(false);
    }
  else{
      ui->address_listen->setEnabled(true);
      ui->port_listen->setEnabled(true);
      ui->status->setEnabled(true);
      ui->label_address->setEnabled(true);
      ui->label_listen->setEnabled(true);
      ui->label_status->setEnabled(true);
      ui->start_stop_server->setEnabled(true);
      ui->start_with_program->setEnabled(true);
    }
}
void Server::slot_start_or_stop_tcpServer()
{
    if(pTcpServer->isListening()){
        pTcpServer->close();
        ui->status->setText(tr("stopped"));
        ui->start_stop_server->setIcon(QIcon(":/img/play.png"));
    }
    else{
        if(pTcpServer->start(ui->address_listen->text(), ui->port_listen->text().toInt())){
            ui->status->setText(tr("started"));
            ui->start_stop_server->setIcon(QIcon(":/img/stop.png"));
            ui->address_listen->setText(pTcpServer->currentAddress());
            ui->port_listen->setText(pTcpServer->currentPort());
        }
    }
}

