TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.c \
        player.c \
        renderer.c \
        window.c

HEADERS += \
    player.h \
    renderer.h \
    utils.h \
    window.h
