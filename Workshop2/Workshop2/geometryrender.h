/*
 *  Workshop 2
 *  Computer Graphics course
 *  Dept Computing Science, Umea University
 *  Stefan Johansson, stefanj@cs.umu.se
 */
#pragma once

#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>

#include "3dstudio.h"
#include "openglwindow.h"
#include "sphere.h"

class GeometryRender : public OpenGLWindow
{
public:
    GeometryRender();

    void initialize() Q_DECL_OVERRIDE;
    void display() Q_DECL_OVERRIDE;

protected:
    bool event(QEvent *event) Q_DECL_OVERRIDE;
private:
    std::unique_ptr<QOpenGLShaderProgram> program;

    // OpenGL buffers
    QOpenGLVertexArrayObject vao;
    QOpenGLBuffer vBuffer;
    QOpenGLBuffer iBuffer;

    // OpenGL attribute locations
    GLuint locVertices;
    GLuint locProj;
    GLuint locView;
    GLuint locTransform;
    GLuint locNormals;

    Sphere sphere;

    // All matrices initialized to the identity matrix
    QMatrix4x4 matProj;
    QMatrix4x4 matView;
    QMatrix4x4 matTransformation;

    void loadGeometry(void);
    void loadProjectionMatrix(void) const;
    void loadViewMatrix(void) const;
    void loadTransformation(void) const;
    void rotateTX(float);
};

