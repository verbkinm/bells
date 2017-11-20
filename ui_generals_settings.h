/********************************************************************************
** Form generated from reading UI file 'generals_settings.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GENERALS_SETTINGS_H
#define UI_GENERALS_SETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Generals_Settings
{
public:
    QLabel *label;
    QComboBox *manual_ring;
    QComboBox *shedul;
    QFrame *line;
    QSpinBox *change_1;
    QSpinBox *change_2;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QToolButton *choseDir;
    QLineEdit *pathToSoundsDir;
    QLabel *label_5;
    QPushButton *buttonPlayStop;

    void setupUi(QWidget *Generals_Settings)
    {
        if (Generals_Settings->objectName().isEmpty())
            Generals_Settings->setObjectName(QStringLiteral("Generals_Settings"));
        Generals_Settings->resize(400, 230);
        Generals_Settings->setMinimumSize(QSize(400, 230));
        Generals_Settings->setMaximumSize(QSize(400, 230));
        label = new QLabel(Generals_Settings);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 80, 141, 21));
        QFont font;
        font.setPointSize(9);
        label->setFont(font);
        label->setLayoutDirection(Qt::LeftToRight);
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        manual_ring = new QComboBox(Generals_Settings);
        manual_ring->setObjectName(QStringLiteral("manual_ring"));
        manual_ring->setGeometry(QRect(210, 80, 141, 23));
        manual_ring->setMinimumSize(QSize(141, 23));
        manual_ring->setMaximumSize(QSize(141, 23));
        shedul = new QComboBox(Generals_Settings);
        shedul->setObjectName(QStringLiteral("shedul"));
        shedul->setEnabled(true);
        shedul->setGeometry(QRect(210, 130, 141, 23));
        shedul->setMinimumSize(QSize(141, 23));
        shedul->setMaximumSize(QSize(141, 23));
        line = new QFrame(Generals_Settings);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(0, 110, 401, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        change_1 = new QSpinBox(Generals_Settings);
        change_1->setObjectName(QStringLiteral("change_1"));
        change_1->setEnabled(true);
        change_1->setGeometry(QRect(210, 160, 141, 24));
        change_1->setMinimum(1);
        change_1->setMaximum(20);
        change_2 = new QSpinBox(Generals_Settings);
        change_2->setObjectName(QStringLiteral("change_2"));
        change_2->setEnabled(true);
        change_2->setGeometry(QRect(210, 190, 141, 24));
        change_2->setMinimum(1);
        change_2->setMaximum(20);
        label_2 = new QLabel(Generals_Settings);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 130, 141, 21));
        label_2->setFont(font);
        label_2->setLayoutDirection(Qt::LeftToRight);
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_3 = new QLabel(Generals_Settings);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 160, 191, 21));
        label_3->setFont(font);
        label_3->setLayoutDirection(Qt::LeftToRight);
        label_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_4 = new QLabel(Generals_Settings);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 190, 191, 21));
        label_4->setFont(font);
        label_4->setLayoutDirection(Qt::LeftToRight);
        label_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        choseDir = new QToolButton(Generals_Settings);
        choseDir->setObjectName(QStringLiteral("choseDir"));
        choseDir->setGeometry(QRect(360, 40, 23, 22));
        pathToSoundsDir = new QLineEdit(Generals_Settings);
        pathToSoundsDir->setObjectName(QStringLiteral("pathToSoundsDir"));
        pathToSoundsDir->setGeometry(QRect(20, 40, 331, 23));
        pathToSoundsDir->setClearButtonEnabled(true);
        label_5 = new QLabel(Generals_Settings);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 10, 331, 21));
        label_5->setFont(font);
        label_5->setLayoutDirection(Qt::LeftToRight);
        label_5->setAlignment(Qt::AlignCenter);
        buttonPlayStop = new QPushButton(Generals_Settings);
        buttonPlayStop->setObjectName(QStringLiteral("buttonPlayStop"));
        buttonPlayStop->setGeometry(QRect(360, 78, 26, 26));
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonPlayStop->setIcon(icon);

        retranslateUi(Generals_Settings);

        QMetaObject::connectSlotsByName(Generals_Settings);
    } // setupUi

    void retranslateUi(QWidget *Generals_Settings)
    {
        Generals_Settings->setWindowTitle(QApplication::translate("Generals_Settings", "Form", 0));
#ifndef QT_NO_TOOLTIP
        label->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        label->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        label->setText(QApplication::translate("Generals_Settings", "Manual call:", 0));
#ifndef QT_NO_TOOLTIP
        manual_ring->setToolTip(QApplication::translate("Generals_Settings", "Choosing a ringtone submitted manually", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        manual_ring->setWhatsThis(QApplication::translate("Generals_Settings", "Choosing a ringtone submitted manually", 0));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        shedul->setToolTip(QApplication::translate("Generals_Settings", "The list of existing schedules", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        shedul->setWhatsThis(QApplication::translate("Generals_Settings", "The list of existing schedules", 0));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        change_1->setToolTip(QApplication::translate("Generals_Settings", "Lessons per change #1", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        change_1->setWhatsThis(QApplication::translate("Generals_Settings", "Lessons per change #1", 0));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        change_2->setToolTip(QApplication::translate("Generals_Settings", "Lessons per change #2", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        change_2->setWhatsThis(QApplication::translate("Generals_Settings", "Lessons per change #2", 0));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        label_2->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        label_2->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        label_2->setText(QApplication::translate("Generals_Settings", "Shedule:", 0));
#ifndef QT_NO_TOOLTIP
        label_3->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        label_3->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        label_3->setText(QApplication::translate("Generals_Settings", "Lessons per change #1", 0));
#ifndef QT_NO_TOOLTIP
        label_4->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        label_4->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        label_4->setText(QApplication::translate("Generals_Settings", "Lessons per change #2", 0));
#ifndef QT_NO_TOOLTIP
        choseDir->setToolTip(QApplication::translate("Generals_Settings", "Catalog choice tunes", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        choseDir->setWhatsThis(QApplication::translate("Generals_Settings", "Catalog choice tunes", 0));
#endif // QT_NO_WHATSTHIS
        choseDir->setText(QApplication::translate("Generals_Settings", "...", 0));
#ifndef QT_NO_TOOLTIP
        pathToSoundsDir->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        label_5->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        label_5->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        label_5->setText(QApplication::translate("Generals_Settings", "The path to the directory tunes:", 0));
#ifndef QT_NO_TOOLTIP
        buttonPlayStop->setToolTip(QApplication::translate("Generals_Settings", "Play\\Stop", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        buttonPlayStop->setWhatsThis(QApplication::translate("Generals_Settings", "Play\\Stop", 0));
#endif // QT_NO_WHATSTHIS
        buttonPlayStop->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Generals_Settings: public Ui_Generals_Settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GENERALS_SETTINGS_H
