#ifndef ENTERNEXT_H
#define ENTERNEXT_H

#include <QMainWindow>
#include<NKUscene.h>
#include<classicscene.h>

class Enternext : public QMainWindow
{
    Q_OBJECT
public:
    explicit Enternext(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
    mambasence * Mambasence = NULL;
    classicscene * Classicscene = NULL;

signals:
};

#endif // ENTERNEXT_H
