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
//    std::vector<std::vector<float>> getTextures();
    std::vector<std::vector<float>> getNormals();
    std::vector<unsigned int> getVertexIndices();
    std::vector<std::vector<float>> getTriangulation();

    void setVertices(std::vector<std::vector<float>>);
    void setVertexIndices(std::vector<unsigned int>);
    void setTriangulation(std::vector<std::vector<float>>);
    void setTextures(std::vector<std::vector<float>>);
    void setNormals(std::vector<std::vector<float>>);

    void rotateX(float alpha);
    void rotateY(float alpha);
    void rotateZ(float alpha);

    void translate(float dx, float dy, float dz);

    void scale(float sx, float sy, float sz);

    QMatrix4x4 matModel;

    void reset();
private:
    void initialize();
    std::vector<std::vector<float>> vertices, textures, normals, triangulation;
    std::vector<unsigned int> vertexIndices;

    std::vector<float> midpoint;
    void updateVertices(float dx, float dy, float dz);
    void updateMidpoint();
};

#endif // OBJECT3D_H
