#include "mainwindow.h"
#include "mainwidget.h"
#include "introduction.h"
#include "setting.h"
#include "startgame.h"
#include "generatemaze.h"
#include <QMediaPlayer>
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
