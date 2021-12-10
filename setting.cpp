#include "setting.h"
#include "ui_setting.h"
#include <QPoint>
#include <QMouseEvent>
#include <QMediaPlayer>

Setting::Setting(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Setting)
{
    ui->setupUi(this);
    //去窗口边框
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());

    //把窗口背景设置为透明;
    setAttribute(Qt::WA_TranslucentBackground);
    sound = new QMediaPlayer();
    sound->setMedia(QUrl("qrc:/click.wav"));
}

Setting::~Setting()
{
    delete ui;
}

void Setting::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton)
    {
        //求坐标差值
        //当前点击坐标-窗口左上角坐标
        p = e->globalPos() - this->frameGeometry().topLeft();
    }
}

void Setting::mouseMoveEvent(QMouseEvent *e)
{
    if(e->buttons() & Qt::LeftButton)
    {
        //移到左上角
        move(e->globalPos() - p);
    }

}

void Setting::on_toolButton_close_clicked()
{
    //弹窗判断是否确认退出游戏
    close();
}


void Setting::on_toolButton_back_clicked()
{
    //emit showMain();
    Mainwidget *M = new Mainwidget;
    M->show();
    sound->play();
    close();
}

/*void Setting::receiveMain()
{
    show();
}*/
