#ifndef mambasence_H
#define mambasence_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>

#include "shop.h"
#include "card.h"
#include "shovel.h"
#include "button.h"
#include "map.h"
#include "mower.h"
#include "basiczombie.h"
#include "conezombie.h"
#include "bucketzombie.h"
#include "screenzombie.h"
#include "footballzombie.h"


class mambasence : public QMainWindow
{
    Q_OBJECT
public:
    explicit mambasence(QWidget *parent = nullptr);
    ~mambasence() override;
    void addZombie();
    void check();

private:
    QSoundEffect *sound;
    QTimer *timer;
    QGraphicsScene *scene;
    QGraphicsView *view;
};

#endif
