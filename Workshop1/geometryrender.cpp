/*
 *  Workshop 1
 *  Computer Graphics course
 *  Dept Computing Science, Umea University
 *  Stefan Johansson, stefanj@cs.umu.se
 */
#include <QKeyEvent>
#include <QDebug>
#include <iostream>
#include <string>
#include "geometryrender.h"
#include "objfilereader.h"
using namespace std;

GeometryRender::GeometryRender()
    : vao(0)
    , vBuffer(QOpenGLBuffer::VertexBuffer){
}

QMatrix4x4 matModel;
string filename;
OBJFileReader* reader = new OBJFileReader();

// Initialize OpenGL
void GeometryRender::initialize(){

    OpenGLWindow::initialize();

    // Enable depth test
    glEnable(GL_DEPTH_TEST);

    // Create and initialize a program object with shaders
    program = initProgram(this, "vshader.glsl", "fshader.glsl");

    // Installs the program object as part of current rendering state
    // Corresponds to the GL call glUseProgram()
    program->bind();

    // Creat a vertex array object
    // Corresponds to the GL calls glGenVertexArrays() and glBindVertexArray()
    vao.create();
    vao.bind();

    // Create vertex buffer in the shared display list space and
    // bind it as VertexBuffer (GL_ARRAY_BUFFER)
    // Corresponds to the GL calls glGenBuffers() and glBindBuffer()
    vBuffer.create();
    vBuffer.setUsagePattern(QOpenGLBuffer::StaticDraw);
    vBuffer.bind();

    // Get locations of the attributes in the shader
    // Corresponds to the GL calls glGetAttribLocation() and
    // glGetUniformLocation()
    locVertices = program->attributeLocation("vPosition");
    locModel = program->uniformLocation("M");

    vao.release();
    program->release();
    loadGeometry("sphere_large.obj");
}

// Update the model matrix
void GeometryRender::update(void){
    program->bind();
    vao.bind();

    program->setUniformValue(locModel, matModel);
    OpenGLWindow::displayNow();

    vao.release();
    program->release();
}

// Handle keyboard events
void GeometryRender::keyPressEvent(QKeyEvent *keyEvent){
    switch (keyEvent->key()){
    case Qt::Key_Left:
        matModel.rotate(-10.0, 0.0, 1.0, 0.0);
        break;
    case Qt::Key_Right:
        matModel.rotate(10.0, 0.0, 1.0, 0.0);
        break;
    case Qt::Key_Up:
        matModel.rotate(10.0, 1.0, 0.0, 0.0);
        break;
    case Qt::Key_Down:
        matModel.rotate(-10.0, 1.0, 0.0, 0.0);
        break;
    case Qt::Key_I:
        matModel.translate(0.0,0.1);
        break;
    case Qt::Key_K:
        matModel.translate(0.0,-0.1);
        break;
    case Qt::Key_L:
        matModel.translate(0.1,0.0);
        break;
    case Qt::Key_J:
        matModel.translate(-0.1,0.0);
        break;
    case Qt::Key_O:
        filename = reader->getUserInput("Enter filename: ");
        //Reset transformations etc
        loadGeometry(filename);
        break;
    default:
        keyEvent -> ignore();
        break;
    }
    update();
}

void GeometryRender::loadGeometry(string filename){
    reader -> formatData(filename);
    QVector<QVector<float>> vertexList = reader -> getVertices();

    // Define vertices in array
    for (QVector<QVector<float>>::iterator it = vertexList.begin() ; it != vertexList.end(); ++it){
        QVector<float> row = *it;
        vertices.push_back(VertVec(row[0],row[1],row[2]));
    }

    cout <<endl;
    cout << "Vertices" << endl << endl;


    program->bind();
    vao.bind();

    // Set the pointers of locVertices_ to the right places
    // Can also call program_->setAttributeBuffer() but then the values are normalized
    glVertexAttribPointer(locVertices, 3, GL_FLOAT, GL_TRUE, 0, BUFFER_OFFSET(0));
    glEnableVertexAttribArray(locVertices);

    program->setUniformValue(locModel, matModel);

    // Load data to the array buffer
    // Corresponds to the GL call glBufferData()
    size_t vSize = vertices.size()*sizeof(VertVec);
    vBuffer.allocate(vSize);
    vBuffer.write(0, vertices.data(), vSize);

    vao.release();
    program->release();
}

// Render object
void GeometryRender::display(){
    program->bind();
    vao.bind();

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glDrawArrays(GL_LINE_LOOP, 0, vertices.size());
    glFlush();

    vao.release();
    program->release();
}
