/*
 *  Approximate a sphere using subdivision of a tetrahedron.
 *  Computer Graphics course
 *  Dept Computing Science, Umea University
 *  Stefan Johansson, stefanj@cs.umu.se
 *
 *  Code inspired by Example 1, Ch 5, Interactive Computer Graphics
 *  by E. Angel and D. Shreiner.
 */
#include "sphere.h"

Sphere::Sphere()
{
    // Reserve memory for n=4
    vsphere.reserve(1024);
    isphere.reserve(3100);
}

QVector4D Sphere::unit(const QVector4D v)
{
    QVector4D vnew;
    float d = v.toVector3D().length();

    if(d > 0.0f) {
        vnew = QVector4D(v.x()/d,v.y()/d,v.z()/d, ++lastindex);
    } else {
        vnew = QVector4D(0.0f,0.0f,0.0f, ++lastindex);
    }

    vsphere.push_back(vnew.toVector3D());

    // Since the sphere is centered around origio the normals
    // are pointing in the direction of the vertex
    nsphere.push_back(vnew.toVector3D().normalized());

    return vnew;
}

void Sphere::triangle(QVector4D  a, QVector4D b, QVector4D c)
{
    isphere.push_back(a.w());
    isphere.push_back(b.w());
    isphere.push_back(c.w());
}


void Sphere::divide_triangle(QVector4D a, QVector4D b, QVector4D c, int n)
{
    QVector4D v1, v2, v3;

    if(n>0) {
        v1 = unit(a + b);
        v2 = unit(a + c);
        v3 = unit(b + c);
        divide_triangle(a ,v2, v1, n-1);
        divide_triangle(c ,v3, v2, n-1);
        divide_triangle(b ,v1, v3, n-1);
        divide_triangle(v1 ,v2, v3, n-1);
    } else {
        triangle(a, b, c);
    }
}

/*
 * Create a sphere by subdividing the faces of a tetrahedron n times.
 */
void Sphere::make_sphere(const int n)
{
    vsphere.push_back(v[0].toVector3D());
    vsphere.push_back(v[1].toVector3D());
    vsphere.push_back(v[2].toVector3D());
    vsphere.push_back(v[3].toVector3D());
    nsphere.push_back(v[0].toVector3D().normalized());
    nsphere.push_back(v[1].toVector3D().normalized());
    nsphere.push_back(v[2].toVector3D().normalized());
    nsphere.push_back(v[3].toVector3D().normalized());

    divide_triangle(v[0], v[1], v[2], n);
    divide_triangle(v[3], v[2], v[1], n);
    divide_triangle(v[0], v[3], v[1], n);
    divide_triangle(v[0], v[3], v[2], n);
}

