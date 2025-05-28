QT       += core gui
QT       += core gui multimedia multimediawidgets
QT       += multimedia
CONFIG += resources_big

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    NKUscene.cpp \
    basiczombie.cpp \
    bucketzombie.cpp \
    button.cpp \
    card.cpp \
    cherrybomb.cpp \
    classcard.cpp \
    classicmap.cpp \
    classicmower.cpp \
    classicpea.cpp \
    classicpeashooter.cpp \
    classicrepeater.cpp \
    classicscene.cpp \
    classicshop.cpp \
    classicsnowpea.cpp \
    classicsun.cpp \
    classicsunflower.cpp \
    conezombie.cpp \
    footballzombie.cpp \
    introduceplant.cpp \
    introducezombies.cpp \
    loginscene.cpp \
    main.cpp \
    map.cpp \
    mower.cpp \
    mypushbutton.cpp \
    other.cpp \
    pea.cpp \
    peashooter.cpp \
    plant.cpp \
    potatomine.cpp \
    repeater.cpp \
    screenzombie.cpp \
    shop.cpp \
    shoval.cpp \
    snowpea.cpp \
    sun.cpp \
    sunflower.cpp \
    wallnut.cpp \
    zombie.cpp

HEADERS += \
    NKUscene.h \
    basiczombie.h \
    bucketzombie.h \
    button.h \
    card.h \
    cherrybomb.h \
    classcard.h \
    classicmap.h \
    classicmower.h \
    classicpea.h \
    classicpeashooter.h \
    classicrepeater.h \
    classicscene.h \
    classicshop.h \
    classicsnowpea.h \
    classicsun.h \
    classicsunflower.h \
    conezombie.h \
    footballzombie.h \
    introduceplant.h \
    introducezombies.h \
    loginscene.h \
    map.h \
    mower.h \
    mypushbutton.h \
    other.h \
    pea.h \
    peashooter.h \
    plant.h \
    potatomine.h \
    repeater.h \
    screenzombie.h \
    shop.h \
    shovel.h \
    snowpea.h \
    sun.h \
    sunflower.h \
    wallnut.h \
    zombie.h

FORMS += \
    introduceplant.ui \
    introducezombies.ui \
    loginscene.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
