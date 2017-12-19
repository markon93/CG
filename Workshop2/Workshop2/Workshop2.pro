#-------------------------------------------------
#
# Project created by QtCreator 2016-10-18T12:10:47
#
#-------------------------------------------------

QT       += core gui
CONFIG   += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Workshop2
TEMPLATE = app


SOURCES += main.cpp\
    openglwindow.cpp \
    geometryrender.cpp \
    sphere.cpp

HEADERS  += \
    openglwindow.h \
    geometryrender.h \
    sphere.h \
    3dstudio.h

FORMS    +=

DISTFILES += \
    vshader.glsl \
    fshader.glsl
