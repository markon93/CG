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
    object3d.cpp \
    ass2widget.cpp \
    camera.cpp \
    ass3widget.cpp \
    qdoubleslider.cpp

HEADERS  += \
    openglwindow.h \
    geometryrender.h \
    3dstudio.h \
    objfilereader.h \
    object3d.h \
    ass2widget.h \
    camera.h \
    ass3widget.h \
    qdoubleslider.h

FORMS    += \
    ass2widget.ui \
    ass3widget.ui

DISTFILES += \
    vshader.glsl \
    fshader.glsl
