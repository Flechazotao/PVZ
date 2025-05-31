#include "introduceplant.h"
#include "lilypad.h"
#include "ui_introduceplant.h"
#include "loginscene.h"
#include "classicsunflower.h"
#include "wallnut.h"
#include "classicsnowpea.h"
#include "cherrybomb.h"
#include "classicrepeater.h"
#include "potatomine.h"
#include "classicpeashooter.h"

introduceplant::introduceplant(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::introduceplant)
{
    ui->setupUi(this);
    this->setWindowTitle("植物介绍");
    layout = new QVBoxLayout(ui->grass);
    label=new QLabel();
    movie=nullptr;
}

introduceplant::~introduceplant()
{
    delete ui;
}

void introduceplant::on_Exit_clicked()
{
    this->hide();
    loginscene*scene=new loginscene;
    scene->show();
}

void introduceplant::showMovieAndInfo(Plant*p,QString path){
    // 如果当前有 QMovie，先停止并删除它
    if (movie)
        delete movie;
    movie = new QMovie(path);
    movie->start();

    // 如果 label 当前有 QMovie，先停止并删除它
    if (label) {
        delete label->movie();  // 停止动画（可选）
        delete label;   // 释放 QMovie 内存
    }
    //设置label
    label=new QLabel();
    label->setFixedSize(161,117);
    label->setMovie(movie);
    label->setAlignment(Qt::AlignCenter);
    //让layout控件居中;
    layout->setAlignment(Qt::AlignCenter);
    layout->addStretch();
    layout->addWidget(label);
    layout->addStretch();
    //设置植物描述label内容;
    ui->info->setText(QString::fromStdString(p->getInfo()));
    //设置植物名称展示label
    ui->name->setText(QString::fromStdString(p->getName()));
}
void introduceplant::on_sunFlower_clicked(){
    ui->grass->setStyleSheet(
        "QWidget#grass{"
        "   border-image:url(:/Picture/Plant_introduce/grass.png);"
        "   border-radius:7px;"
        "}"
        );
    showMovieAndInfo(new classicSunFlower,":/Picture/Plant/sunflower/1.gif");
}

void introduceplant::on_wallnut_clicked()
{
        ui->grass->setStyleSheet(
        "QWidget#grass{"
        "   border-image:url(:/Picture/Plant_introduce/grass.png);"
        "   border-radius:7px;"
        "}"
        );
        showMovieAndInfo(new WallNut,":/Picture/Plant/wallnut/1.gif");
}


void introduceplant::on_peashooter_clicked()
{
        ui->grass->setStyleSheet(
        "QWidget#grass{"
        "   border-image:url(:/Picture/Plant_introduce/grass.png);"
        "   border-radius:7px;"
        "}"
        );
        showMovieAndInfo(new classicpeashooter,":/Picture/Plant/peashooter/1.gif");
}


void introduceplant::on_potatomine_clicked()
{
        ui->grass->setStyleSheet(
        "QWidget#grass{"
        "   border-image:url(:/Picture/Plant_introduce/grass.png);"
        "   border-radius:7px;"
        "}"
        );
        showMovieAndInfo(new PotatoMine,":/Picture/Plant/potatomine/PotatoMine.gif");
}


void introduceplant::on_repeaterpea_clicked()
{
        ui->grass->setStyleSheet(
        "QWidget#grass{"
        "   border-image:url(:/Picture/Plant_introduce/grass.png);"
        "   border-radius:7px;"
        "}"
        );
        showMovieAndInfo(new classicRepeater,":/Picture/Plant/repeater/1.gif");
}


void introduceplant::on_snowpea_clicked()
{
        ui->grass->setStyleSheet(
        "QWidget#grass{"
        "   border-image:url(:/Picture/Plant_introduce/grass.png);"
        "   border-radius:7px;"
        "}"
        );
        showMovieAndInfo(new classicSnowPea,":/Picture/Plant/snowpea/1.gif");
}


void introduceplant::on_cherrybomb_clicked()
{
    ui->grass->setStyleSheet(
        "QWidget#grass{"
        "   border-image:url(:/Picture/Plant_introduce/grass.png);"
        "   border-radius:7px;"
        "}"
        );
    showMovieAndInfo(new CherryBomb,":/Picture/Plant/cherrybomb/1.gif");
}


void introduceplant::on_lilypad_clicked()
{
    ui->grass->setStyleSheet(
        "QWidget#grass{"
        "   border-image:url(:/Picture/Plant_introduce/pool.png);"
        "   border-radius:7px;"
        "}"
        );
    showMovieAndInfo(new lilypad,":/Picture/Plant/lilypad/LilyPad.gif");
}

