#include "startgame.h"
#include "ui_startgame.h"
#include <QPoint>
#include <QMouseEvent>
#include <QMediaPlayer>
#include <QMessageBox>
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
        isPressing = true;
    }
}
void StartGame::mouseReleaseEvent(QMouseEvent *e)
{
    Q_UNUSED(e);
    isPressing = false;
}

void StartGame::mouseMoveEvent(QMouseEvent *e)
{
    if(e->buttons() & Qt::LeftButton && isPressing)
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
    QMessageBox::StandardButton result = QMessageBox::question(this,"","是否确认退出游戏？",QMessageBox::No|QMessageBox::Yes);
    switch(result)
    {
    case QMessageBox::Yes:
        close();
        break;
    case QMessageBox::No:
        break;
    default:
        break;
    }
}

/*void StartGame::receiveMain()
{
    show();
}*/

void StartGame::on_pushButton_low_clicked()
{
    level_low *L_L = new level_low;
    L_L->show();
    sound->play();
    close();
}

