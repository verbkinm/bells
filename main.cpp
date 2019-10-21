#include <QApplication>
#include "mainwindow.h"

//#include <QFont>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
//Для маленького монитора
/*    w.setIconSize(QSize(16,16));
    QFont font = w.font();
    font.setPixelSize(8);
    w.setFont(font);
*/
    w.showMaximized();

    return a.exec();
}
