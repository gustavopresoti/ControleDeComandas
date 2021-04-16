TEMPLATE = app
QT += core gui sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

SOURCES += \
    lib/clientmanagement.cpp \
    lib/createclient.cpp \
    lib/createitem.cpp \
    lib/createorderpaper.cpp \
    lib/createorderpaperitem.cpp \
    lib/itemsmanagement.cpp \
    lib/orderpapermanagement.cpp \
    lib/createuser.cpp \
    lib/report.cpp \
    lib/showactiveorderpapers.cpp \
    lib/showitems.cpp \
    lib/showorderpapers.cpp \
    lib/showtotalrevenues.cpp \
    lib/showusers.cpp \
    lib/usermanagement.cpp \
    lib/dashboard.cpp \
    lib/loginwindow.cpp \
    main.cpp \

HEADERS += \
    lib/include/createitem.h \
    lib/include/report.h \
    lib/include/showusers.h \
    lib/include/createorderpaperitem.h \
    lib/include/createclient.h \
    lib/include/clientmanagement.h \
    lib/include/createorderpaper.h \
    lib/include/orderpapermanagement.h \
    lib/include/createuser.h \
    lib/include/usermanagement.h \
    lib/include/dashboard.h \
    lib/include/loginwindow.h \
    lib/include/showactiveorderpapers.h \
    lib/include/itemsmanagement.h \
    lib/include/showitems.h \
    lib/include/showtotalrevenues.h \
    lib/include/showorderpapers.h

FORMS += \
    ui/showorderpapers.ui \
    ui/showtotalrevenues.ui \
    ui/showitems.ui \
    ui/itemsmanagement.ui \
    ui/createitem.ui \
    ui/showactiveorderpapers.ui \
    ui/report.ui \
    ui/showusers.ui \
    ui/createorderpaperitem.ui \
    ui/createclient.ui \
    ui/clientmanagement.ui \
    ui/createorderpaper.ui \
    ui/orderpapermanagement.ui \
    ui/createuser.ui \
    ui/usermanagement.ui \
    ui/dashboard.ui \
    ui/loginwindow.ui \
