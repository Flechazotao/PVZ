#ifndef PLANT_H
#define PLANT_H

#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPainter>
#include <QMovie>
#include <string>
using namespace std;
class Plant : public QGraphicsItem
{
public:
    int hp;
    int state;
    enum { Type = UserType + 1};
    Plant();
    ~Plant() override;
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
    int type() const override;
    void setMovie(QString path);
    void setInfo(string &info);
    void setName(string &Name);
    QMovie* getMovie();
    string getInfo();
    string getName();
protected:
    QMovie *movie;
    int atk;
    int counter;
    int time;
    string information;
    string plantname;
};

#endif // PLANT_H
