/*
 *  Workshop 1
 *  Computer Graphics course
 *  Dept Computing Science, Umea University
 *  Stefan Johansson, stefanj@cs.umu.se
 */
#pragma once

#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>
#include <QtGui/QVector2D>

#include "3dstudio.h"
#include "openglwindow.h"

//using VertVec = QVector2D;
using VertVec = QVector3D;
class GeometryRender : public OpenGLWindow
{
public:
    GeometryRender();

    void initialize() Q_DECL_OVERRIDE;
    void display() Q_DECL_OVERRIDE;

protected:
    void keyPressEvent(QKeyEvent *event) override;

private:
    std::unique_ptr<QOpenGLShaderProgram> program {};

    // OpenGL buffers
    QOpenGLVertexArrayObject vao;
    QOpenGLBuffer vBuffer;

    // OpenGL attribute locations
    GLuint locVertices;
    GLuint locModel;

    // Geometry data
    std::vector<VertVec> vertices;

    void update(void);
    void loadGeometry(std::string filename);
};

