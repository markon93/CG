#include "object3d.h"
#include <vector>
#include<QVector2D>
#include <QtMath>
#include "objfilereader.h"
#include <string>
using namespace std;

Object3D::Object3D(){
    midpoint = {0.0,0.0,0.0};
    k_ambient = {0.2, 0.2, 0.2, 1.0};
    k_diffuse = {1.0, 0.8, 0.0, 1.0};
    k_specular = {1.0, 1.0, 1.0, 1.0};
    alpha = 100;
}

/* Set the vertices of the object */
void Object3D::setVertices(vector<vector<float>> vertices){
    this->vertices = vertices;
}

/* Set the indices of the object's vertices */
void Object3D::setVertexIndices(vector<unsigned int> vertexIndices){
    this->vertexIndices = vertexIndices;
}

/* Set the texture data of the object */
void Object3D::setTextures(vector<vector<float>> textures){
    this->textures = textures;
}

/* Set the normal data of the object */
void Object3D::setNormals(vector<vector<float>> normals){
    this->normals = normals;
}

/* Set the vertex triangulation of the object */
void Object3D::setTriangulation(vector<vector<float>> triangulation){
    this->triangulation = triangulation;
}

/* Returns: the vertices of the object */
vector<vector<float>> Object3D::getVertices(){
    return vertices;
}

/* Returns: The indices of the object's vertices */
vector<unsigned int> Object3D::getVertexIndices(){
    return vertexIndices;
}

/* Returns: the vertices of the object */
vector<vector<float>> Object3D::getTriangulation(){
    return triangulation;
}

/* Reset all transformations; set the model matrix to the identity matrix */
void Object3D::reset(){
    matModel.setToIdentity();
}

//    std::vector<std::vector<float>> getTextures();
vector<vector<float>> Object3D::getNormals(){
    return normals;
}

void Object3D::rotateX(float alpha){
    //matModel.translate(-midpoint[0],-midpoint[1],-midpoint[2]);
    matModel.rotate(alpha, 1.0, 0.0, 0.0);
    //matModel.translate(midpoint[0],midpoint[1],midpoint[2]);
}

void Object3D::rotateY(float alpha){
    //matModel.translate(-midpoint[0],-midpoint[1],-midpoint[2]);
    matModel.rotate(alpha, 0.0, -1.0, 0.0);
    //matModel.translate(midpoint[0],midpoint[1],midpoint[2]);
}

void Object3D::rotateZ(float alpha){
    //matModel.translate(-midpoint[0],-midpoint[1],-midpoint[2]);
    matModel.rotate(alpha, 0.0, 0.0, 1.0);
    //matModel.translate(midpoint[0],midpoint[1],midpoint[2]);
}

void Object3D::translate(float dx, float dy, float dz){
    matModel.translate(dx, dy, dz);
    updateVertices(dx,dy,dz);
    updateMidpoint();
}

void Object3D::scale(float sx, float sy, float sz){
    matModel.scale(sx,sy,sz);
}

// Update the vertex list
void Object3D::updateVertices(float dx, float dy, float dz){
    for(int i = 0; i < (int) vertices.size(); i++){
        vertices[i][0] -= dx;
        vertices[i][1] -= dy;
        vertices[i][2] -= dz;
    }
}

// Calculate the midpoint of the object
void Object3D::updateMidpoint(){
    float sumX = 0.0, sumY = 0.0, sumZ = 0.0;
    for(int i = 0; i < (int) vertices.size(); i++){
        vector<float> row = vertices[i];
        sumX += row[0];
        sumY += row[1];
        sumZ += row[2];
    }
    float aveX = sumX/vertices.size();
    float aveY = sumY/vertices.size();
    float aveZ = sumZ/vertices.size();

    midpoint = {aveX, aveY, aveZ};
}

///////////////////////////
vector<QVector2D> Object3D::generateTextureCoords(){
    vector<QVector2D> interSectionPoints;
    for(int i = 0; i < (int)vertices.size(); i++){
        double a = 0, b = 0, c = 0;
        for(int j = 0; j < 3; j++){
            a += normals[i][j]*normals[i][j];
            b += 2*(vertices[i][j]*normals[i][j]);
            c += vertices[i][j]*vertices[i][j] - 1;
        }
        double delta = b*b - 4*a*c;
        double q = -0.5*(b + sgn(b)*sqrt(delta));
        double d1 = q/a;
        double d2 = c/q;

        double d = max(d1, d2);

        vector<float> P;
        for(int k = 0; k < 3; k++){
            P.push_back(vertices[i][k] + d*normals[i][k]);
        }

        // Normalize P
        double length = 0;
        for(int l = 0; l < 3; l++){
            length += P[l]*P[l];
        }
        length = sqrt(length);

        for(int l = 0; l < 3; l++){
            P[l] /= length;
        }

        float s  = qAcos(P[0])/M_PI;
        float t = qAtan2(P[2],P[1])/(2*M_PI) + 0.5;

        QVector2D row = QVector2D(s,t);
        interSectionPoints.push_back(row);
    }
    return interSectionPoints;
}

// Sign function
int Object3D::sgn(float x){
    if (x > 0) return 1;
    if (x < 0) return -1;
    return 0;
}
////////////////////////////


// Set the ambient coefficient of the material
void Object3D::setK_A_R(double k_a_r){
    this->k_ambient[0] = k_a_r;
}

// Set the ambient coefficient of the material
void Object3D::setK_A_G(double k_a_g){
    this->k_ambient[1] = k_a_g;
}

// Set the ambient coefficient of the material
void Object3D::setK_A_B(double k_a_b){
    this->k_ambient[2] = k_a_b;
}

// Set the ambient coefficient of the material
void Object3D::setK_D_R(double k_d_r){
    this->k_diffuse[0] = k_d_r;
}

// Set the ambient coefficient of the material
void Object3D::setK_D_G(double k_d_g){
    this->k_diffuse[1] = k_d_g;
}

// Set the ambient coefficient of the material
void Object3D::setK_D_B(double k_d_b){
    this->k_diffuse[2] = k_d_b;
}

// Set the ambient coefficient of the material
void Object3D::setK_S_R(double k_s_r){
    this->k_specular[0] = k_s_r;
}

// Set the ambient coefficient of the material
void Object3D::setK_S_G(double k_s_g){
    this->k_specular[1] = k_s_g;
}

// Set the ambient coefficient of the material
void Object3D::setK_S_B(double k_s_b){
    this->k_specular[2] = k_s_b;
}

// Set the ambient coefficient of the material
QVector4D Object3D::getK_A(){
    return this->k_ambient;
}

// Set the ambient coefficient of the material
QVector4D Object3D::getK_D(){
    return this->k_diffuse;
}

// Set the ambient coefficient of the material
QVector4D Object3D::getK_S(){
    return this->k_specular;
}

void Object3D::setAlpha(int alpha){
    this->alpha = alpha;
}

int Object3D::getAlpha(){
    return this->alpha;
}


















