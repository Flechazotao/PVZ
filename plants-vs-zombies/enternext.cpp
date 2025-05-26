#include "enternext.h"

#include<QPainter>
#include<mypushbutton.h>
#include<NKUscene.h>
#include<classicscene.h>

Enternext::Enternext(QWidget *parent)
    : QMainWindow{parent}
{

    this->setFixedSize(800,600);
    this->setWindowTitle("植物大战僵尸");

}

void Enternext::paintEvent(QPaintEvent *)
{
    QPainter painter0(this);
    QPixmap pix;
    pix.load(":/Picture/Login/MainMenu.png");
    painter0.drawPixmap(0,0,this->width(),this->height(),pix);

    //设置经典模式按钮
    myPushButton* startbtn1=new myPushButton(":/pvz.res/classic.jpg");
    startbtn1->setParent(this);
    startbtn1->move(this->width()*0.85,this->height()*0);
    startbtn1->show();
    //利用信号与槽，点击进入经典模式
    connect (startbtn1,&myPushButton::clicked,[=](){
        qDebug()<<"开始经典模式";
        //进入开始场景中
        this->hide();
        Classicscene = new classicscene;
        Classicscene->show();
    });

    //设置NKU模式按钮
    myPushButton* startbtn2=new myPushButton(":/pvz.res/NKUmode.jpg");
    startbtn2->setParent(this);
    startbtn2->move(this->width()*0.85,this->height()*0.05);
    startbtn2->show();
    //利用信号与槽，点击进入NKU模式
    connect (startbtn2,&myPushButton::clicked,[=](){
        qDebug()<<"开始NKU模式";
        //进入开始场景中
        this->hide();
        Mambasence = new mambasence;
        Mambasence->show();
    });
}
