#ifndef INTRODUCEZOMBIES_H
#define INTRODUCEZOMBIES_H
#include "zombie.h"
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>

namespace Ui {
class introducezombies;
}

class introducezombies : public QWidget
{
    Q_OBJECT

public:
    explicit introducezombies(QWidget *parent = nullptr);
    void showMovieAndInfo(Zombie*p,QString path);
    ~introducezombies();

private slots:
    void on_Exit_clicked();

    void on_basiczombies_clicked();

    void on_ConeheadZombie_clicked();

    void on_BucketheadZombie_clicked();

    void on_ScreenDoorZombie_clicked();

    void on_FootballZombie_clicked();

private:
    Ui::introducezombies *ui;
    QVBoxLayout *layout;  // 改为成员变量
    QLabel *label;
    QMovie *movie;
};

#endif // INTRODUCEZOMBIES_H
