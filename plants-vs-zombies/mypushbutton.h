#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>

class myPushButton : public QPushButton
{
    Q_OBJECT
public:
    myPushButton(QString normalImg,QString pressImg ="");
    QString normalImgPath;
    QString pressImgPath;

signals:
};

#endif // MYPUSHBUTTON_H
