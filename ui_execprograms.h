/********************************************************************************
** Form generated from reading UI file 'execprograms.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXECPROGRAMS_H
#define UI_EXECPROGRAMS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ExecPrograms
{
public:
    QLabel *label;
    QLineEdit *programStart1;
    QLabel *label_2;
    QToolButton *chooseProgramStart1;
    QToolButton *chooseProgramStart2;
    QLabel *label_3;
    QLineEdit *programStart2;
    QFrame *line;
    QLabel *label_4;
    QToolButton *chooseProgramEnd1;
    QLabel *label_5;
    QLabel *label_6;
    QToolButton *chooseProgramEnd2;
    QLineEdit *programEnd1;
    QLineEdit *programEnd2;

    void setupUi(QWidget *ExecPrograms)
    {
        if (ExecPrograms->objectName().isEmpty())
            ExecPrograms->setObjectName(QStringLiteral("ExecPrograms"));
        ExecPrograms->resize(400, 230);
        ExecPrograms->setMinimumSize(QSize(400, 230));
        ExecPrograms->setMaximumSize(QSize(400, 230));
        label = new QLabel(ExecPrograms);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 351, 16));
        programStart1 = new QLineEdit(ExecPrograms);
        programStart1->setObjectName(QStringLiteral("programStart1"));
        programStart1->setGeometry(QRect(40, 40, 321, 23));
        programStart1->setReadOnly(false);
        programStart1->setClearButtonEnabled(true);
        label_2 = new QLabel(ExecPrograms);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 40, 41, 21));
        chooseProgramStart1 = new QToolButton(ExecPrograms);
        chooseProgramStart1->setObjectName(QStringLiteral("chooseProgramStart1"));
        chooseProgramStart1->setGeometry(QRect(370, 40, 23, 22));
        chooseProgramStart2 = new QToolButton(ExecPrograms);
        chooseProgramStart2->setObjectName(QStringLiteral("chooseProgramStart2"));
        chooseProgramStart2->setGeometry(QRect(370, 70, 23, 22));
        label_3 = new QLabel(ExecPrograms);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 70, 41, 21));
        programStart2 = new QLineEdit(ExecPrograms);
        programStart2->setObjectName(QStringLiteral("programStart2"));
        programStart2->setGeometry(QRect(40, 70, 321, 23));
        programStart2->setReadOnly(false);
        programStart2->setClearButtonEnabled(true);
        line = new QFrame(ExecPrograms);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(0, 100, 401, 31));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        label_4 = new QLabel(ExecPrograms);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 130, 351, 16));
        chooseProgramEnd1 = new QToolButton(ExecPrograms);
        chooseProgramEnd1->setObjectName(QStringLiteral("chooseProgramEnd1"));
        chooseProgramEnd1->setGeometry(QRect(370, 160, 23, 22));
        label_5 = new QLabel(ExecPrograms);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 190, 41, 21));
        label_6 = new QLabel(ExecPrograms);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 160, 41, 21));
        chooseProgramEnd2 = new QToolButton(ExecPrograms);
        chooseProgramEnd2->setObjectName(QStringLiteral("chooseProgramEnd2"));
        chooseProgramEnd2->setGeometry(QRect(370, 190, 23, 22));
        programEnd1 = new QLineEdit(ExecPrograms);
        programEnd1->setObjectName(QStringLiteral("programEnd1"));
        programEnd1->setGeometry(QRect(40, 160, 321, 23));
        programEnd1->setReadOnly(false);
        programEnd1->setClearButtonEnabled(true);
        programEnd2 = new QLineEdit(ExecPrograms);
        programEnd2->setObjectName(QStringLiteral("programEnd2"));
        programEnd2->setGeometry(QRect(40, 190, 321, 23));
        programEnd2->setReadOnly(false);
        programEnd2->setClearButtonEnabled(true);

        retranslateUi(ExecPrograms);

        QMetaObject::connectSlotsByName(ExecPrograms);
    } // setupUi

    void retranslateUi(QWidget *ExecPrograms)
    {
        ExecPrograms->setWindowTitle(QApplication::translate("ExecPrograms", "Form", 0));
        label->setText(QApplication::translate("ExecPrograms", "Run the program before the call:", 0));
#ifndef QT_NO_TOOLTIP
        programStart1->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        label_2->setText(QApplication::translate("ExecPrograms", "#1", 0));
#ifndef QT_NO_TOOLTIP
        chooseProgramStart1->setToolTip(QApplication::translate("ExecPrograms", "Program selection", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        chooseProgramStart1->setWhatsThis(QApplication::translate("ExecPrograms", "Program selection", 0));
#endif // QT_NO_WHATSTHIS
        chooseProgramStart1->setText(QApplication::translate("ExecPrograms", "...", 0));
#ifndef QT_NO_TOOLTIP
        chooseProgramStart2->setToolTip(QApplication::translate("ExecPrograms", "Program selection", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        chooseProgramStart2->setWhatsThis(QApplication::translate("ExecPrograms", "Program selection", 0));
#endif // QT_NO_WHATSTHIS
        chooseProgramStart2->setText(QApplication::translate("ExecPrograms", "...", 0));
        label_3->setText(QApplication::translate("ExecPrograms", "#2", 0));
        label_4->setText(QApplication::translate("ExecPrograms", "Run the program after the call:", 0));
#ifndef QT_NO_TOOLTIP
        chooseProgramEnd1->setToolTip(QApplication::translate("ExecPrograms", "Program selection", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        chooseProgramEnd1->setWhatsThis(QApplication::translate("ExecPrograms", "Program selection", 0));
#endif // QT_NO_WHATSTHIS
        chooseProgramEnd1->setText(QApplication::translate("ExecPrograms", "...", 0));
        label_5->setText(QApplication::translate("ExecPrograms", "#2", 0));
        label_6->setText(QApplication::translate("ExecPrograms", "#1", 0));
#ifndef QT_NO_TOOLTIP
        chooseProgramEnd2->setToolTip(QApplication::translate("ExecPrograms", "Program selection", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        chooseProgramEnd2->setWhatsThis(QApplication::translate("ExecPrograms", "Program selection", 0));
#endif // QT_NO_WHATSTHIS
        chooseProgramEnd2->setText(QApplication::translate("ExecPrograms", "...", 0));
    } // retranslateUi

};

namespace Ui {
    class ExecPrograms: public Ui_ExecPrograms {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXECPROGRAMS_H
