#include "loginscene.h"
#include "ui_loginscene.h"
#include "classicscene.h"
loginscene::loginscene(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::loginscene)
{
    ui->setupUi(this);
    ui->widget->setStyleSheet("background: transparent;");
    ui->introduce_Plant->setStyleSheet("QPushButton { background: transparent; border: none; }");
    ui->introduce_Plant->setStyleSheet("font: bold 12px 'Arial';");
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

