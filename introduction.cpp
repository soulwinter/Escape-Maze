#include "introduction.h"
#include "ui_introduction.h"
#include <QPoint>
#include <QMouseEvent>
#include <QtDebug>
#include <QMediaPlayer>

Introduction::Introduction(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Introduction)
{
    ui->setupUi(this);
    //去窗口边框
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());

    //把窗口背景设置为透明;
    setAttribute(Qt::WA_TranslucentBackground);
    sound = new QMediaPlayer();
    sound->setMedia(QUrl("qrc:/click.wav"));
}

Introduction::~Introduction()
{
    delete ui;
}

void Introduction::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton)
    {
        //求坐标差值
        //当前点击坐标-窗口左上角坐标
        p = e->globalPos() - this->frameGeometry().topLeft();
    }
}

void Introduction::mouseMoveEvent(QMouseEvent *e)
{
    if(e->buttons() & Qt::LeftButton)
    {
        //移到左上角
        move(e->globalPos() - p);
    }

}

void Introduction::on_toolButton_close_clicked()
{
    //弹窗判断是否确认退出游戏
    close();
}


void Introduction::on_toolButton_back_clicked()
{
    //emit showMain();
    Mainwidget *M = new Mainwidget;
    M->show();
    sound->play();
    close();
}

/*void Introduction::receiveMain()
{
    qDebug()<<111;
    this->show();
}*/
