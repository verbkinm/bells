#ifndef TABTEXT_H
#define TABTEXT_H

#include <QDialog>

#include "ui_tabtext.h"

namespace Ui {
class TabText;
}

class TabText : public QDialog
{
    Q_OBJECT

public:
    TabText();
    ~TabText();

    QString getText();
    void setText(QString string);

private:
    Ui::TabText *ui;
};

#endif // TABTEXT_H
