#ifndef EXITBUTTON_H
#define EXITBUTTON_H

#include <QTimer>
#include <QSoundEffect>
#include "other.h"

class exitbutton : public Other
{
public:
    exitbutton(QSoundEffect *s, QTimer *t, QWidget *w, const std::string &title);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void changeName(std::string&title);

private:
    QSoundEffect *sound;
    QTimer *timer;
    QWidget *widget;
    QString qstr;
};

#endif // EXITBUTTON_H
