#-------------------------------------------------
#
# Project created by QtCreator 2015-02-17T11:08:10
#
#-------------------------------------------------

QT       += core gui webkitwidgets
QT += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = bdsInterface
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    formsubmain.cpp \
    formphotolist.cpp \
    formairplay.cpp \
    formbluetooth.cpp \
    formmusiclist.cpp \
    formmovielist.cpp \
    formexit.cpp \
    formhdmi.cpp \
    formipod.cpp \
    formsetting.cpp \
    formradio.cpp \
    formyoutube.cpp \
    formchrome.cpp \
    formpandora.cpp \
    formweather.cpp \
    formhdmovies.cpp \
    formdlna.cpp \
    formdisc.cpp \
    myqfilesystemmodel.cpp

HEADERS  += mainwindow.h \
    formsubmain.h \
    formphotolist.h \
    formairplay.h \
    formbluetooth.h \
    formmusiclist.h \
    formmovielist.h \
    formexit.h \
    formhdmi.h \
    formipod.h \
    formsetting.h \
    formradio.h \
    formyoutube.h \
    formchrome.h \
    formpandora.h \
    formweather.h \
    formhdmovies.h \
    formdlna.h \
    formdisc.h \
    myqfilesystemmodel.h

FORMS    += mainwindow.ui \
    formsubmain.ui \
    formphotolist.ui \
    formairplay.ui \
    formbluetooth.ui \
    formmusiclist.ui \
    formmovielist.ui \
    formexit.ui \
    formhdmi.ui \
    formipod.ui \
    formsetting.ui \
    formradio.ui \
    formyoutube.ui \
    formchrome.ui \
    formpandora.ui \
    formweather.ui \
    formhdmovies.ui \
    formdlna.ui \
    formdisc.ui

CONFIG += mobility resources_big
MOBILITY = 

RESOURCES += \
    res.qrc \
    ori_uis.qrc

DISTFILES += \
    bds_UIs/down.PNG \
    bds_UIs/up.PNG \
    GUIS/01.png \
    GUIS/02.png \
    GUIS/airplay.png \
    GUIS/bluetooth.png \
    GUIS/DLNA.png \
    GUIS/Music 2 (iPod) .png \
    GUIS/music.png \
    GUIS/music_DLNA.png \
    GUIS/option menu.png \
    GUIS/photo.png \
    GUIS/picture(thumbnail) Copy.png \
    GUIS/picture(thumbnail).png \
    GUIS/RADIO.png \
    GUIS/Source 2.png \
    GUIS/Video(Display).png \
    GUIS/video.png \
    GUIS/Music 2 (iPod) .png \
    GUIS/option menu.png \
    GUIS/picture(thumbnail) Copy.png \
    GUIS/Source 2.png \
    bds_UIs/downButton.png

