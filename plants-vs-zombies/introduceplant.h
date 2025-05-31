#ifndef INTRODUCEPLANT_H
#define INTRODUCEPLANT_H
#include "plant.h"
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>

namespace Ui {
class introduceplant;
}

class introduceplant : public QWidget
{
    Q_OBJECT

public:
    explicit introduceplant(QWidget *parent = nullptr);
    void showMovieAndInfo(Plant*p, QString path);
    ~introduceplant();

private slots:
    void on_Exit_clicked();
    void on_sunFlower_clicked();

    void on_wallnut_clicked();

    void on_peashooter_clicked();

    void on_potatomine_clicked();

    void on_repeaterpea_clicked();

    void on_snowpea_clicked();

    void on_cherrybomb_clicked();

    void on_lilypad_clicked();

private:
    Ui::introduceplant *ui;
    QVBoxLayout *layout;  // 改为成员变量
    QLabel *label;
    QMovie *movie;
};

#endif // INTRODUCEPLANT_H
