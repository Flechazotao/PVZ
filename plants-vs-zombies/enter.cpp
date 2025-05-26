#include "enter.h"

#include<QPainter>
#include<mypushbutton.h>
#include<enternext.h>

Enter::Enter(QWidget *parent)
    : QMainWindow{parent}
{
    this->setFixedSize(800,600);
    this->setWindowTitle("植物大战僵尸");

    myPushButton * next=new myPushButton(":/pvz.res/secend.jpg");

    next->setParent(this);
    next->setStyleSheet(styleSheet());

    enternext =new Enternext;

    connect (next,&myPushButton::clicked,[=](){
        qDebug()<<"进入选择关卡界面";
        //进入开始场景中
        this->hide();

        enternext->show();

    });
}

void Enter::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

}
