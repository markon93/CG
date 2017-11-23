#-------------------------------------------------
#
# Project created by QtCreator 2016-10-18T12:10:47
#
#-------------------------------------------------

QT       += core gui
CONFIG   += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Workshop1
TEMPLATE = app


SOURCES +=\
    openglwindow.cpp \
    geometryrender.cpp \
    main.cpp \
    objfilereader.cpp \
    object3d.cpp

HEADERS  += \
    openglwindow.h \
    geometryrender.h \
    3dstudio.h \
    objfilereader.h \
    object3d.h

FORMS    +=

DISTFILES += \
    vshader.glsl \
    fshader.glsl
