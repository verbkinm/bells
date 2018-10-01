#ifndef EXECPROGRAMS_H
#define EXECPROGRAMS_H

#include <QWidget>
#include <QFileDialog>
#include <QSettings>
#include <QMessageBox>

#include "ui_execprograms.h"

namespace Ui {
class ExecPrograms;
}

class ExecPrograms : public QWidget
{
    Q_OBJECT

public:
    QSettings   settings;

    ExecPrograms();
    ~ExecPrograms();

    void writeSettings();
    void message();

private:
    Ui::ExecPrograms *ui;

private slots:
    void slotChooseProgramStart1    ();
    void slotChooseProgramStart2    ();

    void slotChooseProgramEnd1      ();
    void slotChooseProgramEnd2      ();

    void slotCheckFile              (QString file);
};

#endif // EXECPROGRAMS_H
