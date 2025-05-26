#include "map1.h"
#include "ui_map1.h"

MAP1::MAP1(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MAP1)
{
    ui->setupUi(this);
}

MAP1::~MAP1()
{
    delete ui;
}
