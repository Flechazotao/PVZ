#include "exitbutton.h"
#include "loginscene.h"

exitbutton::exitbutton(QSoundEffect *s, QTimer *t,QWidget *w,const std::string&title)
{
    sound = s;
    timer = t;
    widget = w;
    qstr = QString::fromStdString(title);
}

QRectF exitbutton::boundingRect() const
{
    return QRectF(-80, -20, 160, 40);
}

void exitbutton::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    painter->drawPixmap(QRect(-80, -20, 160, 40), QPixmap(":/Picture/Button.png"));
    painter->setPen(Qt::green);
    QFont font("Calibri", 16, QFont::Bold, true);
    painter->setFont(font);
    painter->drawText(boundingRect(), Qt::AlignCenter, qstr);
}

void exitbutton::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        loginscene*scene=new loginscene;
        scene->setFixedSize(900, 600);
        scene->setWindowTitle("植物大战僵尸");
        widget->hide();
        scene->show();

        // delete sound;
        // delete timer;
    }
    update();
}
