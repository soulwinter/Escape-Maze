#ifndef SETTING_H
#define SETTING_H

#include <QWidget>
#include "mainwidget.h"
#include <QSound>
#include <QMediaPlayer>

namespace Ui {
class Setting;
}

class Setting : public QWidget
{
    Q_OBJECT

public:
    explicit Setting(QWidget *parent = nullptr);
    ~Setting();
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
    Ui::Setting *ui;
    QPoint p;

};

#endif // SETTING_H
