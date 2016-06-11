#ifndef PASSWORD_H
#define PASSWORD_H

#include <QLineEdit>
#include <QDialog>

class Password : public QDialog
{
    Q_OBJECT
public:
    Password(QString &date);

    QString str, date_and_time;
    QLineEdit* pInput;

public slots:
    void showWidget();

};

#endif // PASSWORD_H
