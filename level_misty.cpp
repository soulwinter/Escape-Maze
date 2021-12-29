#include "level_misty.h"
#include "ui_level_misty.h"
#include <QPoint>
#include <QMouseEvent>
#include <QtDebug>
#include <QMediaPlayer>
#include <QPainter>
#include <QTimer>
#include <QMessageBox>
#include <QKeyEvent>

level_misty::level_misty(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::level_misty)
{
    ui->setupUi(this);
    //去窗口边框
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());

    //把窗口背景设置为透明;
    //setAttribute(Qt::WA_TranslucentBackground);

    sound = new QMediaPlayer();
    sound->setMedia(QUrl("qrc:/click.wav"));

//    timer = new QTimer(this);
//    connect(timer, SIGNAL(timeout()), this, SLOT(Timeout()));
//    startTimer(1);

    pix_x = sizeOfRec + X;
    pix_y = sizeOfRec + Y;

    init(G , &start);
    FindBlock(x_num , y_num , m , n , &myblock , G);
    GenerateMap(G, &start ,x_num ,  y_num , m , n , myblock);

    picLabel = new QLabel(this);
    picLabel->setFixedSize(sizeOfRec, sizeOfRec);
    picLabel->move(pix_x,pix_y);

    picLabel->setFocusPolicy(Qt::StrongFocus);
}

level_misty::~level_misty()
{
    delete ui;
}

void level_misty::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton)
    {
        //求坐标差值
        //当前点击坐标-窗口左上角坐标
        p = e->globalPos() - this->frameGeometry().topLeft();
        isPressing = true;
    }
}

void level_misty::mouseReleaseEvent(QMouseEvent *e)
{
    Q_UNUSED(e);
    isPressing = false;
}

void level_misty::mouseMoveEvent(QMouseEvent *e)
{
    if(e->buttons() & Qt::LeftButton && isPressing)
    {
        //移到左上角
        move(e->globalPos() - p);
    }

}

void level_misty::paintEvent(QPaintEvent *event)   //绘画事件
{
    Q_UNUSED(event);
    QPainter painter(this);

    for(int i = 0; i < I; i++)
    {
        for(int j = 0; j < J; j++)
        {
            if(qAbs((pix_x - X)/sizeOfRec - i) > canSee || qAbs((pix_y - Y)/sizeOfRec - j) > canSee)
            {
                painter.drawPixmap(X + i * sizeOfRec, Y  + sizeOfRec * j, sizeOfRec, sizeOfRec, QPixmap(":/misty.png"));
            }
            else
            {
                if(G[i][j]==2)
                {
                    painter.drawPixmap(X + i * sizeOfRec, Y  + sizeOfRec * j, sizeOfRec, sizeOfRec, QPixmap(":/path.jpeg"));
                }
                else if(G[i][j] == -1)
                {
                    painter.drawPixmap(X + i * sizeOfRec, Y  + sizeOfRec * j, sizeOfRec, sizeOfRec, QPixmap(":/wall.jpeg"));
                }
            }
        }
    }

    painter.drawPixmap(picLabel->x(), picLabel->y(), picLabel->width(), picLabel->height(), QPixmap(":/780.jfif"));
//    if(picLabel->x() == 750 && picLabel->y() == 810)
//        Victory();
}

void level_misty::Timeout()  //定时器函数
{
    update();
    qDebug() << 111;

}

void level_misty::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_Up:
    case Qt::Key_W:
        if(G[(pix_x - X)/sizeOfRec][(pix_y - Y)/sizeOfRec - 1] == 2)
        {
            pix_y -= sizeOfRec;
            picLabel->move(pix_x, pix_y);//向上移动就是x不变y减小
        }
        break;
    case Qt::Key_Down:
    case Qt::Key_S:
        if(G[(pix_x - X)/sizeOfRec][(pix_y - Y)/sizeOfRec + 1] == 2 || G[(pix_x - X)/sizeOfRec][(pix_y - Y)/sizeOfRec + 1] == 3)
        {
            pix_y += sizeOfRec;
            picLabel->move(pix_x, pix_y);
        }
        break;
    case Qt::Key_Right:
    case Qt::Key_D:
        if(G[(pix_x - X)/sizeOfRec + 1][(pix_y - Y)/sizeOfRec] == 2 || G[(pix_x - X)/sizeOfRec + 1][(pix_y - Y)/sizeOfRec] == 3)
        {
            pix_x += sizeOfRec;
            picLabel->move(pix_x, pix_y);
        }
        break;
    case Qt::Key_Left:
    case Qt::Key_A:
        if(G[(pix_x - X)/sizeOfRec - 1][(pix_y - Y)/sizeOfRec] == 2)
        {
            pix_x -= sizeOfRec;
            picLabel->move(pix_x, pix_y);
        }
        break;
    default:
        break;
    }
    update();
}

void level_misty::Victory()
{
    QMessageBox::StandardButton result = QMessageBox::information(this,"","VICTORY!\n  本局战绩:\n用时:     \n拾取道具数:     \n被NPC捕捉次数:     ",QMessageBox::Yes);
    switch(result)
    {
    case QMessageBox::Yes:
        close();
        break;
    default:
        break;
    }
}

void level_misty::keyReleaseEvent(QKeyEvent *event)
{

}

void level_misty::on_toolButton_back_clicked()
{
    //弹窗判断是否确认退出游戏
    QMessageBox::StandardButton result = QMessageBox::question(this,"","是否返回？（将退出本次游戏）",QMessageBox::No|QMessageBox::Yes);
    switch(result)
    {
    case QMessageBox::Yes:
    {
        StartGame *SG = new StartGame;
        SG->show();
        sound->play();
        close();
        break;
    }
    case QMessageBox::No:
        break;
    default:
        break;
    }
}

void level_misty::on_toolButton_close_clicked()
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
