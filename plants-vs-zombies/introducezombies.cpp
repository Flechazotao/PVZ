#include "introducezombies.h"
#include "ui_introducezombies.h"
#include "loginscene.h"
#include "basiczombie.h"
#include <QVBoxLayout>

introducezombies::introducezombies(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::introducezombies)
{
    ui->setupUi(this);
    this->setWindowTitle("僵尸介绍");
    layout = new QVBoxLayout(ui->grass);
    label=new QLabel();
    movie=nullptr;
}

introducezombies::~introducezombies()
{
    delete ui;
}

void introducezombies::on_Exit_clicked()
{
    this->hide();
    loginscene*scene=new loginscene;
    scene->show();
}


void introducezombies::showMovieAndInfo(Zombie*p,QString path){
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
    label->setFixedSize(171,149);
    label->setMovie(movie);
    label->setAlignment(Qt::AlignCenter);
    //让layout中的控件居中;
    layout->setAlignment(Qt::AlignCenter);
    layout->addStretch();
    layout->addWidget(label);
    layout->addStretch();
    //设置植物描述label内容;
    ui->info->setText(QString::fromStdString(p->getInfo()));
    //设置植物名称展示label
    ui->name->setText(QString::fromStdString(p->getName()));
}


void introducezombies::on_basiczombies_clicked()
{
    showMovieAndInfo(new BasicZombie,":/Picture/Zombie/Zombie/2.gif");
}

