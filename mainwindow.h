#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mainwidget.h"
#include <QSound>
#include <QMediaPlayer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QMediaPlayer *sound;
    QMediaPlayer *BGM;
protected:
    void mouseMoveEvent(QMouseEvent *e);//鼠标移动
    void mousePressEvent(QMouseEvent *e);//鼠标按下移动
    void mouseReleaseEvent(QMouseEvent *e);//鼠标释放
private slots:
    void on_toolButton_minimize_clicked();

    void on_toolButton_close_clicked();

    //void on_toolButton_maxmize_clicked();

    void on_pushButton_login_clicked();
private:
    Ui::MainWindow *ui;

    QPoint p;

    bool isPressing = false;

    Mainwidget *M = new Mainwidget;
};
#endif // MAINWINDOW_H
