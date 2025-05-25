#include "mypushbutton.h"


myPushButton::myPushButton(QString normalImg,QString  pressImg)
{

    this->normalImgPath=normalImg;
    this->pressImgPath=pressImg;

    QPixmap pix;
    pix.load(normalImg);

    this->setFixedSize(pix.width(),pix.height());

    this->setStyleSheet("QPushButton{border:Opx}");

    this->setIcon(pix);

    this->setIconSize(QSize(pix.width(),pix.height()));

}
