QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/creditswindow.cpp \
    src/fourgame.cpp \
    src/help_four.cpp \
    src/help_numerical.cpp \
    src/help_pyramid.cpp \
    src/help_sus.cpp \
    src/help_ultimate.cpp \
    src/help_word.cpp \
    src/helpwindow.cpp \
    main.cpp \
    src/mainwindow.cpp \
    src/menuwindow.cpp \
    src/numericalgame.cpp \
    src/pyramidgame.cpp \
    src/susgame.cpp \
    src/ultimategame.cpp \
    src/win.cpp \
    src/draw.cpp \
    src/fivebyfivegame.cpp \
    src/miseregame.cpp \
    src/wordgame.cpp

HEADERS += \
    include/creditswindow.h \
    include/fourgame.h \
    include/help_four.h \
    include/help_numerical.h \
    include/help_pyramid.h \
    include/help_sus.h \
    include/help_ultimate.h \
    include/help_word.h \
    include/helpwindow.h \
    include/mainwindow.h \
    include/menuwindow.h \
    include/numericalgame.h \
    include/pyramidgame.h \
    include/susgame.h \
    include/ultimategame.h \
    include/win.h \
    include/draw.h \
    include/fivebyfivegame.h \
    include/miseregame.h \
    include/wordgame.h

FORMS += \
    forms/creditswindow.ui \
    forms/fourgame.ui \
    forms/help_four.ui \
    forms/help_numerical.ui \
    forms/help_pyramid.ui \
    forms/help_sus.ui \
    forms/help_ultimate.ui \
    forms/help_word.ui \
    forms/helpwindow.ui \
    forms/mainwindow.ui \
    forms/menuwindow.ui \
    forms/numericalgame.ui \
    forms/pyramidgame.ui \
    forms/susgame.ui \
    forms/ultimategame.ui \
    forms/win.ui \
    forms/draw.ui \
    forms/miseregame.ui \
    forms/fivebyfivegame.ui \
    forms/wordgame.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

RC_FILE = app.rc
