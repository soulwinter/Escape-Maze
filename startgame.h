#ifndef STARTGAME_H
#define STARTGAME_H

#include <QWidget>
#include "mainwidget.h"
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
private slots:
    void on_toolButton_back_clicked();
    void on_toolButton_close_clicked();
    /*void receiveMain();
signals:
    void showMain();*/
private:
    Ui::StartGame *ui;
    QPoint p;

};

#endif // STARTGAME_H
