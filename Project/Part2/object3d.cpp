#include "object3d.h"
#include <vector>
#include "objfilereader.h"
#include <string>
using namespace std;

Object3D::Object3D(){
    midpoint = {0.0,0.0,0.0};
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
//    std::vector<std::vector<float>> getNormals();


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

