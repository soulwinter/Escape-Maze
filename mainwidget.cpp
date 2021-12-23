#include "mainwidget.h"
#include "ui_mainwidget.h"
#include <QPoint>
#include <QMouseEvent>
#include <QDebug>
#include <QMediaPlayer>
#include <QMessageBox>
Mainwidget::Mainwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Mainwidget)
{
    ui->setupUi(this);
    //去窗口边框
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());

    //把窗口背景设置为透明;
    setAttribute(Qt::WA_TranslucentBackground);

    sound = new QMediaPlayer();
    sound->setMedia(QUrl("qrc:/click.wav"));
}

Mainwidget::~Mainwidget()
{
    delete ui;
}

void Mainwidget::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton)
    {
        //求坐标差值
        //当前点击坐标-窗口左上角坐标
        p = e->globalPos() - this->frameGeometry().topLeft();
        isPressing = true;
    }
}
void Mainwidget::mouseReleaseEvent(QMouseEvent *e)
{
    Q_UNUSED(e);
    isPressing = false;
}

void Mainwidget::mouseMoveEvent(QMouseEvent *e)
{
    if(e->buttons() & Qt::LeftButton && isPressing)
    {
        //移到左上角
        move(e->globalPos() - p);
    }

}

void Mainwidget::on_toolButton_minimize_clicked()
{
    showMinimized();
}


/*void Mainwidget::on_toolButton_maxmize_clicked()
{
    showMaximized();
}*/

void Mainwidget::on_toolButton_close_clicked()
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

void Mainwidget::on_pushButton_startGame_clicked()
{
    //emit showSg();
    StartGame *SG = new StartGame;
    SG->show();
    sound->play();
    close();
}


void Mainwidget::on_pushButton_introduction_clicked()
{
    //qDebug()<<222;
    //emit showIntro();
    Introduction *I = new Introduction;
    I->show();

    sound->play();

    close();
}


void Mainwidget::on_pushButton_setting_clicked()
{
    //emit showSet();
    Setting *Set = new Setting;
    Set->show();

    sound->play();

    close();
}

/*void Mainwidget::receiveIntro()
{
    show();
}

void Mainwidget::receiveSet()
{
    show();
}

void Mainwidget::receiveSG()
{
    show();
}*/
