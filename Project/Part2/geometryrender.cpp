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
#include <QApplication>
#include <math.h>
#include "geometryrender.h"
#include "objfilereader.h"
using namespace std;

GeometryRender::GeometryRender()
    : vao(0)
    , vBuffer(QOpenGLBuffer::VertexBuffer)
    , iBuffer(QOpenGLBuffer::IndexBuffer){
}

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

    iBuffer.create();
    iBuffer.setUsagePattern(QOpenGLBuffer::StaticDraw);
    iBuffer.bind();

    // Get locations of the attributes in the shader
    // Corresponds to the GL calls glGetAttribLocation() and
    // glGetUniformLocation()
    locVertices = program->attributeLocation("vPosition");
    locModel = program->uniformLocation("M");



/////////////////////////////////////////
    locProj = program->uniformLocation("P");
    locView = program->uniformLocation("V");
////////////////////////////////////////

    // Initialize the camera
    camera = new Camera(getAspectRatio());

    program->setUniformValue(locView, camera->V);
    program->setUniformValue(locProj, camera->P);



    vao.release();
    program->release();

    // Standard object is a cube
    reader = new OBJFileReader();
    obj = new Object3D();
    obj->setVertices(reader->getVertices());
    obj->setVertexIndices(reader->getVertexIndices());
    obj->setTriangulation(reader->getTriangulation());
    obj->setTextures(reader->getTextures());
    obj->setNormals(reader->getNormals());

    loadGeometry();
}

// Update the object
void GeometryRender::updateObj(){
    program->bind();

    program->setUniformValue(locModel, obj->matModel);
    program->release();

    ////////////////////////
    OpenGLWindow::displayNow();


}

// Update the camera
void GeometryRender::updateCamera(){
    program->bind();
    ////////////////////////
    program->setUniformValue(locView, camera->V);
    program->setUniformValue(locProj, camera->P);

    program->release();

    ////////////////////////
    OpenGLWindow::displayNow();
}



// Get new object from GUI
void GeometryRender::getNewObject(string filename){
    obj->reset();  // Set model matrix to identity matrix
    reader->updateData(filename); // Read in data from new file
    obj->setVertices(reader->getVertices()); // Update data in object
    obj->setVertexIndices(reader->getVertexIndices());
    obj->setTriangulation(reader->getTriangulation());
    obj->setTextures(reader->getTextures());
    obj->setNormals(reader->getNormals());
    loadGeometry();
    updateObj();
}


// Handle keyboard events
void GeometryRender::keyPressEvent(QKeyEvent *keyEvent){
    float alpha = 10;
    float t = 0.1;
    float scaleUp = 1.1;
    float scaleDown = 0.9;
    float ct = 0.05;
    switch (keyEvent->key()){
    case Qt::Key_Left:
        obj->rotateX(-alpha);
        updateObj();
        break;
    case Qt::Key_Right:
        obj->rotateX(alpha);
        updateObj();
        break;
    case Qt::Key_Up:
        obj->rotateY(alpha);
        updateObj();
        break;
    case Qt::Key_Down:
        obj->rotateY(-alpha);
        updateObj();
        break;
    case Qt::Key_I:
        obj->translate(0.0,t,0.0);
        updateObj();
        break;
    case Qt::Key_K:
        obj->translate(0.0,-t,0.0);
        updateObj();
        break;
    case Qt::Key_L:
        obj->translate(t,0.0,0.0);
        updateObj();
        break;
    case Qt::Key_J:
        obj->translate(-t,0.0,0.0);
        updateObj();
        break;
    case Qt::Key_Plus:
        obj->scale(scaleUp, scaleUp, scaleUp);
        updateObj();
        break;
    case Qt::Key_Minus:
        obj->scale(scaleDown, scaleDown, scaleDown);
        updateObj();
        break;
    case Qt::Key_W:
        camera->updatePos(0.0, ct, 0.0);
        updateCamera();
        break;
    case Qt::Key_S:
        camera->updatePos(0.0, -ct, 0.0);
        updateCamera();
        break;
    case Qt::Key_A:
        camera->updatePos(-ct, 0.0, 0.0);
        updateCamera();
        break;
    case Qt::Key_D:
        camera->updatePos(ct, 0.0, 0.0);
        updateCamera();
        break;
    case Qt::Key_Z:
        camera->updatePos(0.0, 0.0, -ct);
        updateCamera();
        break;
    case Qt::Key_X:
        camera->updatePos(0.0, 0.0, ct);
        updateCamera();
        break;
    default:
        keyEvent -> ignore();
        break;
    }
}


// Register mouse clicks, register the position of the mouse
void GeometryRender::mousePressEvent(QMouseEvent *mouseEvent){
    mouseClickedPos = mouseEvent->pos();
}

// Rotate the camera while the mouse is pressed and moved
void GeometryRender::mouseMoveEvent(QMouseEvent *mouseEvent){
    if(mouseEvent->buttons() && Qt::LeftButton){

        int dx = mouseEvent->x() - mouseClickedPos.x();
        int dy = mouseEvent->y() - mouseClickedPos.y();

        camera->pitch(dy/6);
        camera->yaw(dx/6);
        updateCamera();

        mouseClickedPos = mouseEvent->pos();

    }
}

void GeometryRender::loadGeometry(){
    program->bind();
    vao.bind();

    // Set the pointers of locVertices_ to the right places
    // Can also call program_->setAttributeBuffer() but then the values are normalized
    glVertexAttribPointer(locVertices, 3, GL_FLOAT, GL_TRUE, 0, BUFFER_OFFSET(0));
    glEnableVertexAttribArray(locVertices);

    program->setUniformValue(locModel, obj->matModel);
    vector<vector<float>> temp = obj->getVertices();
    vertices = castVecVec2VertVec(temp);

    vertexIndices = obj->getVertexIndices();

    // Load data to the array buffer
    // Corresponds to the GL call glBufferData()
    size_t vSize = vertices.size()*sizeof(float)*3;
    vBuffer.allocate(vSize);

    vBuffer.write(0, vertices.data(), vSize);

    size_t iSize = vertexIndices.size()*sizeof(unsigned int);

    cout << vertexIndices.size() << endl;
    cout << iSize << endl;

    for(int I = 0; I<(int)vertexIndices.size();I++){
        cout << vertexIndices[I] << endl;
    }


    iBuffer.allocate(iSize);
    iBuffer.write(0, vertexIndices.data(), iSize);

    vao.release();
    program->release();
}

/* Transform a vector of vectors to a vector with VertVecs */
vector<VertVec> GeometryRender::castVecVec2VertVec(vector<vector<float>> vec){
    vector<VertVec> newVec;
    vector<vector<float>>::iterator it;
    for (it = vec.begin(); it != vec.end(); it++){
        vector<float> row = *it;
        newVec.push_back(VertVec(row[0],row[1],row[2]));
    }
    return newVec;
}

/* Transform a vector of vectors to a vector with VertVecs */
vector<float> GeometryRender::castVec3D2Vec(QVector3D vec){
    vector<float> newVec;
    for (int i = 0; i < 3; i++){
        newVec.push_back(vec[i]);
    }
    return newVec;
}

// Render object
void GeometryRender::display(){
    program->bind();
    vao.bind();

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glDrawElements(GL_TRIANGLES, vertexIndices.size(), GL_UNSIGNED_INT, BUFFER_OFFSET(0));
    glFlush();

    vao.release();
    program->release();
}

/* Functions passing signals from the window to the camera */

// Change the field of view
void GeometryRender::changeFOV(int fov){
    camera->setFOV(fov);
    updateCamera();
}

// Change the distance to the back plane of the frustum
void GeometryRender::changePFar(int d){
    camera->setPFar(d);
    updateCamera();
}

// Change the projection mode to perspective
void GeometryRender::changeToPerspective(){
    camera->setMode("Perspective");
    camera->setFOV(60);
    camera->setPFar(500);
    updateCamera();
}

// Change the projection mode to parallel
void GeometryRender::changeToParallel(){
    camera->setMode("Parallel");
    camera->setPlTop(1.0);
    camera->setPFar(500);
    camera->setOblScale(0.0);
    camera->setOblAngle(45.0);
    updateCamera();
}

// Change the oblique scale for parallel projection
void GeometryRender::changeOblScale(double scale){
    camera->setOblScale(scale);
    updateCamera();
}

// Change the oblique angle for parallel projection
void GeometryRender::changeOblAngle(double angle){
    camera->setOblAngle(angle);
    updateCamera();
}

// Change the oblique angle for parallel projection
void GeometryRender::changePlTop(double top){
    camera->setPlTop(top);
    updateCamera();
}

// Change the oblique angle for parallel projection
void GeometryRender::changePlFar(int plfar){
    camera->setPFar(plfar);
    updateCamera();
}


/*
  cout << "Indices\n\n";
        cout << "size: " <<vertexIndices.size() << endl;
        vector<unsigned int>::iterator it;
        for (it = vertexIndices.begin(); it != vertexIndices.end(); it++){
            cout << *it;
            cout << endl;
        }

        cout <<endl;
        cout << "Vertices" << endl << endl;

        cout << "size: " << vertices.size() << endl;
        vector<VertVec>::iterator IT;
        for (IT = vertices.begin(); IT != vertices.end(); IT++){
            VertVec row = *IT;
            cout << row[0] << " " << row[1] << " " << row[2];
            cout << endl;
        }
*/









