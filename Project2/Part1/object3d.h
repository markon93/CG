#ifndef OBJECT3D_H
#define OBJECT3D_H

#include <QObject>
#include <objfilereader.h>
#include "3dstudio.h"

class Object3D{
public:
    Object3D();
    Object3D(std::string fname);

    std::vector<std::vector<float>> getVertices();
    std::vector<std::vector<float>> getTextures();
    std::vector<std::vector<float>> getNormals();

    void rotateX(float alpha);
    void rotateY(float alpha);
    void rotateZ(float alpha);

    void translate(float dx, float dy, float dz);

    void scale(float sx, float sy, float sz);

    QMatrix4x4 matModel;

private:
    void initialize();
    OBJFileReader* reader;
    std::string filename;
    std::vector<std::vector<float>> vertices, textures, normals;
};

#endif // OBJECT3D_H
