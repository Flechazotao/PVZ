#ifndef EXITBUTTON_H
#define EXITBUTTON_H

#include <QTimer>
#include <QSoundEffect>
#include "other.h"

class exitbutton : public Other
{
public:
    exitbutton(QSoundEffect *s, QTimer *t, QWidget *w);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

private:
    QSoundEffect *sound;
    QTimer *timer;
    QWidget *widget;
};

#endif // EXITBUTTON_H
