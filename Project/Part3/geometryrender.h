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
#include "camera.h"
#include "3dstudio.h"
#include "openglwindow.h"
#include "lightsource.h"

using VertVec = QVector3D;
class GeometryRender : public OpenGLWindow
{
    Q_OBJECT
public:
    GeometryRender();

    std::string getUserInput(std::string prompt);

    void initialize() Q_DECL_OVERRIDE;
    void display() Q_DECL_OVERRIDE;
    void updatePMatrix(float near, float far, float right, float top);

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void mousePressEvent(QMouseEvent* mouseEvent) override;
    void mouseMoveEvent(QMouseEvent* mouseEvent) override;

private:
    std::unique_ptr<QOpenGLShaderProgram> program {};

    Object3D* obj;
    Camera* camera;
    LightSource* light;
    LightSource* ambientLight;

    QPoint mouseClickedPos;

    // OpenGL buffers
    QOpenGLVertexArrayObject vao;
    QOpenGLBuffer vBuffer;
    QOpenGLBuffer iBuffer;

    // OpenGL attribute locations
    GLuint locVertices;
    GLuint locModel;
    GLuint locView;
    GLuint locProj;

    GLuint loc_k_a;
    GLuint locLightPos;
    GLuint locAmbientLightRGB;
    GLuint locNormals;

    // Geometry data
    std::vector<VertVec> vertices, normals;
    std::vector<unsigned int> vertexIndices;
    std::vector<VertVec> castVecVec2VertVec(std::vector<std::vector<float>> vertices);
    std::vector<float> castVec3D2Vec(QVector3D vec);

    void updateObj();
    void updateCamera();
    void loadGeometry();

///////////
    void updateLightSourcePosition();
    void updateLightSourceColor();
    void updateAmbientLightSourceColor();
///////////

    OBJFileReader* reader;

public slots:
    void changeFOV(int fov);
    void changePFar(int d);
    void getNewObject(std::string filename);
    void changeToPerspective();
    void changeToParallel();
    void changeOblScale(double scale);
    void changeOblAngle(double angle);
    void changePlTop(double top);
    void changePlFar(int plfar);

    void changeLightX(float x);
    void changeLightY(float y);
    void changeLightZ(float z);

    void changeLightR(double r);
    void changeLightG(double g);
    void changeLightB(double b);
};

