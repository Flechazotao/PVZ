#include "loginscene.h"
#include "ui_loginscene.h"
#include "classicscene.h"
#include <QApplication>
loginscene::loginscene(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::loginscene)
{
    ui->setupUi(this);
}

loginscene::~loginscene()
{
    delete ui;
}

void loginscene::on_login1_clicked()
{
    this->hide();
    classicscene *scene=new classicscene;
    scene->show();
}


void loginscene::on_introduce_Zombies_clicked()
{

}


void loginscene::on_Exit_clicked()
{   //退出游戏;
    QApplication*app;
    app->exit(0);
}


void loginscene::on_introduce_Plant_clicked()
{

}

