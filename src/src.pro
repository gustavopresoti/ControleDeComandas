TEMPLATE = app
QT += core gui sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

SOURCES += \
    lib/clientmanagement.cpp \
    lib/createclient.cpp \
    lib/createorderpaper.cpp \
    lib/createorderpaperitem.cpp \
    lib/orderpapermanagement.cpp \
    lib/createuser.cpp \
    lib/usermanagement.cpp \
    lib/dashboard.cpp \
    lib/loginwindow.cpp \
    main.cpp \

HEADERS += \
    lib/include/createorderpaperitem.h \
    lib/include/createclient.h \
    lib/include/clientmanagement.h \
    lib/include/createorderpaper.h \
    lib/include/orderpapermanagement.h \
    lib/include/createuser.h \
    lib/include/usermanagement.h \
    lib/include/dashboard.h \
    lib/include/loginwindow.h \

FORMS += \
    ui/createorderpaperitem.ui \
    ui/createclient.ui \
    ui/clientmanagement.ui \
    ui/createorderpaper.ui \
    ui/orderpapermanagement.ui \
    ui/createuser.ui \
    ui/usermanagement.ui \
    ui/dashboard.ui \
    ui/loginwindow.ui \
