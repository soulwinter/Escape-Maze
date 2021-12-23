#ifndef STARTGAME_H
#define STARTGAME_H

#include <QWidget>
#include "mainwidget.h"
#include "level_low.h"
#include <QSound>
#include <QMediaPlayer>

namespace Ui {
class StartGame;
}

class StartGame : public QWidget
{
    Q_OBJECT

public:
    explicit StartGame(QWidget *parent = nullptr);
    ~StartGame();
    QMediaPlayer *sound;
protected:
    void mouseMoveEvent(QMouseEvent *e);//鼠标移动
    void mousePressEvent(QMouseEvent *e);//鼠标按下移动
    void mouseReleaseEvent(QMouseEvent *e);//鼠标释放
private slots:
    void on_toolButton_back_clicked();
    void on_toolButton_close_clicked();
    /*void receiveMain();
signals:
    void showMain();*/
    void on_pushButton_low_clicked();

private:
    Ui::StartGame *ui;
    QPoint p;
    bool isPressing = false;

};

#endif // STARTGAME_H
