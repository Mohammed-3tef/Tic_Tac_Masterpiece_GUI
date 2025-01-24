QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    creditswindow.cpp \
    help_pyramid.cpp \
    help_sus.cpp \
    help_ultimate.cpp \
    helpwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    menuwindow.cpp \
    pyramidgame.cpp \
    susgame.cpp \
    ultimategame.cpp \
    win.cpp \
    draw.cpp \
    wordgame.cpp

HEADERS += \
    creditswindow.h \
    help_pyramid.h \
    help_sus.h \
    help_ultimate.h \
    helpwindow.h \
    mainwindow.h \
    menuwindow.h \
    pyramidgame.h \
    susgame.h \
    ultimategame.h \
    win.h \
    draw.h \
    wordgame.h

FORMS += \
    creditswindow.ui \
    help_pyramid.ui \
    help_sus.ui \
    help_ultimate.ui \
    helpwindow.ui \
    mainwindow.ui \
    menuwindow.ui \
    pyramidgame.ui \
    susgame.ui \
    ultimategame.ui \
    win.ui \
    draw.ui \
    wordgame.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

RC_FILE = app.rc
