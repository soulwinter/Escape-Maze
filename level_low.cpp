#include "level_low.h"
#include "ui_level_low.h"
#include <QPoint>
#include <QMouseEvent>
#include <QtDebug>
#include <QMediaPlayer>
#include <QPainter>
#include <QTimer>
#include <QMessageBox>

int m  = 15, n = 15;//墙的边界
int x , y;//墙的界限
vector<block> myblock;//存储待处理的墙
int x_num = 1, y_num = 1;//玩家起始位置
char G[100][100];//理想最大地图的最大边界（并非生成的地图的最大边界）
point start , end;

level_low::level_low(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::level_low)
{
    ui->setupUi(this);
    //去窗口边框
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());

    //把窗口背景设置为透明;
    //setAttribute(Qt::WA_TranslucentBackground);

    sound = new QMediaPlayer();
    sound->setMedia(QUrl("qrc:/click.wav"));

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(Timeout()));

    init(G , &start);
    FindBlock(x_num , y_num , m , n , &myblock , G);
    GenerateMap(G, &start ,x_num ,  y_num , m , n ,myblock );
}

level_low::~level_low()
{
    delete ui;
}

void level_low::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton)
    {
        //求坐标差值
        //当前点击坐标-窗口左上角坐标
        p = e->globalPos() - this->frameGeometry().topLeft();
        isPressing = true;
    }
}
void level_low::mouseReleaseEvent(QMouseEvent *e)
{
    Q_UNUSED(e);
    isPressing = false;
}

void level_low::mouseMoveEvent(QMouseEvent *e)
{
    if(e->buttons() & Qt::LeftButton && isPressing)
    {
        //移到左上角
        move(e->globalPos() - p);
    }

}

void level_low::paintEvent(QPaintEvent *event)   //绘画事件
{
    int I = m + 2, J = n + 2, X = 0, Y = 10;
    Q_UNUSED(event);
    QPainter painter(this);

    for(int i = 0; i < I; i++)
    {
        for(int j = 0; j < J; j++)
        {
            if(G[i][j]==2)
            {
                painter.drawPixmap(X + i * 50, Y + 50 + 50 * j, 50, 50, QPixmap(":/path.jpeg"));
            }
            else if(G[i][j] == -1)
            {
                painter.drawPixmap(X + i * 50, Y + 50 + 50 * j, 50, 50, QPixmap(":/wall.jpeg"));
            }
        }
    }

}

void level_low::Timeout()  //定时器函数
{
    update();
}

void level_low::on_toolButton_back_clicked()
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


void level_low::on_toolButton_close_clicked()
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

