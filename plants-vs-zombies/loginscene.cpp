#include "loginscene.h"
// #include "roofscene.h"
#include "swimmingpoolscene.h"
#include "ui_loginscene.h"
#include "classicscene.h"
#include "introduceplant.h"
#include "introducezombies.h"
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
    this->hide();
    introducezombies* scene=new introducezombies;
    scene->show();
}


void loginscene::on_Exit_clicked()
{   //退出游戏;
    QApplication*app;
    app->exit(0);
}


void loginscene::on_introduce_Plant_clicked()
{
    this->hide();
    introduceplant* scene=new introduceplant;
    scene->setWindowTitle("植物图鉴");
    scene->show();
}


void loginscene::on_login2_clicked()
{
    this->hide();
    swimmingpoolscene* scene=new swimmingpoolscene;
    scene->setWindowTitle("泳池地图");
    scene->show();
}

