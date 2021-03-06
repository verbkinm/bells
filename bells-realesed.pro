#-------------------------------------------------
#
# Project created by QtCreator 2016-03-01T20:46:18
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets network

TARGET = bells
TEMPLATE = app

SOURCES += main.cpp\
    left_panel/lesson.cpp \
    left_panel/lesson_melody.cpp \
    left_panel/listlesson.cpp \
    left_panel/scrollarea.cpp \
    left_panel/tabofsheduls.cpp \
    left_panel/tabtext.cpp \
    leftpanel.cpp \
    right_panel/rightpanel.cpp \
    mainwindow.cpp \
    settings/settings.cpp \
    settings/generals_settings.cpp \
    settings/tabsettings.cpp \
    log.cpp \
    settings/execprograms.cpp \
    settings/setdatetime.cpp \
    settings/mytimeedit.cpp \
    statusbar/statusbartime.cpp \
    settings/password.cpp \
    settings/server.cpp \
    tcpserver/tcpserver.cpp \
    tcpserver/datatosend.cpp \
    about.cpp

HEADERS  += \
    left_panel/lesson.h \
    left_panel/lesson_melody.h \
    left_panel/listlesson.h \
    left_panel/scrollarea.h \
    left_panel/tabofsheduls.h \
    left_panel/tabtext.h \
    leftpanel.h \
    mainwindow.h \
    right_panel/rightpanel.h \
    settings/settings.h \
    settings/generals_settings.h \
    settings/tabsettings.h \
    log.h \
    settings/execprograms.h \
    settings/setdatetime.h \
    settings/mytimeedit.h \
    statusbar/statusbartime.h \
    settings/password.h \
    settings/server.h \
    tcpserver/tcpserver.h \
    tcpserver/datatosend.h \
    about.h

FORMS += \
    left_panel/lesson.ui \
    left_panel/lesson_melody.ui \
    left_panel/tabtext.ui \
    settings/settings.ui \
    settings/generals_settings.ui \
    settings/execprograms.ui \
    settings/setdatetime.ui \
    settings/server.ui \
    about.ui

RESOURCES += \
    img.qrc

RC_FILE = file.rc

TRANSLATIONS = translation/arrowpad_ru_RU.ts

DISTFILES += \
    file.rc
