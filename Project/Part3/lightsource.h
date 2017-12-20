#ifndef LIGHTSOURCE_H
#define LIGHTSOURCE_H
#include "3dstudio.h"

class LightSource : public QObject
{
    Q_OBJECT
public:
    LightSource(QVector4D pos, float r, float g, float b);
    void setR(float r);
    void setG(float g);
    void setB(float b);

    void setPosition(float x, float y, float z, float w);

    void move(float dx, float dy, float dz);

    QVector3D getRGB();
    QVector4D getPosition();

private:
    float R, G, B;
    QVector4D position;
};

#endif // LIGHTSOURCE_H
