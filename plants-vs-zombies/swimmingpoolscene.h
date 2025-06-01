#ifndef SWIMMINGPOOLSCENE_H
#define SWIMMINGPOOLSCENE_H

#include "qgraphicsscene.h"
#include "qmediaplayer.h"
#include "qsoundeffect.h"
#include "qwidget.h"


class swimmingpoolscene : public QWidget
{
    Q_OBJECT

public:
    explicit swimmingpoolscene(QWidget *parent = nullptr);
    ~swimmingpoolscene();
    void addZombie();
    void check();
    void on_exit_clicked();
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


#endif // SWIMMINGPOOLSCENE_H
