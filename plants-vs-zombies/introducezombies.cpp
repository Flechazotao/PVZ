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


void introducezombies::on_basiczombies_clicked()
{
    BasicZombie *zom =new BasicZombie;
    QLabel *label = new QLabel;

    zom->getMovie()->start();

    label->setMovie(zom->getMovie());
    QVBoxLayout *layout = new QVBoxLayout(ui->grass);
    layout->addWidget(label);
}

