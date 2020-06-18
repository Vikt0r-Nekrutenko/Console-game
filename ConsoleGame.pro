TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        ammo.c \
        main.c \
        player.c \
        renderer.c \
        weapon.c \
        window.c

HEADERS += \
    ammo.h \
    player.h \
    renderer.h \
    utils.h \
    weapon.h \
    window.h
