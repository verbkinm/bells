/********************************************************************************
** Form generated from reading UI file 'tabtext.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABTEXT_H
#define UI_TABTEXT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_TabText
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *TabText)
    {
        if (TabText->objectName().isEmpty())
            TabText->setObjectName(QStringLiteral("TabText"));
        TabText->resize(310, 103);
        TabText->setMinimumSize(QSize(310, 103));
        TabText->setMaximumSize(QSize(310, 103));
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/lyceum.png"), QSize(), QIcon::Normal, QIcon::Off);
        TabText->setWindowIcon(icon);
        TabText->setModal(true);
        verticalLayout = new QVBoxLayout(TabText);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(TabText);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        lineEdit = new QLineEdit(TabText);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMaxLength(50);
        lineEdit->setAlignment(Qt::AlignCenter);
        lineEdit->setDragEnabled(true);
        lineEdit->setClearButtonEnabled(true);

        verticalLayout->addWidget(lineEdit);

        buttonBox = new QDialogButtonBox(TabText);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(TabText);
        QObject::connect(buttonBox, SIGNAL(accepted()), TabText, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), TabText, SLOT(reject()));

        QMetaObject::connectSlotsByName(TabText);
    } // setupUi

    void retranslateUi(QDialog *TabText)
    {
        TabText->setWindowTitle(QApplication::translate("TabText", "The name of the tab schedule", 0));
        label->setText(QApplication::translate("TabText", "The name of the tab schedule", 0));
#ifndef QT_NO_TOOLTIP
        lineEdit->setToolTip(QApplication::translate("TabText", "Enter the caption text for the tab", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        lineEdit->setWhatsThis(QApplication::translate("TabText", "Enter the caption text for the tab", 0));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        buttonBox->setToolTip(QApplication::translate("TabText", "Save\\Cancel", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        buttonBox->setWhatsThis(QApplication::translate("TabText", "Save\\Cancel", 0));
#endif // QT_NO_WHATSTHIS
    } // retranslateUi

};

namespace Ui {
    class TabText: public Ui_TabText {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABTEXT_H
