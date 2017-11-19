/*
 *  Workshop 1
 *  Computer Graphics course
 *  Dept Computing Science, Umea University
 *  Stefan Johansson, stefanj@cs.umu.se
 */
#pragma once

#include <QWindow>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include "3dstudio.h"

#define BUFFER_OFFSET(i) ((char *)NULL + (i))

class QPainter;
class QOpenGLContext;
class QOpenGLPaintDevice;

class OpenGLWindow : public QWindow, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    explicit OpenGLWindow(QWindow *parent = 0);

    virtual void display(QPainter *painter);
    virtual void display();

    virtual void initialize();

public slots:
    void displayNow();

protected:
    bool event(QEvent *event) Q_DECL_OVERRIDE;
    void exposeEvent(QExposeEvent *event) Q_DECL_OVERRIDE;

    std::unique_ptr<QOpenGLShaderProgram> initProgram(QObject *parent, const QString &vShaderFile, const QString &fShaderFile) const;

private:
    std::unique_ptr<QOpenGLContext> context {};
    std::shared_ptr<QOpenGLPaintDevice> device {};
};
