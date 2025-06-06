#include "classicscene.h"
#include<QSoundEffect>
#include<QMediaPlayer>
#include<QtMultimedia/QtMultimedia>
#include<QtMultimediaWidgets/QVideoWidget>
#include<QDebug>
#include<QAudioOutput>
#include<QPainter>
#include<classicscene.h>
#include"classicmap.h"
#include "exitbutton.h"


//主页面创建

classicscene::classicscene(QWidget *parent) : QMainWindow(parent)
{

    this->setFixedSize(902,602);
    srand(uint(QTime(0,0,0).secsTo(QTime::currentTime())));//生成随机数
    //设置并播放背景音乐
    QSoundEffect * sound = new QSoundEffect(this);
    sound->setSource(QUrl::fromLocalFile(":/Picture/UraniwaNi.wav"));
    //sound->setLoopCount(5);这里背景音乐无法循环播放
    //sound->setVolume(0.25f);
    sound->setLoopCount(QSoundEffect::Infinite);//循环播放
    sound->setVolume(0.25f);//设置声音大小
    sound->play();

    //创建计时器
    timer = new QTimer;

    //创建倒计时器;
    countdownTimer = new QTimer(this);
    // 设置初始时间(例如5分钟=300秒)
    remainingTime = 300;
    // 启动倒计时计时器(每秒触发一次)
    countdownTimer->start(1000);


    //场景创建
    scene = new QGraphicsScene(this);

    //以下为设置场景过程
    scene->setSceneRect(150, 0, 900, 600);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    classicshop *shop = new classicshop;//设置购买栏
    shop->setPos(520, 45);//调整购买栏大小
    scene->addItem(shop);

    //设置铲子
    Shovel *shovel = new Shovel;
    shovel->setPos(830, 40);
    scene->addItem(shovel);

    //设置按钮
    Button *button = new Button(sound, timer);//参数为sound和timer,实现按下暂停，音乐停止，计时器停止，从而实现画面静止
    button->setPos(970, 20);
    scene->addItem(button);

    // 创建按钮返回主页面
    exitbutton *exit=new exitbutton(sound, timer,this,"返回主页面");
    exit->setPos(970,60);
    scene->addItem(exit);

    //设置场景
    classicMap *map = new classicMap;
    map->setPos(618, 326);
    scene->addItem(map);

    //用循环语句，设置5个小推车
    for (int i = 0; i < 5; ++i)
    {
        classicMower *mower = new classicMower;
        mower->setPos(210, 130 + 98 * i);
        scene->addItem(mower);
    }

    //QGraphicsView提供的View组件，用于可视化场景中的内容
    //创建
    view = new QGraphicsView(scene, this);
    //设置大小
    view->resize(902, 602);
    //反走样功能，调用反锯齿功能，优化图像
    view->setRenderHint(QPainter::Antialiasing);
    //设置背景图
    view->setBackgroundBrush(QPixmap(":/Picture/Map1/map1.jpg"));
    //进行画质优化
    view->setCacheMode(QGraphicsView::CacheBackground);
    //设置自动刷新模式
    view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    connect(timer, &QTimer::timeout, scene, &QGraphicsScene::advance);
    connect(timer, &QTimer::timeout, this, &classicscene::addZombie);
    connect(timer, &QTimer::timeout, this, &classicscene::check);
    connect(countdownTimer, &QTimer::timeout, this, &classicscene::updateCountdown);

    //启动定时器
    timer->start(33);
    view->show();
}

classicscene::~classicscene()
{
    delete sound;
    delete timer;
    delete scene;
    delete view;
}

void classicscene::updateCountdown()
{
    remainingTime--;
    // 时间到，游戏结束
    if (remainingTime <= 0) {
        countdownTimer->stop(); //停止倒计时;
        exitbutton*winbutton=new exitbutton(sound, timer,this,"游戏胜利");
        winbutton->setPos(600,300);
        winbutton->setZValue(4);
        scene->addItem(winbutton);
        return;
    }
}



//绘制僵尸
void classicscene::addZombie()
{
    static int low = 4;
    static int high = 8;
    static int maxtime = 20 * 1000 / 33;
    static int time = maxtime / 2;
    static int counter = 0;
    if (++counter >= time)
    {
        if (++low > high)
        {
            maxtime /= 1.3;
            high *= 2;
        }
        counter = 0;
        //生成随机数并进行运算
        time = rand() % (2 * maxtime / 3) + maxtime / 3;
        int type = rand() % 100;
        int i = rand() % 5;
        Zombie *zombie;
        //根据随机数各个分布区间出现的概率不同，来随机绘制僵尸
        //普通僵尸最常出现，然后是路障僵尸~~~
        if (type < 40)
            zombie = new BasicZombie;
        else if (type < 70)
            zombie = new ConeZombie;
        else if (type < 80)
            zombie = new BucketZombie;
        else if (type < 90)
            zombie = new ScreenZombie;
        else
            zombie = new FootballZombie;
        zombie->setPos(1028, 130 + 98 * i);
        scene->addItem(zombie);
    }
}

//通过判断僵尸距离左边界的距离来判断是否游戏结束
void classicscene::check()
{
    static int time = 1 * 1000 / 33;
    static int counter = 0;
    if (++counter >= time)
    {
        counter = 0;
        const QList<QGraphicsItem *> items = scene->items();
        foreach (QGraphicsItem *item, items)
            if (item->type() == Zombie::Type && item->x() < 200)
            {
                exitbutton*winbutton=new exitbutton(sound, timer,this,"游戏失败");
                winbutton->setPos(600,300);
                winbutton->setZValue(4);
                scene->addItem(winbutton);
                scene->addPixmap(QPixmap(":/Picture/Screen/ZombiesWon.png"))->setPos(336, 40);
                scene->advance();
                timer->stop();
                return;
            }
    }
}


