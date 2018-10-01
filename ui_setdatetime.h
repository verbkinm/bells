/********************************************************************************
** Form generated from reading UI file 'setdatetime.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETDATETIME_H
#define UI_SETDATETIME_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SetDateTime
{
public:
    QVBoxLayout *verticalLayout;
    QCalendarWidget *calendarWidget;
    QFrame *line;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *SetDateTime)
    {
        if (SetDateTime->objectName().isEmpty())
            SetDateTime->setObjectName(QStringLiteral("SetDateTime"));
        SetDateTime->resize(271, 300);
        SetDateTime->setMinimumSize(QSize(271, 300));
        SetDateTime->setMaximumSize(QSize(271, 300));
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/clock.png"), QSize(), QIcon::Normal, QIcon::Off);
        SetDateTime->setWindowIcon(icon);
        SetDateTime->setModal(true);
        verticalLayout = new QVBoxLayout(SetDateTime);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        calendarWidget = new QCalendarWidget(SetDateTime);
        calendarWidget->setObjectName(QStringLiteral("calendarWidget"));
        calendarWidget->setMinimumDate(QDate(1800, 9, 14));
        calendarWidget->setFirstDayOfWeek(Qt::Monday);
        calendarWidget->setGridVisible(true);
        calendarWidget->setHorizontalHeaderFormat(QCalendarWidget::ShortDayNames);
        calendarWidget->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);
        calendarWidget->setNavigationBarVisible(true);
        calendarWidget->setDateEditEnabled(true);

        verticalLayout->addWidget(calendarWidget);

        line = new QFrame(SetDateTime);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        buttonBox = new QDialogButtonBox(SetDateTime);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(SetDateTime);
        QObject::connect(buttonBox, SIGNAL(accepted()), SetDateTime, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SetDateTime, SLOT(reject()));

        QMetaObject::connectSlotsByName(SetDateTime);
    } // setupUi

    void retranslateUi(QDialog *SetDateTime)
    {
        SetDateTime->setWindowTitle(QApplication::translate("SetDateTime", "Setting the date and time", 0));
    } // retranslateUi

};

namespace Ui {
    class SetDateTime: public Ui_SetDateTime {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETDATETIME_H
