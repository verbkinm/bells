/********************************************************************************
** Form generated from reading UI file 'aboutprogram.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTPROGRAM_H
#define UI_ABOUTPROGRAM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_AboutProgram
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *AboutProgram)
    {
        if (AboutProgram->objectName().isEmpty())
            AboutProgram->setObjectName(QStringLiteral("AboutProgram"));
        AboutProgram->resize(520, 193);
        AboutProgram->setMinimumSize(QSize(520, 193));
        AboutProgram->setMaximumSize(QSize(520, 193));
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/lyceum.png"), QSize(), QIcon::Normal, QIcon::Off);
        AboutProgram->setWindowIcon(icon);
        AboutProgram->setModal(true);
        buttonBox = new QDialogButtonBox(AboutProgram);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(0, 160, 471, 21));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);
        label = new QLabel(AboutProgram);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(140, 20, 371, 141));
        label_2 = new QLabel(AboutProgram);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 30, 121, 111));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/img/lyceum.png")));
        label_2->setScaledContents(true);

        retranslateUi(AboutProgram);
        QObject::connect(buttonBox, SIGNAL(accepted()), AboutProgram, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AboutProgram, SLOT(reject()));

        QMetaObject::connectSlotsByName(AboutProgram);
    } // setupUi

    void retranslateUi(QDialog *AboutProgram)
    {
        AboutProgram->setWindowTitle(QApplication::translate("AboutProgram", "\320\236 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265", 0));
        label->setText(QApplication::translate("AboutProgram", "<html><head/><body><p align=\"justify\"><span style=\" font-size:12pt; font-weight:600;\">\302\253\320\250\320\272\320\276\320\273\321\214\320\275\320\276\320\265 \321\200\320\260\321\201\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\267\320\262\320\276\320\275\320\272\320\276\320\262\302\273</span></p><p align=\"justify\"><span style=\" font-family:'Arial'; font-size:medium; color:#000000;\">\320\236\321\201\320\275\320\276\320\262\320\260\320\275\320\276 \320\275\320\260\302\240Qt 5.6</span></p><p align=\"justify\"><span style=\" font-family:'Arial'; font-size:medium; color:#000000;\">\320\241\320\276\320\261\321\200\320\260\320\275\320\276 \320\262 \320\260\320\277\321\200\320\265\320\273\320\265 2016 \320\263\320\276\320\264\320\260</span></p><p align=\"justify\"><span style=\" font-family:'Arial'; font-size:medium; color:#000000;\">\320\242\320\265\321\201\321\202\320\270\321\200\320\276\320\262\320\260\320\273\320\276\321\201\321\214 \320\275\320\260\302\240Windows 7, Linux Ubuntu\302\2401"
                        "4.04,\302\240FreeBSD 10.1</span></p><p align=\"justify\"><span style=\" font-family:'Arial'; font-size:medium; color:#000000;\">\320\240\320\260\320\267\321\200\320\260\320\261\320\276\321\202\321\207\320\270\320\272\302\240\342\200\224 \320\222\320\265\321\200\320\261\320\272\320\270\320\275 \320\234\320\270\321\205\320\260\320\270\320\273 \320\241\320\265\321\200\320\263\320\265\320\265\320\262\320\270\321\207,\302\240</span><a href=\"mailto:verbkinm@yandex.ru\"><span style=\" font-family:'Arial'; font-size:medium; text-decoration: underline; color:#0000ff;\">verbkinm</span></a><a href=\"mailto:verbkinm@yandex.ru\"><span style=\" font-family:'Arial'; font-size:medium; font-style:italic; text-decoration: underline; color:#0000ff;\">@yandex.ru</span></a><br/></p></body></html>", 0));
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AboutProgram: public Ui_AboutProgram {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTPROGRAM_H
