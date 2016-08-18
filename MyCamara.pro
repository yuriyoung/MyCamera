#-------------------------------------------------
#
# Project created by QtCreator 2013-11-17T14:03:22
# @file mycamara.cpp
# @auth: Yuri Young<yuri.young@qq.com>
# @date: 2013-11-17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyCamara
TEMPLATE = app

SOURCES += main.cpp\
        MainWindow.cpp \
    MyCamera.cpp

HEADERS  += MainWindow.h \
    MyCamera.h

FORMS    += MainWindow.ui

#opencv
INCLUDEPATH += D:/3rdParty/opencv/build/include \
            D:/3rdParty/opencv/build/include/opencv \
            D:/3rdParty/opencv/build/include/opencv2

DEPENDPATH += D:/3rdParty/opencv/build/x86/vc10 \

LIBS += -LD:/3rdParty/opencv/build/x86/vc10/lib/

win32: LIBS += -lopencv_core247d \
            -lopencv_highgui247d \
            -lopencv_photo247d \
            -lopencv_imgproc247d \
            -lshell32

