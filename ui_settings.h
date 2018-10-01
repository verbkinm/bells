/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_settings
{
public:
    QSpinBox *time_before_lesson;
    QLabel *label_2;
    QCheckBox *on_or_off_day;
    QFrame *line_15;
    QComboBox *ring_before_lesson;
    QFrame *line_16;
    QCheckBox *on_or_off_before_lesson;
    QComboBox *shedul_of_day;
    QLabel *label_3;
    QCheckBox *sheduleOfDay;
    QPushButton *buttonPlayStop;

    void setupUi(QDialog *settings)
    {
        if (settings->objectName().isEmpty())
            settings->setObjectName(QStringLiteral("settings"));
        settings->resize(400, 182);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(settings->sizePolicy().hasHeightForWidth());
        settings->setSizePolicy(sizePolicy);
        settings->setMinimumSize(QSize(400, 182));
        settings->setMaximumSize(QSize(400, 182));
        settings->setSizeGripEnabled(false);
        settings->setModal(true);
        time_before_lesson = new QSpinBox(settings);
        time_before_lesson->setObjectName(QStringLiteral("time_before_lesson"));
        time_before_lesson->setGeometry(QRect(80, 140, 45, 21));
        time_before_lesson->setAlignment(Qt::AlignCenter);
        time_before_lesson->setMinimum(1);
        label_2 = new QLabel(settings);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(35, 140, 41, 21));
        label_2->setAlignment(Qt::AlignCenter);
        on_or_off_day = new QCheckBox(settings);
        on_or_off_day->setObjectName(QStringLiteral("on_or_off_day"));
        on_or_off_day->setGeometry(QRect(140, 10, 161, 31));
        line_15 = new QFrame(settings);
        line_15->setObjectName(QStringLiteral("line_15"));
        line_15->setGeometry(QRect(0, 80, 401, 31));
        line_15->setFrameShape(QFrame::HLine);
        line_15->setFrameShadow(QFrame::Sunken);
        ring_before_lesson = new QComboBox(settings);
        ring_before_lesson->setObjectName(QStringLiteral("ring_before_lesson"));
        ring_before_lesson->setGeometry(QRect(210, 140, 141, 23));
        line_16 = new QFrame(settings);
        line_16->setObjectName(QStringLiteral("line_16"));
        line_16->setGeometry(QRect(0, 30, 401, 31));
        line_16->setFrameShape(QFrame::HLine);
        line_16->setFrameShadow(QFrame::Sunken);
        on_or_off_before_lesson = new QCheckBox(settings);
        on_or_off_before_lesson->setObjectName(QStringLiteral("on_or_off_before_lesson"));
        on_or_off_before_lesson->setGeometry(QRect(30, 100, 341, 31));
        shedul_of_day = new QComboBox(settings);
        shedul_of_day->setObjectName(QStringLiteral("shedul_of_day"));
        shedul_of_day->setGeometry(QRect(210, 60, 141, 23));
        shedul_of_day->setMaxCount(10);
        shedul_of_day->setSizeAdjustPolicy(QComboBox::AdjustToContentsOnFirstShow);
        shedul_of_day->setModelColumn(0);
        label_3 = new QLabel(settings);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(130, 140, 61, 21));
        label_3->setAlignment(Qt::AlignCenter);
        sheduleOfDay = new QCheckBox(settings);
        sheduleOfDay->setObjectName(QStringLiteral("sheduleOfDay"));
        sheduleOfDay->setGeometry(QRect(30, 50, 171, 41));
        sheduleOfDay->setChecked(false);
        sheduleOfDay->setTristate(false);
        buttonPlayStop = new QPushButton(settings);
        buttonPlayStop->setObjectName(QStringLiteral("buttonPlayStop"));
        buttonPlayStop->setGeometry(QRect(360, 138, 26, 26));
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonPlayStop->setIcon(icon);

        retranslateUi(settings);

        shedul_of_day->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(settings);
    } // setupUi

    void retranslateUi(QDialog *settings)
    {
        settings->setWindowTitle(QApplication::translate("settings", "Settings", 0));
#ifndef QT_NO_TOOLTIP
        time_before_lesson->setToolTip(QApplication::translate("settings", "For how many minutes before class begins to play the melody", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        time_before_lesson->setWhatsThis(QApplication::translate("settings", "For how many minutes before class begins to play the melody", 0));
#endif // QT_NO_WHATSTHIS
        label_2->setText(QApplication::translate("settings", "Before", 0));
#ifndef QT_NO_TOOLTIP
        on_or_off_day->setToolTip(QApplication::translate("settings", "ON\\OFF calls for the this day", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        on_or_off_day->setWhatsThis(QApplication::translate("settings", "ON\\OFF calls for the this day", 0));
#endif // QT_NO_WHATSTHIS
        on_or_off_day->setText(QApplication::translate("settings", "ON\\OFF", 0));
#ifndef QT_NO_TOOLTIP
        ring_before_lesson->setToolTip(QApplication::translate("settings", "Select a melody to a lesson for N minutes", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        ring_before_lesson->setWhatsThis(QApplication::translate("settings", "Select a melody to a lesson for N minutes", 0));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        on_or_off_before_lesson->setToolTip(QApplication::translate("settings", "ON\\OFF calls before the start of the lesson for the this day", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        on_or_off_before_lesson->setWhatsThis(QApplication::translate("settings", "ON\\OFF calls before the start of the lesson for the this day", 0));
#endif // QT_NO_WHATSTHIS
        on_or_off_before_lesson->setText(QApplication::translate("settings", "Time and melody before the start of the lesson", 0));
#ifndef QT_NO_TOOLTIP
        shedul_of_day->setToolTip(QApplication::translate("settings", "Select a schedule for the this day", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        shedul_of_day->setWhatsThis(QApplication::translate("settings", "Select a schedule for the this day", 0));
#endif // QT_NO_WHATSTHIS
        label_3->setText(QApplication::translate("settings", "minutes", 0));
#ifndef QT_NO_TOOLTIP
        sheduleOfDay->setToolTip(QApplication::translate("settings", "ON\\OFF automatic selection of the schedule for the this day", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        sheduleOfDay->setWhatsThis(QApplication::translate("settings", "ON\\OFF automatic selection of the schedule for the this day", 0));
#endif // QT_NO_WHATSTHIS
        sheduleOfDay->setText(QApplication::translate("settings", "Shedule of day:", 0));
#ifndef QT_NO_TOOLTIP
        buttonPlayStop->setToolTip(QApplication::translate("settings", "Play\\Stop", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        buttonPlayStop->setWhatsThis(QApplication::translate("settings", "Play\\Stop", 0));
#endif // QT_NO_WHATSTHIS
        buttonPlayStop->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class settings: public Ui_settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
