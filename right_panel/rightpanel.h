#ifndef RIGHTPANEL_H
#define RIGHTPANEL_H
#include <QFrame>
#include <QLabel>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QSettings>
#include <QTime>
#include <QHeaderView>
#include <QTableWidgetItem>
#include <QDebug>
#include <QMouseEvent>

class RightPanel : public QFrame
{
    Q_OBJECT

public:

    QSettings   settings;

    RightPanel(int numbersOfLessonsChange1 = 8, int numbersOfLessonsChange2 = 8);
    ~RightPanel();

    void setNumbersOfLesson     (int numbersOfLessonChange1, bool enabledChange1,int numbersOfLessonChange2,bool enabledChange2);
    void setNumberOfShedul      (QString numberOfShedul, int numberOfTab);
    void setLesson              (int change, int numberOfLesson, QString timeBegin, QString timeEnd, \
                                 QString soundBegin="", QString soundEnd = "");
    void setTableToolTip        ();
    void setRecess              (int change, int lesson, QString result);

    int  getCountOfLessons      (int change);
    int  getNumberOfInstalTab   ();

    QString getLessonTimeBegin  (int change, int numberOfLesson);
    QString getLessonTimeEnd    (int change, int numberOfLesson);

    QString getLessonSoundBegin (int change, int numberOfLesson);
    QString getLessonSoundEnd   (int change, int numberOfLesson);

private:
    QLabel *pLabel; //Установленно распсание № n
    QList<QTableWidget*> pTable; //Вкладки смен
    QVBoxLayout *pLayout;
    QTabWidget* tabs;
    int numberOfInstalTab;

    void createTables(int numbersOfLessonsChange1, int numbersOfLessonsChange2);

    void correctChange(int change);
};

#endif // RIGHTPANEL_H
