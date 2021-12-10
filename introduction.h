#ifndef INTRODUCTION_H
#define INTRODUCTION_H

#include <QWidget>
#include "mainwidget.h"
#include <QSound>
#include <QMediaPlayer>

namespace Ui {
class Introduction;
}

class Introduction : public QWidget
{
    Q_OBJECT

public:
    explicit Introduction(QWidget *parent = nullptr);
    ~Introduction();
    QMediaPlayer *sound;

protected:
    void mouseMoveEvent(QMouseEvent *e);//鼠标移动
    void mousePressEvent(QMouseEvent *e);//鼠标按下移动
private slots:
    void on_toolButton_close_clicked();
    void on_toolButton_back_clicked();
   /*void receiveMain();
signals:
    void showMain();*/
private:
    Ui::Introduction *ui;
    QPoint p;

};

#endif // INTRODUCTION_H
