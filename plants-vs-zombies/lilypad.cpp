#include "lilypad.h"

string name="莲叶";
string info="莲叶可以让你种植非水生植物在它上面。\n特点：非水生植物可以种植在它上面\n必须种植在水面\n莲叶从不抱怨，它也从来不想知道发生了什么事。\n在它身上种植物，它也不会说什么。\n难道，它有什么惊奇想法或者可怕的秘密？\n没人知道。\n莲叶把这些都埋藏在心底。\n冷却：7.5秒\t花费：25";

lilypad::lilypad() {
    hp = 300;
    time = int(10.0 * 1000 / 33);
    setMovie(":/pvz.res/LilyPad.png");
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
