#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include "introduction.h"
#include "setting.h"
#include "startgame.h"
#include <QSound>
#include <QMediaPlayer>

namespace Ui {
class Mainwidget;
}

class Mainwidget : public QWidget
{
    Q_OBJECT

public:
    explicit Mainwidget(QWidget *parent = nullptr);
    ~Mainwidget();
    QMediaPlayer *sound;
protected:
    void mouseMoveEvent(QMouseEvent *e);//鼠标移动
    void mousePressEvent(QMouseEvent *e);//鼠标按下移动
    void mouseReleaseEvent(QMouseEvent *e);//鼠标释放
private slots:
    void on_toolButton_minimize_clicked();
    //void on_toolButton_maxmize_clicked();
    void on_toolButton_close_clicked();
    void on_pushButton_startGame_clicked();
    void on_pushButton_introduction_clicked();
    void on_pushButton_setting_clicked();
   /* void receiveIntro();
    void receiveSet();
    void receiveSG();
signals:
    void showIntro();  //显示游戏说明界面
    void showSet();    //显示设置界面
    void showSg();     //显示开始游戏界面  */
private:
    Ui::Mainwidget *ui;
    QPoint p;
    bool isPressing = false;

};

#endif // MAINWIDGET_H
