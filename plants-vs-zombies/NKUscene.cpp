#include<QSoundEffect>
#include<QMediaPlayer>
#include<QtMultimedia/QtMultimedia>
#include<QtMultimediaWidgets/QVideoWidget>
#include<QDebug>
#include<QAudioOutput>
#include<QPainter>
#include<NKUscene.h>



//主页面创建

mambasence::mambasence(QWidget *parent) : QMainWindow(parent)
{

    this->setFixedSize(902,602);

    srand(uint(QTime(0,0,0).secsTo(QTime::currentTime())));//生成随机数
    QSoundEffect * sound = new QSoundEffect(this);
    sound->setSource(QUrl::fromLocalFile(":/pvz.res/uilaf-pnamj.wav"));
    //sound->setLoopCount(5);
    //sound->setVolume(0.25f);
    sound->setLoopCount(QSoundEffect::Infinite);
    sound->setVolume(0.25f);
    sound->play();

    //创建计时器
    timer = new QTimer;

    //场景创建
    scene = new QGraphicsScene(this);

    //以下为设置场景过程
    scene->setSceneRect(150, 0, 900, 600);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    Shop *shop = new Shop;//设置购买栏
    shop->setPos(520, 45);//调整购买栏大小
    scene->addItem(shop);

    //设置铲子
    Shovel *shovel = new Shovel;
    shovel->setPos(830, 40);
    scene->addItem(shovel);

    //设置按钮
    Button *button = new Button(sound, timer);
    button->setPos(970, 20);
    scene->addItem(button);

    //设置场景
    Map *map = new Map;
    map->setPos(618, 326);
    scene->addItem(map);

    //用循环语句，设置5个小推车
    for (int i = 0; i < 5; ++i)
    {
        Mower *mower = new Mower;
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
    view->setBackgroundBrush(QPixmap(":/pvz.res/NKUback.jpg"));
    //进行画质优化
    view->setCacheMode(QGraphicsView::CacheBackground);
    //设置自动刷新模式
    view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    connect(timer, &QTimer::timeout, scene, &QGraphicsScene::advance);
    connect(timer, &QTimer::timeout, this, &mambasence::addZombie);
    connect(timer, &QTimer::timeout, this, &mambasence::check);
    //播放背景音乐

    //启动定时器
    timer->start(33);
    view->show();
}

mambasence::~mambasence()
{
    delete sound;
    delete timer;
    delete scene;
    delete view;
}

void mambasence::addZombie()
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
        time = rand() % (2 * maxtime / 3) + maxtime / 3;
        int type = rand() % 100;
        int i = rand() % 5;
        Zombie *zombie;
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

void mambasence::check()
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
                scene->addPixmap(QPixmap(":/pvz.res/NKUlose.jpg"))->setPos(200,100 );
                scene->advance();
                timer->stop();
                return;
            }
    }
}
