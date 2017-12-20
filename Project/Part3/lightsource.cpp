#include "lightsource.h"

LightSource::LightSource(QVector4D pos, float r, float g, float b){
    this->position = pos;
    this->R = r;
    this->G = g;
    this->B = b;
}

void LightSource::setR(float r){
    this->R = r;
}

void LightSource::setG(float g){
    this->G = g;
}

void LightSource::setB(float b){
    this->B = b;
}

void LightSource::setPosition(float x, float y, float z, float w){
    this->position = QVector4D(x,y,z,w);
}

QVector3D LightSource::getRGB(){
    return QVector3D(this->R,this->G,this->B);
}

QVector4D LightSource::getPosition(){
    return this->position;
}

void LightSource::move(float dx, float dy, float dz){
    this->position += QVector4D(dx, dy, dz, 0.0);
}
