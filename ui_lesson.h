/********************************************************************************
** Form generated from reading UI file 'lesson.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LESSON_H
#define UI_LESSON_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_lesson
{
public:
    QWidget *verticalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *lessonNumber;
    QTimeEdit *lessonBegin;
    QLabel *label;
    QTimeEdit *lessonEnd;
    QPushButton *lessonRing;
    QCheckBox *lessonOnOrOff;

    void setupUi(QWidget *lesson)
    {
        if (lesson->objectName().isEmpty())
            lesson->setObjectName(QStringLiteral("lesson"));
        lesson->setEnabled(true);
        lesson->resize(305, 40);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lesson->sizePolicy().hasHeightForWidth());
        lesson->setSizePolicy(sizePolicy);
        lesson->setMinimumSize(QSize(0, 0));
        lesson->setMaximumSize(QSize(9999, 9999));
        lesson->setContextMenuPolicy(Qt::NoContextMenu);
        lesson->setWindowTitle(QStringLiteral(""));
        lesson->setLayoutDirection(Qt::LeftToRight);
        lesson->setAutoFillBackground(false);
        verticalLayoutWidget = new QWidget(lesson);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 313, 53));
        horizontalLayout = new QHBoxLayout(verticalLayoutWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        lessonNumber = new QLabel(verticalLayoutWidget);
        lessonNumber->setObjectName(QStringLiteral("lessonNumber"));
        lessonNumber->setEnabled(false);
        lessonNumber->setMinimumSize(QSize(0, 0));
        lessonNumber->setMaximumSize(QSize(31, 51));
        QFont font;
        font.setPointSize(13);
        font.setBold(true);
        font.setWeight(75);
        lessonNumber->setFont(font);
        lessonNumber->setContextMenuPolicy(Qt::NoContextMenu);
        lessonNumber->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(lessonNumber);

        lessonBegin = new QTimeEdit(verticalLayoutWidget);
        lessonBegin->setObjectName(QStringLiteral("lessonBegin"));
        lessonBegin->setEnabled(false);
        lessonBegin->setMinimumSize(QSize(0, 0));
        lessonBegin->setMaximumSize(QSize(82, 32));
        QFont font1;
        font1.setPointSize(15);
        lessonBegin->setFont(font1);
        lessonBegin->setContextMenuPolicy(Qt::NoContextMenu);
        lessonBegin->setLayoutDirection(Qt::LeftToRight);
        lessonBegin->setWrapping(false);
        lessonBegin->setFrame(true);
        lessonBegin->setAlignment(Qt::AlignCenter);
        lessonBegin->setProperty("showGroupSeparator", QVariant(false));

        horizontalLayout->addWidget(lessonBegin);

        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setEnabled(false);
        label->setMaximumSize(QSize(32, 32));
        QFont font2;
        font2.setPointSize(20);
        font2.setBold(true);
        font2.setItalic(false);
        font2.setWeight(75);
        label->setFont(font2);
        label->setContextMenuPolicy(Qt::NoContextMenu);
        label->setLayoutDirection(Qt::LeftToRight);
        label->setAutoFillBackground(false);
        label->setFrameShape(QFrame::NoFrame);
        label->setScaledContents(false);
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);

        lessonEnd = new QTimeEdit(verticalLayoutWidget);
        lessonEnd->setObjectName(QStringLiteral("lessonEnd"));
        lessonEnd->setEnabled(false);
        lessonEnd->setMinimumSize(QSize(0, 0));
        lessonEnd->setMaximumSize(QSize(82, 32));
        lessonEnd->setFont(font1);
        lessonEnd->setContextMenuPolicy(Qt::NoContextMenu);
        lessonEnd->setAlignment(Qt::AlignCenter);
        lessonEnd->setCalendarPopup(false);

        horizontalLayout->addWidget(lessonEnd);

        lessonRing = new QPushButton(verticalLayoutWidget);
        lessonRing->setObjectName(QStringLiteral("lessonRing"));
        lessonRing->setEnabled(false);
        lessonRing->setMaximumSize(QSize(31, 31));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(210, 211, 223, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 255, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(232, 233, 239, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(105, 105, 111, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(140, 141, 149, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush3);
        QBrush brush6(QColor(255, 255, 220, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        lessonRing->setPalette(palette);
        lessonRing->setContextMenuPolicy(Qt::NoContextMenu);
        lessonRing->setToolTipDuration(-1);
        lessonRing->setAutoFillBackground(false);
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/ring.png"), QSize(), QIcon::Normal, QIcon::Off);
        lessonRing->setIcon(icon);
        lessonRing->setIconSize(QSize(20, 20));

        horizontalLayout->addWidget(lessonRing);

        lessonOnOrOff = new QCheckBox(verticalLayoutWidget);
        lessonOnOrOff->setObjectName(QStringLiteral("lessonOnOrOff"));
        lessonOnOrOff->setMaximumSize(QSize(61, 16));
        lessonOnOrOff->setContextMenuPolicy(Qt::NoContextMenu);
        lessonOnOrOff->setChecked(false);
        lessonOnOrOff->setTristate(false);

        horizontalLayout->addWidget(lessonOnOrOff);


        retranslateUi(lesson);

        QMetaObject::connectSlotsByName(lesson);
    } // setupUi

    void retranslateUi(QWidget *lesson)
    {
#ifndef QT_NO_WHATSTHIS
        verticalLayoutWidget->setWhatsThis(QApplication::translate("lesson", "ON\\OFF calls for this lesson", 0));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        lessonNumber->setToolTip(QApplication::translate("lesson", "Number of lesson", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        lessonNumber->setWhatsThis(QApplication::translate("lesson", "ON\\OFF calls for this lesson", 0));
#endif // QT_NO_WHATSTHIS
        lessonNumber->setText(QApplication::translate("lesson", "X", 0));
#ifndef QT_NO_TOOLTIP
        lessonBegin->setToolTip(QApplication::translate("lesson", "The beginning time of the lesson", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        lessonBegin->setWhatsThis(QApplication::translate("lesson", "ON\\OFF calls for this lesson", 0));
#endif // QT_NO_WHATSTHIS
        lessonBegin->setDisplayFormat(QApplication::translate("lesson", "HH:mm", 0));
#ifndef QT_NO_WHATSTHIS
        label->setWhatsThis(QApplication::translate("lesson", "ON\\OFF calls for this lesson", 0));
#endif // QT_NO_WHATSTHIS
        label->setText(QApplication::translate("lesson", ":", 0));
#ifndef QT_NO_TOOLTIP
        lessonEnd->setToolTip(QApplication::translate("lesson", "The end time of the lesson", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        lessonEnd->setWhatsThis(QApplication::translate("lesson", "ON\\OFF calls for this lesson", 0));
#endif // QT_NO_WHATSTHIS
        lessonEnd->setDisplayFormat(QApplication::translate("lesson", "HH:mm", 0));
#ifndef QT_NO_TOOLTIP
        lessonRing->setToolTip(QApplication::translate("lesson", "Selection of melodies for start and end of the lesson", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        lessonRing->setWhatsThis(QApplication::translate("lesson", "ON\\OFF calls for this lesson", 0));
#endif // QT_NO_WHATSTHIS
        lessonRing->setText(QString());
#ifndef QT_NO_TOOLTIP
        lessonOnOrOff->setToolTip(QApplication::translate("lesson", "ON\\OFF calls for this lesson", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        lessonOnOrOff->setWhatsThis(QApplication::translate("lesson", "ON\\OFF calls for this lesson", 0));
#endif // QT_NO_WHATSTHIS
        lessonOnOrOff->setText(QApplication::translate("lesson", "ON", 0));
        Q_UNUSED(lesson);
    } // retranslateUi

};

namespace Ui {
    class lesson: public Ui_lesson {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LESSON_H
