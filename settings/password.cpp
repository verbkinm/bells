#include "password.h"
#include <QGridLayout>
#include <QPushButton>
#include <QDesktopWidget>
#include <QLineEdit>
#include <QLabel>
#include <QMessageBox>

Password::Password(QString &date) : QDialog()
{
    date_and_time = date;
    this->setFixedSize(250, 100);
    this->setWindowTitle(tr("Authentication"));

    QPushButton* pOk = new QPushButton("OK");
    QPushButton* pCancel = new QPushButton("Cancel");

    pInput = new QLineEdit;
    pInput->setEchoMode(QLineEdit::Password);
    pInput->setAlignment(Qt::AlignCenter);

    QGridLayout* pLayout = new QGridLayout;
    pLayout->addWidget(pInput, 0,0,1,0);
    pLayout->addWidget(pOk, 1,0);
    pLayout->addWidget(pCancel, 1,1);

    this->setLayout(pLayout);

    pInput->setFocus();

    connect( pOk, SIGNAL(clicked()), SLOT(showWidget()) );
    connect( pCancel, SIGNAL(clicked()), SLOT(close()) );

    this->setModal(true);
}
void Password::showWidget()
{
    pInput->setEchoMode(QLineEdit::Normal);
    str = pInput->displayText();

    QString  string = "echo '" + str + "' | sudo -S cat /etc/shadow";
    const char *ptr = string.toUtf8().constData(); //t.toAscii().constData();

    int i = system(ptr);
    if( i != 0)
    {
        QMessageBox* msgBox = new QMessageBox;
        msgBox->setText(tr("You input wrong password!"));
        msgBox->setStandardButtons(QMessageBox::Ok);
        msgBox->setDefaultButton(QMessageBox::Ok);
        pInput->setEchoMode(QLineEdit::Password);
        msgBox->show();
        return;
    }
    QString  exec = "echo '" + str + "' | sudo -S date "+date_and_time;
    const char *pset = exec.toUtf8().constData(); //t.toAscii().constData();
    system(pset);
    this->close();
}
