/*
 *  Workshop 1
 *  Computer Graphics course
 *  Dept Computing Science, Umea University
 *  Stefan Johansson, stefanj@cs.umu.se
 */
#pragma once

#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>
#include <QtGui/QVector3D>
#include <object3d.h>
#include "3dstudio.h"
#include "openglwindow.h"

using VertVec = QVector3D;
class GeometryRender : public OpenGLWindow
{
public:
    GeometryRender();
    std::string getUserInput(std::string prompt);

    void initialize() Q_DECL_OVERRIDE;
    void display() Q_DECL_OVERRIDE;

protected:
    void keyPressEvent(QKeyEvent *event) override;

private:
    std::unique_ptr<QOpenGLShaderProgram> program {};

    Object3D* obj;

    // OpenGL buffers
    QOpenGLVertexArrayObject vao;
    QOpenGLBuffer vBuffer;
    QOpenGLBuffer iBuffer;

    // OpenGL attribute locations
    GLuint locVertices;
    GLuint locModel;

    // Geometry data
    std::vector<VertVec> vertices;
    std::vector<unsigned int> vertexIndices;
    std::vector<VertVec> castVecVec2VertVec(std::vector<std::vector<float>> vertices);

    void update();
    void loadGeometry();

    std::string filename;
};

