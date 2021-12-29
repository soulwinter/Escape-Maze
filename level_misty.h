#ifndef LEVEL_MISTY_H
#define LEVEL_MISTY_H

#include <QWidget>
//#include "mainwidget.h"
#include "startgame.h"
#include "generatemaze.h"
#include <QSound>
#include <QMediaPlayer>
#include <QLabel>
//#include <QKeyEvent>

namespace Ui {
class level_misty;
}

class level_misty : public QWidget
{
    Q_OBJECT

public:
    explicit level_misty(QWidget *parent = nullptr);
    ~level_misty();
    QMediaPlayer *sound;
protected:
    void mouseMoveEvent(QMouseEvent *e);//鼠标移动
    void mousePressEvent(QMouseEvent *e);//鼠标按下移动
    void mouseReleaseEvent(QMouseEvent *e);//鼠标释放
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void paintEvent(QPaintEvent *event);
    void Victory();
    void Timeout();
private slots:
    void on_toolButton_back_clicked();

    void on_toolButton_close_clicked();

private:
    Ui::level_misty *ui;
    QPoint p;
    bool isPressing = false;
    QTimer *timer;
    QLabel *picLabel;


    int m  = 49, n = 49;//墙的边界
    int x , y;//墙的界限
    vector<block> myblock;//存储待处理的墙
    int x_num = 1, y_num = 1;//玩家起始位置
    char G[100][100];//理想最大地图的最大边界（并非生成的地图的最大边界）
    point start , end;
    int I = m + 2, J = n + 2, X = 0, Y = 30;
    int sizeOfRec = 850 / I;
    int pix_x;
    int pix_y;
    int canSee = 5;
};

#endif // LEVEL_MISTY_H
