#ifndef SWIMMINGPOOLSCENE_H
#define SWIMMINGPOOLSCENE_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>

#include <QTimer>

#include "classicshop.h"
#include "classcard.h"
#include "shovel.h"
#include "button.h"

#include "classicmower.h"
#include "basiczombie.h"
#include "conezombie.h"
#include "bucketzombie.h"
#include "screenzombie.h"
#include "footballzombie.h"
#include <QMediaPlayer>


namespace Ui {
class swimmingpoolscene;
}

class swimmingpoolscene : public QWidget
{
    Q_OBJECT

public:
    explicit swimmingpoolscene(QWidget *parent = nullptr);
    ~swimmingpoolscene();
    void addZombie();
    void check();
    void on_exit_clicked();
    QMediaPlayer *player = nullptr;
    QAudioOutput *audioOutput = nullptr;

private:
    Ui::swimmingpoolscene *ui;
    QSoundEffect *sound;
    QTimer *timer;
    QGraphicsScene *scene;
    QGraphicsView *view;
};

#endif // SWIMMINGPOOLSCENE_H
