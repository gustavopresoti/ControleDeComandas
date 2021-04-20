TEMPLATE = app
QT += core gui sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

SOURCES += \
    lib/deleteclient.cpp \
    lib/findclient.cpp \
    lib/createclient.cpp \
    lib/clientmanagement.cpp \
    lib/showitems.cpp \
    lib/showusers.cpp \
    lib/showtotalrevenues.cpp \
    lib/showorderpapers.cpp \
    lib/report.cpp \
    lib/deleteitem.cpp \
    lib/createitem.cpp \
    lib/itemsmanagement.cpp \
    lib/showactiveorderpapers.cpp \
    lib/deleteorderpaper.cpp \
    lib/findorderpaper.cpp \
    lib/createorderpaper.cpp \
    lib/createorderpaperitem.cpp \
    lib/orderpapermanagement.cpp \
    lib/deleteuser.cpp \
    lib/finduser.cpp \
    lib/createuser.cpp \
    lib/usermanagement.cpp \
    lib/dashboard.cpp \
    lib/loginwindow.cpp \
    main.cpp \

HEADERS += \
    lib/include/deleteclient.h \
    lib/include/findclient.h \
    lib/include/createclient.h \
    lib/include/clientmanagement.h \
    lib/include/showitems.h \
    lib/include/showusers.h \
    lib/include/showtotalrevenues.h \
    lib/include/showorderpapers.h \
    lib/include/report.h \
    lib/include/deleteitem.h \
    lib/include/createitem.h \
    lib/include/itemsmanagement.h \
    lib/include/showactiveorderpapers.h \
    lib/include/deleteorderpaper.h \
    lib/include/findorderpaper.h \
    lib/include/createorderpaper.h \
    lib/include/createorderpaperitem.h \
    lib/include/orderpapermanagement.h \
    lib/include/deleteuser.h \
    lib/include/finduser.h \
    lib/include/createuser.h \
    lib/include/usermanagement.h \
    lib/include/dashboard.h \
    lib/include/loginwindow.h \

FORMS += \
    ui/deleteclient.ui \
    ui/findclient.ui \
    ui/createclient.ui \
    ui/clientmanagement.ui \
    ui/showitems.ui \
    ui/showusers.ui \
    ui/showtotalrevenues.ui \
    ui/showorderpapers.ui \
    ui/report.ui \
    ui/deleteitem.ui \
    ui/createitem.ui \
    ui/itemsmanagement.ui \
    ui/showactiveorderpapers.ui \
    ui/deleteorderpaper.ui \
    ui/findorderpaper.ui \
    ui/createorderpaper.ui \
    ui/createorderpaperitem.ui \
    ui/orderpapermanagement.ui \
    ui/deleteuser.ui \
    ui/finduser.ui \
    ui/createuser.ui \
    ui/usermanagement.ui \
    ui/dashboard.ui \
    ui/loginwindow.ui \
