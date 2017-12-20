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
    locNormals = program->attributeLocation("vNormal");

/////
    loc_k_a = program->uniformLocation("k_a");
    loc_k_d = program->uniformLocation("k_d");
    loc_k_s = program->uniformLocation("k_s");
    locLightPos = program->uniformLocation("lightPosition");
    locLightLuminance = program->uniformLocation("lightLuminance");
    locAmbientLightRGB = program->uniformLocation("ambientLightRGB");
/////

    locModel = program->uniformLocation("M");
    locProj = program->uniformLocation("P");
    locView = program->uniformLocation("V");

/////////
    // Initialize the light
    ambientLight = new LightSource(QVector4D(0.0,0.0,0.0,0.0), 0.2, 0.2, 0.2);
    program->setUniformValue(locAmbientLightRGB, ambientLight->getRGB());

    light = new LightSource(QVector4D(0.0,1.0,5.0,1.0), 0.7, 0.7, 0.7);
    program->setUniformValue(locLightPos, light->getPosition());
    program->setUniformValue(locLightLuminance, light->getRGB());
/////////

    // Initialize the camera
    camera = new Camera(getAspectRatio());
    program->setUniformValue(locView, camera->V);
    program->setUniformValue(locProj, camera->P);

    // Standard object is a cube
    reader = new OBJFileReader();
    obj = new Object3D();

///////////
    // Initialize the material
    program->setUniformValue(loc_k_a, obj->getK_A());
    program->setUniformValue(loc_k_d, obj->getK_D());
    program->setUniformValue(loc_k_s, obj->getK_S());
///////////

    obj->setVertices(reader->getVertices());
    obj->setVertexIndices(reader->getVertexIndices());
    obj->setTriangulation(reader->getTriangulation());
    obj->setTextures(reader->getTextures());
    obj->setNormals(reader->getVertexNormals());

    vao.release();
    program->release();

    loadGeometry();
}

// Update the object
void GeometryRender::updateObj(){
    program->bind();
    program->setUniformValue(locModel, obj->matModel);
    program->release();
    OpenGLWindow::displayNow();
}

// Update the camera
void GeometryRender::updateCamera(){
    program->bind();
    program->setUniformValue(locView, camera->V);
    program->setUniformValue(locProj, camera->P);
    program->release();
    OpenGLWindow::displayNow();
}

// Update a light source position
void GeometryRender::updateLightSourcePosition(){
    program->bind();
    program->setUniformValue(locLightPos, light->getPosition());
    program->release();
    OpenGLWindow::displayNow();
}

// Update the luminance of a light source
void GeometryRender::updateLightLuminance(){
    program->bind();
    program->setUniformValue(locLightLuminance, light->getRGB());
    program->release();
    OpenGLWindow::displayNow();
}

// Update the color of a light source
void GeometryRender::updateAmbientLightSourceColor(){
    program->bind();
    program->setUniformValue(locAmbientLightRGB, ambientLight->getRGB());
    program->release();
    OpenGLWindow::displayNow();
}

// Update the ambient parameter of the object's material
void GeometryRender::updateMaterialAmbience(){
    program->bind();
    program->setUniformValue(loc_k_a, obj->getK_A());
    program->release();
    OpenGLWindow::displayNow();
}

// Update the diffuse parameter of the object's material
void GeometryRender::updateMaterialDiffusivity(){
    program->bind();
    program->setUniformValue(loc_k_d, obj->getK_D());
    program->release();
    OpenGLWindow::displayNow();
}

// Update the specular parameter of the object's material
void GeometryRender::updateMaterialSpecularity(){
    program->bind();
    program->setUniformValue(loc_k_s, obj->getK_S());
    program->release();
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
    obj->setNormals(reader->getVertexNormals());
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
    vector<vector<float>> tempVertices = obj->getVertices();
////////////
    vector<vector<float>> tempNormals = obj->getNormals();
/////////////

    vertices = castVecVec2VertVec(tempVertices);
    normals = castVecVec2VertVec(tempNormals);

    vertexIndices = obj->getVertexIndices();

    // Load data to the array buffer
    // Corresponds to the GL call glBufferData()
    size_t vSize = vertices.size()*sizeof(float)*3;
    size_t nSize = normals.size()*sizeof(float)*3;

    glVertexAttribPointer(locNormals, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(vSize));
    glEnableVertexAttribArray(locNormals);

    vBuffer.allocate(vSize + nSize);
    vBuffer.write(0, vertices.data(), vSize);
    vBuffer.write(vSize, normals.data(), nSize);

    size_t iSize = vertexIndices.size()*sizeof(unsigned int);

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

// Change the position of the light
void GeometryRender::changeLightX(float x){
    QVector4D currpos = light->getPosition();
    light->setPosition(x,currpos[1],currpos[2],0);
    updateLightSourcePosition();
}
void GeometryRender::changeLightY(float y){
    QVector4D currpos = light->getPosition();
    light->setPosition(currpos[0],y,currpos[2],0);
    updateLightSourcePosition();
}
void GeometryRender::changeLightZ(float z){
    QVector4D currpos = light->getPosition();
    light->setPosition(currpos[0],currpos[1],z,0);
    updateLightSourcePosition();
}

// Change the color of the light source
void GeometryRender::changeLightLuminanceR(double r){
    light->setR(r);
    updateLightLuminance();
}
void GeometryRender::changeLightLuminanceG(double g){
    light->setG(g);
    updateLightLuminance();
}
void GeometryRender::changeLightLuminanceB(double b){
    light->setB(b);
    updateLightLuminance();
}

// Change the color of the ambient light
void GeometryRender::changeAmbientLightR(double r){
    ambientLight->setR(r);
    updateAmbientLightSourceColor();
}
void GeometryRender::changeAmbientLightG(double g){
    ambientLight->setG(g);
    updateAmbientLightSourceColor();
}
void GeometryRender::changeAmbientLightB(double b){
    ambientLight->setB(b);
    updateAmbientLightSourceColor();
}

// Change the ambient material properties
void GeometryRender::changeK_A_R(double r){
    obj->setK_A_R(r);
    updateMaterialAmbience();
}
void GeometryRender::changeK_A_G(double g){
    obj->setK_A_G(g);
    updateMaterialAmbience();
}
void GeometryRender::changeK_A_B(double b){
    obj->setK_A_B(b);
    updateMaterialAmbience();
}

void GeometryRender::changeK_D_R(double r){
    obj->setK_D_R(r);
    updateMaterialDiffusivity();
}
void GeometryRender::changeK_D_G(double g){
    obj->setK_D_G(g);
    updateMaterialDiffusivity();
}
void GeometryRender::changeK_D_B(double b){
    obj->setK_D_B(b);
    updateMaterialDiffusivity();
}

void GeometryRender::changeK_S_R(double r){
    obj->setK_S_R(r);
    updateMaterialSpecularity();
}
void GeometryRender::changeK_S_G(double g){
    obj->setK_S_G(g);
    updateMaterialSpecularity();
}
void GeometryRender::changeK_S_B(double b){
    obj->setK_S_B(b);
    updateMaterialSpecularity();
}


/*
 *
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









