#ifndef CLASSICSCENE_H
#define CLASSICSCENE_H

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


class classicscene : public QMainWindow
{
    Q_OBJECT
public:
    explicit classicscene(QWidget *parent = nullptr);
    ~classicscene() override;

    void addZombie();
    void check();
    void updateCountdown();
    QMediaPlayer *player = nullptr;
    QAudioOutput *audioOutput = nullptr;


private:
    QSoundEffect *sound;
    QTimer *timer;
    QGraphicsScene *scene;
    QGraphicsView *view;
    QTimer *countdownTimer;  // 倒计时计时器
    int remainingTime;       // 剩余时间(秒)

};

#endif
