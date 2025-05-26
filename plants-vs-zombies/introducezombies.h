#ifndef INTRODUCEZOMBIES_H
#define INTRODUCEZOMBIES_H

#include <QWidget>

namespace Ui {
class introducezombies;
}

class introducezombies : public QWidget
{
    Q_OBJECT

public:
    explicit introducezombies(QWidget *parent = nullptr);
    ~introducezombies();

private slots:
    void on_Exit_clicked();

    void on_basiczombies_clicked();

private:
    Ui::introducezombies *ui;
};

#endif // INTRODUCEZOMBIES_H
