#include "mainwindow.h"
#include "mainwidget.h"
#include "introduction.h"
#include "setting.h"
#include "startgame.h"
#include <QMediaPlayer>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    /*Mainwidget wMain;
    Introduction wI;
    Setting wSet;
    StartGame wSG;
    QObject::connect(&wMain,SIGNAL(showIntro()),&wI,SLOT(receiveMain()));
    QObject::connect(&wMain,SIGNAL(showSet()),&wSet,SLOT(receiveMain()));
    QObject::connect(&wMain,SIGNAL(showSg()),&wSG,SLOT(receiveMain()));
    QObject::connect(&wI,SIGNAL(showMain()),&wMain,SLOT(receiveIntro()));
    QObject::connect(&wSet,SIGNAL(showMain()),&wMain,SLOT(receiveSet()));
    QObject::connect(&wSG,SIGNAL(showMain()),&wMain,SLOT(receiveSG()));*/

    return a.exec();
}
