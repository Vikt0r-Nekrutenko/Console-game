TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        bullet.c \
        main.c \
        pistol.c \
        player.c \
        renderer.c \
        window.c

HEADERS += \
    bullet.h \
    pistol.h \
    player.h \
    renderer.h \
    utils.h \
    window.h
