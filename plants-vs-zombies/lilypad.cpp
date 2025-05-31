#include "lilypad.h"

string name="";
string info="";

lilypad::lilypad() {
    hp = 300;
    time = int(10.0 * 1000 / 33);
    setMovie(":/pvz.res/SunFlower.gif");
    setName(name);
    setInfo(info);
}
void lilypad::advance(int phase) {
    if (!phase)
        return;
    update();
    if (hp <= 0)
        delete this;

};
