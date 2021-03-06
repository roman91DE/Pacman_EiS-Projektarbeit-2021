QT       += core gui multimedia


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ConsoleWindow.cpp \
    alien.cpp \
    game.cpp \
    gamewindow.cpp \
    main.cpp \
    mainmenu.cpp \
    map.cpp \
    player.cpp

HEADERS += \
    ConsoleWindow.h \
    alien.h \
    game.h \
    gamewindow.h \
    mainmenu.h \
    map.h \
    player.h

FORMS += \
    mainmenu.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    txt_maps/customLevel.txt \
    txt_maps/level1.txt \
    txt_maps/level2.txt \
    txt_maps/level3.txt \


RESOURCES += \
    wavSounds.qrc
