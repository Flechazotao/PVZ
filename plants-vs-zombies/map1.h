#ifndef MAP1_H
#define MAP1_H

#include <QWidget>

namespace Ui {
class MAP1;
}

class MAP1 : public QWidget
{
    Q_OBJECT

public:
    explicit MAP1(QWidget *parent = nullptr);
    ~MAP1();

private:
    Ui::MAP1 *ui;
};

#endif // MAP1_H
