#ifndef ENTER_H
#define ENTER_H

#include <QMainWindow>
#include<enternext.h>

class Enter : public QMainWindow
{
    Q_OBJECT
public:
    explicit Enter(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
    Enternext * enternext=NULL;

signals:
};

#endif // ENTER_H
