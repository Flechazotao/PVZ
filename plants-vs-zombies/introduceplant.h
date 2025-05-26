#ifndef INTRODUCEPLANT_H
#define INTRODUCEPLANT_H

#include <QWidget>

namespace Ui {
class introduceplant;
}

class introduceplant : public QWidget
{
    Q_OBJECT

public:
    explicit introduceplant(QWidget *parent = nullptr);
    ~introduceplant();

private slots:
    void on_Exit_clicked();

    void on_sunFlower_clicked();

private:
    Ui::introduceplant *ui;
};

#endif // INTRODUCEPLANT_H
