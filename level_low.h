#ifndef LEVEL_LOW_H
#define LEVEL_LOW_H

#include <QWidget>
//#include "mainwidget.h"
#include "startgame.h"
#include "generatemaze.h"
#include <QSound>
#include <QMediaPlayer>
namespace Ui {
class level_low;
}

class level_low : public QWidget
{
    Q_OBJECT

public:
    explicit level_low(QWidget *parent = nullptr);
    ~level_low();
    QMediaPlayer *sound;
protected:
    void mouseMoveEvent(QMouseEvent *e);//鼠标移动
    void mousePressEvent(QMouseEvent *e);//鼠标按下移动
    void mouseReleaseEvent(QMouseEvent *e);//鼠标释放
private slots:
    void on_toolButton_back_clicked();

    void on_toolButton_close_clicked();

private:
    Ui::level_low *ui;
    QPoint p;
    bool isPressing = false;
    QTimer *timer;
    void Timeout();
    void paintEvent(QPaintEvent *event);

};

#endif // LEVEL_LOW_H
