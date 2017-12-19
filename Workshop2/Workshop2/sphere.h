/*
 *  Approximate a sphere using subdivision of a tetrahedron.
 *  Computer Graphics course
 *  Dept Computing Science, Umea University
 *  Stefan Johansson, stefanj@cs.umu.se
 *
 *  Code inspired by Example 1, Ch 5, Interactive Computer Graphics
 *  by E. Angel and D. Shreiner, 2012.
 */
#pragma once

#include "3dstudio.h"

class Sphere
{
public:
    Sphere();
    void make_sphere(const int);

    inline const QVector3D *verticesData() const
        {return vsphere.data(); }
    inline const QVector3D *normalsData() const
        {return nsphere.data(); }
    inline const unsigned int *indicesData() const
        {return isphere.data(); }
    inline size_t sizeVertices() const
        {return vsphere.size()*sizeof(QVector3D);}
    inline size_t sizeNormals() const
        {return nsphere.size()*sizeof(QVector3D);}
    inline size_t sizeIndices() const
        {return isphere.size()*sizeof(unsigned int);}
    inline int faces() const
        { return vsphere.size(); }

private:
    // Four equally spaced points on the unit circle
    // Last value holds the index of the vertex
    std::vector<QVector4D> v = {
        {0.0f, 0.0f, 1.0f, 0},
        {0.0f, 0.942809f, -0.333333f, 1},
        {-0.816497f, -0.471405f, -0.333333f, 2},
        {0.816497f, -0.471405f, -0.333333f, 3}};
    int lastindex = 3; // Current vertex index

    std::vector<QVector3D> vsphere;
    std::vector<unsigned int> isphere;
    std::vector<QVector3D> nsphere;

    QVector4D unit(const QVector4D);
    void triangle(QVector4D, QVector4D, QVector4D);
    void divide_triangle(QVector4D,QVector4D,QVector4D,int);
};

