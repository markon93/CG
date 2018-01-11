#ifndef CAMERA_H
#define CAMERA_H

#include <QObject>
#include <QMatrix4x4>
#include <QVector3D>
class Camera {

public:
    Camera(float aspectRatio);
    QMatrix4x4 V, P;

    /////////////////
    void updatePos(float dx, float dy, float dz);
    void yaw(float yaw);
    void pitch(float pitch);
    void setAspectRatio(float ratio);
    void setFOV(int fov);
    void setPFar(int d);
    void setMode(std::string mode);
    void setOblScale(double scale);
    void setOblAngle(double angle);
    void setPlTop(double top);
    // void updateVMatrix(float x, float y, float z);
    ///////////////////

private:
    QVector4D p0, p0_cam;
    QVector4D pRef, pRef_cam;
    QVector4D vUp;

    float d;

    QMatrix4x4 M_WC;
    QMatrix4x4 T;

    QVector3D n;
    QVector3D u;
    QVector3D v;

    void calculateV();
    void updateT();
    void updateP();

    float top, near, far, right, fov, aspect;
    double a, phi;
    std::string projectionMode;
};



#endif // CAMERA_H
