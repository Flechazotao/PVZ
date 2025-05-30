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
    QMediaPlayer *player = nullptr;
    QAudioOutput *audioOutput = nullptr;

private:
    QSoundEffect *sound;
    QTimer *timer;
    QGraphicsScene *scene;
    QGraphicsView *view;
};


#endif // SWIMMINGPOOLSCENE_H
