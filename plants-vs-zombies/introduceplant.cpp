#include "introduceplant.h"
#include "ui_introduceplant.h"
#include "loginscene.h"
#include "sunflower.h"
introduceplant::introduceplant(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::introduceplant)
{
    ui->setupUi(this);
    this->setWindowTitle("植物介绍");
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


void introduceplant::on_sunFlower_clicked()
{
    SunFlower *sunflower =new SunFlower;
    QLabel *label = new QLabel;
    label->setMovie(sunflower->getMovie());
    QVBoxLayout *layout = new QVBoxLayout(ui->grass);
    //让layout控件居中;
    layout->setAlignment(Qt::AlignCenter);
    layout->addStretch();
    layout->addWidget(label);
    layout->addStretch();
    ui->info->setText(QString::fromStdString(sunflower->getInfo()));
}

