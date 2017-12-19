#include "camera.h"
#include <vector>
#include <math.h>
#include <QtMath>
#include <iostream>
using namespace std;
Camera::Camera(float aspect){
    this->aspect = aspect;

    fov = qDegreesToRadians(60.0);
    far = 500;
    near = 0.005;

    projectionMode = "Perspective";

    // Initial position
    p0 = {0.0, 0.0, 2.0, 1.0};
    p0_cam = {0,0,0,1.0};

    // Initial global reference point
    pRef = {0.0, 0.0, 0.0, 1.0};

    // "Up" direction
    vUp = {0.0, 1.0, 0.0, 0.0};

    // Distance to look-at point
    d = sqrt((p0[0] - pRef[0])*(p0[0] - pRef[0])
            + (p0[1] - pRef[1])*(p0[1] - pRef[1])
            + (p0[2] - pRef[2])*(p0[2] - pRef[2]));

    // Initial camera look-at point
    pRef_cam = {0.0,0.0,-d,1.0};

    // Calculate T matrix
    updateT();

    // Calcualte the initial view matrix
    calculateV();
    updateP();
}

// Calculate the view matrix
void Camera::calculateV(){

    // Normalized z-axis of the camera in world coordinates
    n = QVector3D(p0) - QVector3D(pRef);
    n.normalize();

    // Vector perpendicular to p0 - pRef and vUp
    u = QVector3D::crossProduct(QVector3D(vUp), n);
    u.normalize();

    // Vector perpendicular to v and n
    v = QVector3D::crossProduct(n,u);
    v.normalize();

    // Rotation matrix
    M_WC.setColumn(0, QVector4D(u));
    M_WC.setColumn(1, QVector4D(v));
    M_WC.setColumn(2, QVector4D(n));
    M_WC.setColumn(3, QVector4D(0,0,0,1));

    // View matrix
    V = M_WC.transposed()*T;

}

// Update the translation matrix
void Camera::updateT(){
    T = {1, 0, 0, -p0[0],
         0, 1, 0, -p0[1],
         0, 0, 1, -p0[2],
         0, 0, 0, 1};
}

// Update the perpective matrix
void Camera::updateP(){

    if(projectionMode == "Perspective"){
        top = near*qTan(fov);
        right = top*aspect;

        P = {near/right, 0, 0, 0,
            0, near/top, 0, 0,
            0, 0, -(far+near)/(far-near), -2*far*near/(far-near),
            0, 0, -1, 0};
    }

    else if(projectionMode == "Parallel"){
        right = top*aspect;
        QMatrix4x4 H_phi;
        H_phi(0, 2) = a*cos(phi);
        H_phi(1, 2) = a*sin(phi);

        float bottom = -top;
        float left = -right;

        QMatrix4x4 ST;
        ST(0,0) = 2/(right - left);
        ST(1,1) = 2/(top - bottom);
        ST(2,2) = -2/(far - near);
        ST(0,3) = -(left + right)/(right - left);
        ST(1,3) = -(top + bottom)/(top - bottom);
        ST(2,3) = -(far + near)/(far - near);

        P = ST*H_phi;
    }
}

// Update the position of the camera and the view matrix
void Camera::updatePos(float dx, float dy, float dz){

    QVector4D p0_new = {dx, dy, dz, 1.0};
    p0 = V.inverted()*p0_new;

    QVector4D pRef_new = {dx,dy,dz - d,1};
    pRef = V.inverted()*pRef_new;


//    cout << p0[0] << " " << p0[1] << " " <<p0[2] << endl;
//    cout << pRef[0] << " " << pRef[1] << " " <<pRef[2] << endl << endl;

    updateT();
    calculateV();
}

// Rotate the camera about the y-axis
void Camera::yaw(float yaw){

    QVector4D pRef_new = pRef_cam;
    QMatrix4x4 rot;

    rot.rotate(yaw, 0.0, 1.0, 0.0);
    pRef_new = rot*pRef_new;
    pRef = V.inverted()*pRef_new;

    calculateV();
}

// Rotate the camera about the x-axis
void Camera::pitch(float pitch){

    QMatrix4x4 rot;
    rot.rotate(pitch, 1.0, 0.0, 0.0);
    QVector4D pRef_new = rot*pRef_cam;

    QMatrix4x4 Vinv = V.inverted();
    pRef = Vinv*pRef_new;
    calculateV();
}

/* The below functions are called when the user changes values in the gui */

// Change the field of view
void Camera::setFOV(int fov){
    this->fov = qDegreesToRadians((float)fov);
    updateP();
}

// Change back plane of the frustum
void Camera::setPFar(int d){
    this->far = d;
    updateP();
}

// Switch between projection modes
void Camera::setMode(string mode){
    this->projectionMode = mode;
    updateP();
}

// Change the oblique scale
void Camera::setOblScale(double scale){
    this->a = scale;
    updateP();
}

// Change the oblique angle
void Camera::setOblAngle(double angle){
    this->phi = qDegreesToRadians(angle);
    updateP();
}

// Change the oblique angle
void Camera::setPlTop(double top){
    this->top = top;
    updateP();
}

