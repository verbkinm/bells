/********************************************************************************
** Form generated from reading UI file 'lesson_melody.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LESSON_MELODY_H
#define UI_LESSON_MELODY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label_2;
    QLabel *label_3;
    QComboBox *dialogBeginSound;
    QComboBox *dialogEndSound;
    QFrame *line;
    QPushButton *buttonPlayStop1;
    QPushButton *buttonPlayStop2;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->setWindowModality(Qt::ApplicationModal);
        Dialog->resize(331, 166);
        Dialog->setMinimumSize(QSize(331, 166));
        Dialog->setMaximumSize(QSize(331, 166));
        Dialog->setContextMenuPolicy(Qt::NoContextMenu);
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/ring.png"), QSize(), QIcon::Normal, QIcon::Off);
        Dialog->setWindowIcon(icon);
        Dialog->setSizeGripEnabled(false);
        Dialog->setModal(true);
        buttonBox = new QDialogButtonBox(Dialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(140, 120, 181, 32));
        buttonBox->setContextMenuPolicy(Qt::NoContextMenu);
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(true);
        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 21, 101, 21));
        label_2->setMaximumSize(QSize(16777209, 16777215));
        QFont font;
        font.setFamily(QStringLiteral("Ubuntu"));
        font.setPointSize(9);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        label_2->setFont(font);
        label_2->setContextMenuPolicy(Qt::NoContextMenu);
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_3 = new QLabel(Dialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 61, 101, 21));
        label_3->setFont(font);
        label_3->setContextMenuPolicy(Qt::NoContextMenu);
        label_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        dialogBeginSound = new QComboBox(Dialog);
        dialogBeginSound->setObjectName(QStringLiteral("dialogBeginSound"));
        dialogBeginSound->setGeometry(QRect(130, 22, 141, 23));
        dialogBeginSound->setContextMenuPolicy(Qt::NoContextMenu);
        dialogBeginSound->setIconSize(QSize(0, 0));
        dialogEndSound = new QComboBox(Dialog);
        dialogEndSound->setObjectName(QStringLiteral("dialogEndSound"));
        dialogEndSound->setGeometry(QRect(130, 62, 141, 23));
        dialogEndSound->setContextMenuPolicy(Qt::NoContextMenu);
        dialogEndSound->setIconSize(QSize(0, 0));
        dialogEndSound->setFrame(true);
        dialogEndSound->setModelColumn(0);
        line = new QFrame(Dialog);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(0, 100, 331, 16));
        line->setContextMenuPolicy(Qt::NoContextMenu);
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        buttonPlayStop1 = new QPushButton(Dialog);
        buttonPlayStop1->setObjectName(QStringLiteral("buttonPlayStop1"));
        buttonPlayStop1->setEnabled(true);
        buttonPlayStop1->setGeometry(QRect(280, 20, 26, 26));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/img/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonPlayStop1->setIcon(icon1);
        buttonPlayStop2 = new QPushButton(Dialog);
        buttonPlayStop2->setObjectName(QStringLiteral("buttonPlayStop2"));
        buttonPlayStop2->setEnabled(true);
        buttonPlayStop2->setGeometry(QRect(280, 60, 26, 26));
        buttonPlayStop2->setIcon(icon1);

        retranslateUi(Dialog);
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog, SLOT(reject()));
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog, SLOT(accept()));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Select ringtone", 0));
#ifndef QT_NO_TOOLTIP
        buttonBox->setToolTip(QApplication::translate("Dialog", "Save\\Cancel", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        buttonBox->setWhatsThis(QApplication::translate("Dialog", "Save\\Cancel", 0));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        label_2->setToolTip(QApplication::translate("Dialog", "Select a ringtone for the start of the lesson", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        label_2->setWhatsThis(QApplication::translate("Dialog", "Select a ringtone for the start of the lesson", 0));
#endif // QT_NO_WHATSTHIS
        label_2->setText(QApplication::translate("Dialog", "Beginning  lesson:", 0));
#ifndef QT_NO_TOOLTIP
        label_3->setToolTip(QApplication::translate("Dialog", "Select a ringtone for the end of the lesson", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        label_3->setWhatsThis(QApplication::translate("Dialog", "Select a ringtone for the end of the lesson", 0));
#endif // QT_NO_WHATSTHIS
        label_3->setText(QApplication::translate("Dialog", "End lesson:", 0));
#ifndef QT_NO_TOOLTIP
        dialogBeginSound->setToolTip(QApplication::translate("Dialog", "The list of available ringtones", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        dialogBeginSound->setWhatsThis(QApplication::translate("Dialog", "The list of available ringtones", 0));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        dialogEndSound->setToolTip(QApplication::translate("Dialog", "The list of available ringtones", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        dialogEndSound->setWhatsThis(QApplication::translate("Dialog", "The list of available ringtones", 0));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        buttonPlayStop1->setToolTip(QApplication::translate("Dialog", "Play\\Stop", 0));
#endif // QT_NO_TOOLTIP
        buttonPlayStop1->setText(QString());
#ifndef QT_NO_TOOLTIP
        buttonPlayStop2->setToolTip(QApplication::translate("Dialog", "Play\\Stop", 0));
#endif // QT_NO_TOOLTIP
        buttonPlayStop2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LESSON_MELODY_H
