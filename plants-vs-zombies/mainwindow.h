#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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
#include<enter.h>
#include<enternext.h>


class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;
    void paintEvent(QPaintEvent *);
    void addZombie();
    void check();

    Enter * enter=NULL;
};

#endif // MAINWINDOW_H
