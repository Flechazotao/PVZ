#include "demo1.h"
#include "ui_demo1.h"

demo1::demo1(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::demo1)
{
    ui->setupUi(this);
}

demo1::~demo1()
{
    delete ui;
}
