/*
 *  Workshop 2
 *  Computer Graphics course
 *  Dept Computing Science, Umea University
 *  Stefan Johansson, stefanj@cs.umu.se
 */
#include "geometryrender.h"

GeometryRender::GeometryRender()
    : vao(0)
    , vBuffer(QOpenGLBuffer::VertexBuffer)
    , iBuffer(QOpenGLBuffer::IndexBuffer)
{
}

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

    // Create index buffer in the shared display list space and
    // bind it as IndexBuffer (GL_ELEMENT_ARRAY_BUFFER)
    iBuffer.create();
    iBuffer.setUsagePattern(QOpenGLBuffer::StaticDraw);
    iBuffer.bind();

    // Get locations of the attributes in the shader
    // Corresponds to the GL calls glGetAttribLocation() and
    // glGetUniformLocation()
    locVertices = program->attributeLocation("vPosition");
    locNormals = program->attributeLocation("vNormal");
    locProj = program->uniformLocation("P");
    locView = program->uniformLocation("V");
    locTransform = program->uniformLocation("M");

    vao.release();
    program->release();

    loadGeometry();
    loadProjectionMatrix();
    loadViewMatrix();
    loadTransformation();
}

void GeometryRender::loadGeometry(void)
{
    sphere.make_sphere(4);

    program->bind();
    vao.bind();

    // Load data to the array buffer
    // Corresponds to the GL call glBufferSubData() or glBufferData()
    size_t vSize = sphere.sizeVertices();
    size_t nSize = sphere.sizeNormals();
    vBuffer.allocate(vSize+nSize);
    vBuffer.write(0, sphere.verticesData(), vSize);
    vBuffer.write(vSize, color.normalsData(), nSize);

    // Load indices to index array
    iBuffer.allocate(sphere.sizeIndices());
    iBuffer.write(0, sphere.indicesData(), sphere.sizeIndices());

    // Set the pointers of locVertices to the right places
    // Can also call program->setAttributeBuffer() but then the values are normalized
    glVertexAttribPointer(locVertices, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
    glEnableVertexAttribArray(locVertices);
    glVertexAttribPointer(locNormals, 3, GL_FLOAT, GL_FALSE, 0,
    BUFFER_OFFSET(vSize));
    glEnableVertexAttribArray(locNormals);
    vao.release();
    program->release();
}

void GeometryRender::loadProjectionMatrix(void) const
{
    program->bind();
    // Load projection matrix to GPU
    // Correspons to the GL call glUniformMatrix4fv()
    program->setUniformValue(locProj, matProj);
    program->release();
}

void GeometryRender::loadViewMatrix(void) const
{
    program->bind();
    // Load view matrix to GPU
    // Correspons to the GL call glUniformMatrix4fv()
    program->setUniformValue(locView, matView);
    program->release();
}

void GeometryRender::loadTransformation(void) const
{
    program->bind();
    // Load transformation (model) matrix to GPU
    // Correspons to the GL call glUniformMatrix4fv()
    program->setUniformValue(locTransform, matTransformation);
    program->release();
}

void GeometryRender::rotateTX(float angle)
{
    matTransformation.rotate(angle,1.0f,0.0f);
}

// The window event handler
bool GeometryRender::event(QEvent *event)
{
    QKeyEvent *ke;

    switch (event->type()) {
    case QEvent::KeyPress:
        ke = static_cast<QKeyEvent *>(event);
        if (ke->key() == Qt::Key_Space) {
            // By pressing space the object is rotated
            rotateTX(5.0f);
            loadTransformation();
            displayNow();
            return true;
        }
        return OpenGLWindow::event(event);
    default:
        return OpenGLWindow::event(event);
    }

}


// Render object
void GeometryRender::display()
{

    program->bind();
    vao.bind();

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glDrawElements(GL_TRIANGLES, sphere.faces()*3, GL_UNSIGNED_INT, BUFFER_OFFSET(0));

    vao.release();
    program->release();

}
