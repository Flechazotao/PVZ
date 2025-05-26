#ifndef LOGINSCENE_H
#define LOGINSCENE_H

#include <QWidget>

namespace Ui {
class loginscene;
}

class loginscene : public QWidget
{
    Q_OBJECT

public:
    explicit loginscene(QWidget *parent = nullptr);
    ~loginscene();

private slots:
    void on_login1_clicked();

private:
    Ui::loginscene *ui;
};

#endif // LOGINSCENE_H
