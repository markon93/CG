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

    // Light source position
    QObject::connect(&widgets, SIGNAL(changeLightX(float)),
                     &window, SLOT(changeLightX(float)));

    QObject::connect(&widgets, SIGNAL(changeLightY(float)),
                     &window, SLOT(changeLightY(float)));

    QObject::connect(&widgets, SIGNAL(changeLightZ(float)),
                     &window, SLOT(changeLightZ(float)));

    // Light source intensity
    QObject::connect(&widgets, SIGNAL(changeLightLuminanceR(double)),
                     &window, SLOT(changeLightLuminanceR(double)));

    QObject::connect(&widgets, SIGNAL(changeLightLuminanceG(double)),
                     &window, SLOT(changeLightLuminanceG(double)));

    QObject::connect(&widgets, SIGNAL(changeLightLuminanceB(double)),
                     &window, SLOT(changeLightLuminanceB(double)));

    // Ambient light intensity
    QObject::connect(&widgets, SIGNAL(changeAmbientLightR(double)),
                     &window, SLOT(changeAmbientLightR(double)));

    QObject::connect(&widgets, SIGNAL(changeAmbientLightG(double)),
                     &window, SLOT(changeAmbientLightG(double)));

    QObject::connect(&widgets, SIGNAL(changeAmbientLightB(double)),
                     &window, SLOT(changeAmbientLightB(double)));

    // Material ambience
    QObject::connect(&widgets, SIGNAL(changeK_A_R(double)),
                     &window, SLOT(changeK_A_R(double)));

    QObject::connect(&widgets, SIGNAL(changeK_A_G(double)),
                     &window, SLOT(changeK_A_G(double)));

    QObject::connect(&widgets, SIGNAL(changeK_A_B(double)),
                     &window, SLOT(changeK_A_B(double)));

    // Material diffusivity
    QObject::connect(&widgets, SIGNAL(changeK_D_R(double)),
                     &window, SLOT(changeK_D_R(double)));

    QObject::connect(&widgets, SIGNAL(changeK_D_G(double)),
                     &window, SLOT(changeK_D_G(double)));

    QObject::connect(&widgets, SIGNAL(changeK_D_B(double)),
                     &window, SLOT(changeK_D_B(double)));

    // Material specularity
    QObject::connect(&widgets, SIGNAL(changeK_S_R(double)),
                     &window, SLOT(changeK_S_R(double)));

    QObject::connect(&widgets, SIGNAL(changeK_S_G(double)),
                     &window, SLOT(changeK_S_G(double)));

    QObject::connect(&widgets, SIGNAL(changeK_S_B(double)),
                     &window, SLOT(changeK_S_B(double)));

    QObject::connect(&widgets, SIGNAL(changeAlpha(int)),
                     &window, SLOT(changeAlpha(int)));

    QObject::connect(&widgets, SIGNAL(activateTexture(bool)),
                     &window, SLOT(activateTexture(bool)));


    QObject::connect(&widgets, SIGNAL(changeTexture(std::string)),
                     &window, SLOT(changeTexture(std::string)));

    return app.exec();
}



