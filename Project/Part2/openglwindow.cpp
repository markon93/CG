/*
 *  Workshop 1
 *  Computer Graphics course
 *  Dept Computing Science, Umea University
 *  Stefan Johansson, stefanj@cs.umu.se
 */
#include "openglwindow.h"

#include <QtCore/QCoreApplication>
#include <QtGui/QOpenGLContext>
#include <QtGui/QOpenGLPaintDevice>
#include <QtGui/QPainter>

using namespace std;

OpenGLWindow::OpenGLWindow(QWindow *parent)
    : QWindow(parent){
    setSurfaceType(QWindow::OpenGLSurface);
}

void OpenGLWindow::display(QPainter *painter){
    Q_UNUSED(painter);
}

// Initialize OpenGL context and viewport.
void OpenGLWindow::initialize(){
    context = unique_ptr<QOpenGLContext>{new QOpenGLContext(this)};

    context->setFormat(requestedFormat());
    if (!context->create()) {
        cerr << "Could not initialize OpenGL context." << endl;
        exit(EXIT_FAILURE);
    }

    context->makeCurrent(this);
    initializeOpenGLFunctions();

    /* Set graphics attributes */
    glPointSize(5.0); // Unsupported in Qt on MS Windows
    glLineWidth(1.0);
    glClearColor(0.0, 0.0, 0.0, 0.0);


    // To handle high DPI screens
    //const qreal retinaScale = devicePixelRatio();

///////////////////////////////
    glViewport(0, 0, width(), height());
///////////////////////////////
}

float OpenGLWindow::getAspectRatio(){
    return width()/height();
}

// Initialize OpenGL shader program
unique_ptr<QOpenGLShaderProgram> OpenGLWindow::initProgram(QObject *parent, const QString &vShaderFile, const QString &fShaderFile) const{
    // Create a shader program
    // Corresponds to the GL call glCreateProgram()
    unique_ptr<QOpenGLShaderProgram> program = unique_ptr<QOpenGLShaderProgram>{new QOpenGLShaderProgram(parent)};

    // Load vertex shader
    if (!program->addShaderFromSourceFile(QOpenGLShader::Vertex, vShaderFile)) {
        cerr << "Failed to compile " << vShaderFile.toStdString() << endl;
        cerr << program->log().toStdString() << endl;
        exit(EXIT_FAILURE);
    }

    // Load fragment shader
    if (!program->addShaderFromSourceFile(QOpenGLShader::Fragment, fShaderFile)) {
        cerr << "Failed to compile " << fShaderFile.toStdString() << endl;
        cerr << program->log().toStdString() << endl;
        exit(EXIT_FAILURE);
    }

    // Link and error check
    if (!program->link()) {
        cerr << "Shader program failed to link:" << endl;
        cerr << program->log().toStdString() << endl;
        exit(EXIT_FAILURE);
    }

    return program;
}


// Render the scene using QPainter.
// This should be overriden in a sub-class.
void OpenGLWindow::display(){
    if (!device)
        device = make_shared<QOpenGLPaintDevice>();

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    device->setSize(size());

    QPainter painter(device.get());
    display(&painter);
}

void reshape(void){
    GLint viewportParams[4];
    glGetIntegerv(GL_VIEWPORT, viewportParams);
    glViewport(0, 0, viewportParams[2], viewportParams[3]);
}

// The window event handler
bool OpenGLWindow::event(QEvent *event){
    switch (event->type()) {
    case QEvent::Close:
        // Terminate application if window is closed
        qApp->quit();
    case QEvent::Resize:
        reshape();
    default:
        return QWindow::event(event);
    }
}

// Called when the window is exposed
void OpenGLWindow::exposeEvent(QExposeEvent *event){
    Q_UNUSED(event);

    if (isExposed())
        displayNow();
}

// Render the scene if the window is exposed (shown)
void OpenGLWindow::displayNow(){
    if (!isExposed() || !context)
        return;

    context->makeCurrent(this);

    display();

    context->swapBuffers(this);

}

