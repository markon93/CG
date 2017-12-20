#include <QApplication>
#include <QSurfaceFormat>
#include <QObject>
#include "ass3widget.h"
#include "geometryrender.h"

int main(int argc, char **argv){
    QApplication app(argc, argv);

    // Create the OpenGL window
    QSurfaceFormat format;
    format.setSamples(16);
    format.setVersion(3,3);
    format.setProfile(QSurfaceFormat::CoreProfile);

    GeometryRender window;
    window.setFormat(format);
    window.resize(1024, 768);
    window.setTitle("CG Project");
    window.show();
    window.initialize();

    Ass3Widget widgets;
    widgets.show();

    QObject::connect(&widgets, SIGNAL(changeFile(std::string)),
                     &window, SLOT(getNewObject(std::string)));

    QObject::connect(&widgets, SIGNAL(changeFOV(int)),
                     &window, SLOT(changeFOV(int)));

    QObject::connect(&widgets, SIGNAL(changePFar(int)),
                     &window, SLOT(changePFar(int)));

    QObject::connect(&widgets, SIGNAL(changeToPerspective()),
                     &window, SLOT(changeToPerspective()));

    QObject::connect(&widgets, SIGNAL(changeToParallel()),
                     &window, SLOT(changeToParallel()));

    QObject::connect(&widgets, SIGNAL(changeOblScale(double)),
                     &window, SLOT(changeOblScale(double)));

    QObject::connect(&widgets, SIGNAL(changeOblAngle(double)),
                     &window, SLOT(changeOblAngle(double)));

    QObject::connect(&widgets, SIGNAL(changePlTop(double)),
                     &window, SLOT(changePlTop(double)));

    QObject::connect(&widgets, SIGNAL(changePlFar(int)),
                     &window, SLOT(changePlFar(int)));

    QObject::connect(&widgets, SIGNAL(changeLightX(float)),
                     &window, SLOT(changeLightX(float)));

    QObject::connect(&widgets, SIGNAL(changeLightY(float)),
                     &window, SLOT(changeLightY(float)));

    QObject::connect(&widgets, SIGNAL(changeLightZ(float)),
                     &window, SLOT(changeLightZ(float)));

    QObject::connect(&widgets, SIGNAL(changeLightR(double)),
                     &window, SLOT(changeLightR(double)));

    QObject::connect(&widgets, SIGNAL(changeLightG(double)),
                     &window, SLOT(changeLightG(double)));

    QObject::connect(&widgets, SIGNAL(changeLightB(double)),
                     &window, SLOT(changeLightB(double)));
    return app.exec();
}



