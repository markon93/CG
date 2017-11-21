#include "object3d.h"
#include <vector>
#include "objfilereader.h"
#include <string>
using namespace std;

Object3D::Object3D(){
    filename = "cube.obj";
    this->initialize();
}

Object3D::Object3D(string filename){
    this->filename = filename;
    this->initialize();
}

/* Create object data according to the data in the user supplied file */
void Object3D::initialize(){
    reader = new OBJFileReader(filename);
    vertices = reader->getVertices();
}

/* Returns: the vertices of the object */
vector<vector<float>> Object3D::getVertices(){
    return vertices;
}


//    std::vector<std::vector<float>> getTextures();
//    std::vector<std::vector<float>> getNormals();


//    void rotateX(float alpha);
//    void rotateY(float alpha);
//    void rotateZ(float alpha);

//    void translate(float dx, float dy, float dz);

//    void scale(float sx, float sy, float sz);

