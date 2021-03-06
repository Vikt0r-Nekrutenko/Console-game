TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        allocator.c \
        ammo.c \
        enemy.c \
        main.c \
        player.c \
        renderer.c \
        wave.c \
        weapon.c \
        window.c

HEADERS += \
    allocator.h \
    ammo.h \
    enemy.h \
    player.h \
    renderer.h \
    utils.h \
    wave.h \
    weapon.h \
    window.h
