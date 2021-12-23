#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPoint>
#include <QMouseEvent>
#include <QMediaPlayer>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //去窗口边框
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());

    //把窗口背景设置为透明;
    setAttribute(Qt::WA_TranslucentBackground);

    //点击音效＆BGM
    sound = new QMediaPlayer();
    sound->setMedia(QUrl("qrc:/click.wav"));
    BGM = new QMediaPlayer();
    BGM->setMedia(QUrl("qrc:/BGM.wav"));
    BGM->play();

    ui->lineEdit_password->setEchoMode(QLineEdit::Password); //输入密码以原点显示
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton)
    {
        //求坐标差值
        //当前点击坐标-窗口左上角坐标
        p = e->globalPos() - this->frameGeometry().topLeft();
        isPressing = true;
    }
}
void MainWindow::mouseReleaseEvent(QMouseEvent *e)
{
    Q_UNUSED(e);
    isPressing = false;
}

void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
    if(e->buttons() & Qt::LeftButton && isPressing)
    {
        //移到左上角
        move(e->globalPos() - p);
    }

}

void MainWindow::on_toolButton_minimize_clicked()
{
    showMinimized();
}


void MainWindow::on_toolButton_close_clicked()
{
    //弹窗判断是否确认退出登录
    QMessageBox::StandardButton result = QMessageBox::question(this,"","是否确认退出登录？",QMessageBox::No|QMessageBox::Yes);
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

/*void MainWindow::on_toolButton_maxmize_clicked()
{
    showMaximized();
}*/

void MainWindow::on_pushButton_login_clicked()
{
    sound->play();

    //验证账号密码
    if(ui->lineEdit_username->text().trimmed() == ui->lineEdit_password->text().trimmed())
    {
        M->show();
        hide();
    }
    else
    {
        QMessageBox::warning(this,"警告","账号或密码错误！",QMessageBox::Yes);

        // 清空密码输入框内容
        ui->lineEdit_password->clear();
        //光标定位
        ui->lineEdit_password->setFocus();
    }




}



