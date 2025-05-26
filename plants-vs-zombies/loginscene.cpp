#include "loginscene.h"
#include "ui_loginscene.h"
#include "map1.h"
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
    MAP1 *scene= new MAP1;
    scene->setFixedSize(1000,600);
    scene->setWindowTitle("第一关");
    scene->show();
}

