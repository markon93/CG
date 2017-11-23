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
    , vBuffer(QOpenGLBuffer::VertexBuffer)
    , iBuffer(QOpenGLBuffer::IndexBuffer){
}

/* Get user input.
    - prompt: Message to the user with what to enter.
    - returns: The string that the user entered.
*/
string GeometryRender::getUserInput(string prompt){
    cout << prompt;
    string input;
    cin >> input;
    return input;
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

    vao.release();
    program->release();

    // Standard object is a pyramid
    obj = new Object3D();

    loadGeometry();
}

// Update the model matrix
void GeometryRender::update(){
    program->bind();
    vao.bind();

    program->setUniformValue(locModel, obj->matModel);
    OpenGLWindow::displayNow();

    vao.release();
    program->release();
}

// Handle keyboard events
void GeometryRender::keyPressEvent(QKeyEvent *keyEvent){
    float alpha = 10;
    float t = 0.1;
    float scaleUp = 1.1;
    float scaleDown = 0.9;
    switch (keyEvent->key()){
    case Qt::Key_Left:
        obj->rotateX(-alpha);
        break;
    case Qt::Key_Right:
        obj->rotateX(alpha);
        break;
    case Qt::Key_Up:
        obj->rotateY(10);
        break;
    case Qt::Key_Down:
        obj->rotateY(-alpha);
        break;
    case Qt::Key_I:
        obj->translate(0.0,t,0.0);
        break;
    case Qt::Key_K:
        obj->translate(0.0,-t,0.0);
        break;
    case Qt::Key_L:
        obj->translate(t,0.0,0.0);
        break;
    case Qt::Key_J:
        obj->translate(-t,0.0,0.0);
        break;
    case Qt::Key_W:
        obj->scale(scaleUp, scaleUp, scaleUp);
        break;
    case Qt::Key_S:
        obj->scale(scaleDown, scaleDown, scaleDown);
        break;
    case Qt::Key_O:
        filename = getUserInput("Enter filename: ");
        //Load a new object
        obj->matModel.setToIdentity();
        obj = new Object3D(filename);
        loadGeometry();
        break;
    default:
        keyEvent -> ignore();
        break;
    }
    update();
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

    iBuffer.allocate(iSize);
    iBuffer.write(0, vertexIndices.data(), iSize);

    vao.release();
    program->release();
}

/* Transform a vector of vectors to a vector with VertVecs */
vector<VertVec> GeometryRender::castVecVec2VertVec(vector<vector<float>> vertices){
    vector<VertVec> newVec;
    vector<vector<float>>::iterator it;
    for (it = vertices.begin(); it != vertices.end(); it++){
        vector<float> row = *it;
        newVec.push_back(VertVec(row[0],row[1],row[2]));
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









