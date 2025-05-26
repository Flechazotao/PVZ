#include <QApplication>
#include "loginscene.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    loginscene w;
    w.setFixedSize(900, 600);
    w.setWindowTitle("植物大战僵尸");
    w.show();
    return a.exec();
}
