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
    std::vector<std::vector<float>> getNormals();
    std::vector<unsigned int> getVertexIndices();
    std::vector<std::vector<float>> getTriangulation();

    std::vector<QVector2D> generateTextureCoords();

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

    void setK_A_R(double k_a_r);
    void setK_A_G(double k_a_g);
    void setK_A_B(double k_a_b);

    void setK_D_R(double k_d_r);
    void setK_D_G(double k_d_g);
    void setK_D_B(double k_d_b);

    void setK_S_R(double k_s_r);
    void setK_S_G(double k_s_g);
    void setK_S_B(double k_s_b);

    QVector4D getK_A();
    QVector4D getK_D();
    QVector4D getK_S();

    int getAlpha();
    void setAlpha(int alpha);

    QMatrix4x4 matModel;

    void reset();
private:
    QVector4D k_ambient, k_diffuse, k_specular;

    void initialize();
    std::vector<std::vector<float>> vertices, textures, normals, triangulation;
    std::vector<unsigned int> vertexIndices;
    std::vector<float> midpoint;
    void updateVertices(float dx, float dy, float dz);
    void updateMidpoint();

    int alpha;

    int sgn(float x);
};

#endif // OBJECT3D_H
