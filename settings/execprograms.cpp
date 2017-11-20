#include "execprograms.h"

#include <QDebug>

#define path_1 tr("Path to the program #1 - ")
#define path_2 tr("Path to the program #2 - ")
#define program_selection tr("Program selection")

ExecPrograms::ExecPrograms() :
    QWidget(), settings("LYCEUM","Bells"),
    ui(new Ui::ExecPrograms)
{
    ui->setupUi(this);

    ui->programStart1->setText(settings.value("Generals_settings/program_start_1").toString());
    ui->programStart2->setText(settings.value("Generals_settings/program_start_2").toString());

    ui->programEnd1->setText(settings.value("Generals_settings/program_end_1").toString());
    ui->programEnd2->setText(settings.value("Generals_settings/program_end_2").toString());

    ui->programStart1->setToolTip   (path_1 + ui->programStart1->text()  );
    ui->programStart2->setToolTip   (path_2 + ui->programStart2->text()  );
    ui->programEnd1->setToolTip     (path_1 + ui->programEnd1->text()    );
    ui->programEnd2->setToolTip     (path_2 + ui->programEnd2->text()    );

    ui->programStart1->setWhatsThis (path_1 + ui->programStart1->text()  );
    ui->programStart2->setWhatsThis (path_2 + ui->programStart2->text()  );
    ui->programEnd1->setWhatsThis   (path_1 + ui->programEnd1->text()    );
    ui->programEnd2->setWhatsThis   (path_2 + ui->programEnd2->text()    );

    connect(ui->chooseProgramStart1, SIGNAL(clicked(bool)), SLOT(slotChooseProgramStart1()));
    connect(ui->chooseProgramStart2, SIGNAL(clicked(bool)), SLOT(slotChooseProgramStart2()));

    connect(ui->chooseProgramEnd1,   SIGNAL(clicked(bool)), SLOT(slotChooseProgramEnd1())  );
    connect(ui->chooseProgramEnd2,   SIGNAL(clicked(bool)), SLOT(slotChooseProgramEnd2())  );

    connect(ui->programStart1,       SIGNAL(textChanged(QString)), SLOT(slotCheckFile(QString)) );
    connect(ui->programStart2,       SIGNAL(textChanged(QString)), SLOT(slotCheckFile(QString)) );
    connect(ui->programEnd1,         SIGNAL(textChanged(QString)), SLOT(slotCheckFile(QString)) );
    connect(ui->programEnd2,         SIGNAL(textChanged(QString)), SLOT(slotCheckFile(QString)) );

    ui->programStart1->textChanged(ui->programStart1->text());
    ui->programStart2->textChanged(ui->programStart2->text());
    ui->programEnd1->textChanged(ui->programEnd1->text());
    ui->programEnd2->textChanged(ui->programEnd2->text());
}
void ExecPrograms::writeSettings()
{
    settings.setValue("Generals_settings/program_start_1",ui->programStart1->text());
    settings.setValue("Generals_settings/program_start_2",ui->programStart2->text());

    settings.setValue("Generals_settings/program_end_1",ui->programEnd1->text());
    settings.setValue("Generals_settings/program_end_2",ui->programEnd2->text());
}
void ExecPrograms::message()
{
    QMessageBox::information(this,tr("Attention"),tr("The choice is not right or not working properly program (file)\
                                   may cause unexpected errors operating system or computer!"));
}
void ExecPrograms::slotChooseProgramStart1()
{
    message();
    QString tmpPath = QFileDialog::getOpenFileName(this,program_selection,QDir::homePath());
    if( !tmpPath.isEmpty() ){
#if defined (Q_OS_WIN)
        ui->programStart1->setText(tmpPath.replace("/","\\"));
#elif defined (Q_OS_LINUX)
        ui->programStart1->setText(tmpPath);
#elif defined (Q_OS_FREEBSD)
        ui->programStart1->setText(tmpPath);
#endif
        ui->programStart1->setToolTip   (path_1 + ui->programStart1->text()  );
        ui->programStart1->setWhatsThis (path_1 + ui->programStart1->text()  );
    }
}
void ExecPrograms::slotChooseProgramStart2()
{
    message();
    QString tmpPath = QFileDialog::getOpenFileName(this,program_selection,QDir::homePath());
    if( !tmpPath.isEmpty() ){
#if defined (Q_OS_WIN)
        ui->programStart2->setText(tmpPath.replace("/","\\"));
#elif defined (Q_OS_LINUX)
        ui->programStart1->setText(tmpPath);
#elif defined (Q_OS_FREEBSD)
        ui->programStart1->setText(tmpPath);
#endif
        ui->programStart2->setToolTip   (path_2 + ui->programStart2->text()  );
        ui->programStart2->setWhatsThis (path_2 + ui->programStart2->text()  );
    }
}
void ExecPrograms::slotChooseProgramEnd1()
{
    message();
    QString tmpPath = QFileDialog::getOpenFileName(this,program_selection,QDir::homePath());
    if( !tmpPath.isEmpty() ){
#if defined (Q_OS_WIN)
        ui->programEnd1->setText(tmpPath.replace("/","\\"));
#elif defined (Q_OS_LINUX)
        ui->programEnd1->setText(tmpPath);
#elif defined (Q_OS_FREEBSD)
        ui->programEnd1->setText(tmpPath);
#endif
        ui->programEnd1->setToolTip     (path_1 + ui->programEnd1->text()    );
        ui->programEnd1->setWhatsThis   (path_1 + ui->programEnd1->text()    );
    }
}
void ExecPrograms::slotChooseProgramEnd2()
{
    message();
    QString tmpPath = QFileDialog::getOpenFileName(this,program_selection,QDir::homePath());
    if( !tmpPath.isEmpty() ){
#if defined (Q_OS_WIN)
        ui->programEnd2->setText(tmpPath.replace("/","\\"));
#elif defined (Q_OS_LINUX)
        ui->programEnd2->setText(tmpPath);
#elif defined (Q_OS_FREEBSD)
        ui->programEnd2->setText(tmpPath);
#endif
        ui->programEnd2->setToolTip     (path_2 + ui->programEnd2->text()    );
        ui->programEnd2->setWhatsThis   (path_2 + ui->programEnd1->text()    );
    }
}
void ExecPrograms::slotCheckFile(QString file)
{
    QPalette paletteRed = ui->programStart1->palette();
    QPalette paletteNorm = ui->programStart1->palette();

    QLineEdit *lineEdit = qobject_cast<QLineEdit*>(QObject::sender());

    paletteRed.setColor(QPalette::Text, Qt::red);
    paletteNorm.setColor(QPalette::Text, Qt::black);
    QFile pathToFile(file);

    if(pathToFile.exists())
      lineEdit->setPalette(paletteNorm);
    else
      lineEdit->setPalette(paletteRed);
}

ExecPrograms::~ExecPrograms()
{
    delete ui;
}
