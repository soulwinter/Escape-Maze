#include "startgame.h"
#include "ui_startgame.h"
#include <QPoint>
#include <QMouseEvent>
#include <QMediaPlayer>

StartGame::StartGame(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StartGame)
{
    ui->setupUi(this);
    //去窗口边框
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());

    //把窗口背景设置为透明;
    setAttribute(Qt::WA_TranslucentBackground);
    sound = new QMediaPlayer();
    sound->setMedia(QUrl("qrc:/click.wav"));
}

StartGame::~StartGame()
{
    delete ui;
}

void StartGame::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton)
    {
        //求坐标差值
        //当前点击坐标-窗口左上角坐标
        p = e->globalPos() - this->frameGeometry().topLeft();
    }
}

void StartGame::mouseMoveEvent(QMouseEvent *e)
{
    if(e->buttons() & Qt::LeftButton)
    {
        //移到左上角
        move(e->globalPos() - p);
    }

}

void StartGame::on_toolButton_back_clicked()
{
    //emit showMain();
    Mainwidget *M = new Mainwidget;
    M->show();
    sound->play();
    close();
}


void StartGame::on_toolButton_close_clicked()
{
    //弹窗判断是否确认退出游戏
    close();
}

/*void StartGame::receiveMain()
{
    show();
}*/
