#include "mainwindow.h"
#include<QSoundEffect>
#include<QMediaPlayer>
#include<QtMultimedia/QtMultimedia>
#include<QtMultimediaWidgets/QVideoWidget>
#include<QDebug>
#include<QAudioOutput>
#include<QPainter>
#include<mypushbutton.h>

//主页面创建

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    //设置场景大小
    this->setFixedSize(902,602);
}

void MainWindow::paintEvent(QPaintEvent *)
{
    //设置背景
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/pvz.res/first.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
    //设置进入按钮
    myPushButton* startbtn=new myPushButton(":/pvz.res/btn.png");
    startbtn->setParent(this);
    startbtn->move(this->width()*0.35,this->height()*0.2);
    startbtn->show();

    enter =new Enter;
    //利用信号与槽实现按钮功能
    connect (startbtn,&myPushButton::clicked,[=](){
        qDebug()<<"开始";
        //进入开始场景中
        this->hide();
        enter->show();

    });

}

MainWindow::~MainWindow()
{
}





