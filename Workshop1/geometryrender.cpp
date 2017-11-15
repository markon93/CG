/*
 *  Workshop 1
 *  Computer Graphics course
 *  Dept Computing Science, Umea University
 *  Stefan Johansson, stefanj@cs.umu.se
 */
#include <QKeyEvent>
#include "geometryrender.h"
GeometryRender::GeometryRender()
    : vao(0)
    , vBuffer(QOpenGLBuffer::VertexBuffer)
{
}

QMatrix4x4 matModel;
GLuint locModel;

// Initialize OpenGL
void GeometryRender::initialize()
{
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
    program->setUniformValue(locModel, matModel);

    vao.release();
    program->release();
    loadGeometry();
}

//void GeometryRender::translate(int xt, int yt, int zt){
//   QMatrix4x4 T = QMatrix4x4(1, 0, 0, xt, 0, 1, 0, yt, 0, 0, 0, zt, 0, 0, 0, 1.0);
//    matModel = matModel * T;
//}

// Handle keyboard events
void GeometryRender::keyPressEvent(QKeyEvent *keyEvent)
{
    switch (keyEvent->key())
    {
    case Qt::Key_Left:
        matModel.translate(-0.1,0.0);
    default:
        keyEvent -> ignore();
    }
}

void GeometryRender::loadGeometry(void)
{
    // Define vertices in array
    vertices.push_back(VertVec(-0.5f, -0.75f));
    vertices.push_back(VertVec( 0.0f,  0.75f));
    vertices.push_back(VertVec( 0.5f, -0.75f));


    program->setUniformValue(locModel, matModel);

    program->bind();
    vao.bind();

    // Set the pointers of locVertices_ to the right places
    // Can also call program_->setAttributeBuffer() but then the values are normalized
    glVertexAttribPointer(locVertices, 2, GL_FLOAT, GL_TRUE, 0, BUFFER_OFFSET(0));
    glEnableVertexAttribArray(locVertices);

    // Load data to the array buffer
    // Corresponds to the GL call glBufferData()
    size_t vSize = vertices.size()*sizeof(VertVec);
    vBuffer.allocate(vSize);
    vBuffer.write(0, vertices.data(), vSize);

    vao.release();
    program->release();
}

// Render object
void GeometryRender::display()
{
    program->bind();
    vao.bind();

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glDrawArrays(GL_LINE_LOOP, 0, vertices.size());
    glFlush();

    vao.release();
    program->release();

}
