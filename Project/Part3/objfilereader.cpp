#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;
#include "objfilereader.h"

OBJFileReader::OBJFileReader(){
    this->filename = "cube.obj";
    if(!this -> formatData()){
        exit(1);
    }
}

void OBJFileReader::updateData(string filename){
    this->filename = filename;
    clearData();
    if(!this -> formatData()){
        exit(1);
    }
}

/* Returns a vector with floats from a string where they are separated by spaces. */
vector<float> OBJFileReader::getFloats(string line){
    istringstream iss(line);
    vector<float> values;
    string token;
    while (iss >> token) {
        QString qtoken = QString::fromStdString(token);
        float val = qtoken.toFloat();
        values.push_back(val);
    }
    return values;
}

/* Takes a string on the form x/y/z (y and/or z not mandatory) and return a vector on the form [x, y, z]. */
vector<string> OBJFileReader::parseFaceString(string str){
    string vertexIndex = "", textureIndex = "", normalIndex = "";
    int nFields = 1;
    for(int i = 0; i < (int)str.length(); ++i){
        if(str[i] == '/'){
            nFields++;
            continue;
        }
        if(nFields == 1){
            vertexIndex += str[i];
        }
        else if(nFields == 2){
            textureIndex += str[i];
        }
        else{
            normalIndex += str[i];
        }
    }
    vector<string> output;
    output.push_back(vertexIndex);
    output.push_back(textureIndex);
    output.push_back(normalIndex);
    return output;
}

/* Splits a line consisting of strings into a vector */
vector<string> OBJFileReader::getStrings(string line){
    istringstream iss(line);
    vector<string> out;
    string token;
    int nTokens = 0;
    while (iss >> token) {
        out.push_back(token);
        nTokens++;
    }
    return out;
}

/* Normalize a 3d vector */
vector<float> OBJFileReader::normalizeVec(vector<float> vec){
    vector<float>::iterator it;
    float scale;
    for(it = vec.begin(); it != vec.end(); it++){
        scale += *it*(*it);
    }
    scale = sqrt(scale);

    for(it = vec.begin(); it != vec.end(); it++){
        if(scale > 0){
            *it = *it/scale;
        }
    }
    return vec;
}

/* Make a simple triangulation of vertex data */
vector<vector<float>> OBJFileReader::triangulate(vector<vector<float>> verticeData){
    vector<vector<float>> triangulation;
    vector<vector<float>>::iterator i;
    vector<vector<float>>::iterator j;
    vector<vector<float>>::iterator k;

    for(i = verticeData.begin(); i != verticeData.end() - 2; ++i){
        for(j = verticeData.begin() + 1; j != verticeData.end() - 1; ++j){
            for(k = verticeData.begin() + 2; k != verticeData.end(); ++k){
                triangulation.push_back(*i);
                triangulation.push_back(*j);
                triangulation.push_back(*k);
            }
        }
    }
    return triangulation;
}

/* Center the vertices at the origin */
void OBJFileReader::centerVertices(){
    double sumX = 0.0, sumY = 0.0, sumZ = 0.0;
    vector<vector<float>>::iterator it;
    for(it = vertices.begin(); it != vertices.end(); it++){
        vector<float> row = *it;
        sumX += row[0];
        sumY += row[1];
        sumZ += row[2];
    }

    double aveX = sumX/(vertices.size());
    double aveY = sumY/(vertices.size());
    double aveZ = sumZ/(vertices.size());

    for(int i = 0; i < (int) vertices.size(); i++){
        vertices[i][0] -= aveX;
        vertices[i][1] -= aveY;
        vertices[i][2] -= aveZ;
    }
}

/* Reset all vectors */
void OBJFileReader::clearData(){
    vertices.clear();
    faces.clear();
    vertexIndices.clear();
    textures.clear();
    triangulation.clear();
    faceNormals.clear();
    vertexNormals.clear();
    normalIndices.clear();
}

/* Puts the vertex-, face- and texture data from a file in vectors. */
bool OBJFileReader::formatData(){
    bool fGiven = false, vnGiven = false;
    ifstream data(filename);
    string line;
    if(data.is_open()){
        while(getline(data, line)){
            if (line.size() > 1){
                string tag = line.substr (0,2);
                string rest = line.substr(2,line.size());

                // Add vertices to a list (vector with float values)
                if(tag == "v "){
                    vertices.push_back(getFloats(rest));
                }

                // Add face data x/y/z to a list (vector with strings)
                else if(tag == "f "){
                    fGiven = true;
                    vector<string> coord = getStrings(rest);
                    if(coord.size() == 3){
                        faces.push_back(coord);
                    }
                    else{
                        vector<string> coord1 = {coord[0], coord[1], coord[2]};
                        vector<string> coord2 = {coord[0], coord[2], coord[3]};
                        faces.push_back(coord1);
                        faces.push_back(coord2);
                    }
                }

                // Add texture data to a list (vector with floats)
                else if(tag == "vt"){
                    textures.push_back(getFloats(rest));
                }

                // Add vertex normal data to a list (vector with floats)
                else if(tag == "vn"){
                    vnGiven = true;
                    faceNormals.push_back(getFloats(rest));
                }
            }
        }

        // Center the vertices at the origin
        centerVertices();

        // Find the normalization scale
        vertices = normalize(vertices);

        // Use face data to calculate triangulation if it is given, else make one manually
        vector<vector<string>>::iterator it;
        if(fGiven){
            for(it = faces.begin(); it != faces.end(); it++){
                vector<string>::iterator it2;
                vector<string> row = *it;
                vector<int> outRow;
                for(it2 = row.begin(); it2 != row.end(); ++it2){
                    vector<string> parsedFaceData = parseFaceString(*it2);

                    // Get vertex indices from file
                    int vIndex = stoi(parsedFaceData[0]) - 1;

                    triangulation.push_back(vertices[vIndex]);
                    unsigned int uiIndex = vIndex;
                    vertexIndices.push_back(uiIndex);

                    // Get vertex normal indices
                    if(vnGiven){
                        int fIndex = stoi(parsedFaceData[2]) - 1;
                        outRow.push_back(fIndex);
                    }
                }
                normalIndices.push_back(outRow);
            }
//////////
            // Calculate the vertex normals from given face normals
            if(vnGiven){

                // Initialize vertex normals to zero
                for(int i = 0; i < (int)vertices.size(); i++){
                    vertexNormals.push_back(vector<float>(3,0));
                }

                // Add face normals to vertex normals
                for(int i = 0; i < (int)vertexIndices.size(); i+=3){
                    vector<uint> currVN_indices = {vertexIndices[i],
                                                   vertexIndices[i + 1],
                                                   vertexIndices[i + 2]};

                    vector<int>currFaceNormals = normalIndices[i/3];

                    for(int j = 0; j < 3; j++){
                        for(int k = 0; k < 3; k++){
                            vertexNormals[currVN_indices[j]][k] += faceNormals[currFaceNormals[j]][k];
                        }
                    }
                }

                // Normalize the vertex normals
                for(int i = 0; i < (int)vertexNormals.size(); i++){
                    vector<float> row = vertexNormals[i];
                    float sum = 0;
                    for(int j = 0; j < (int)row.size();j++){
                        sum += row[j]*row[j];
                    }

                    for(int j = 0; j < (int)row.size(); j++){
                        vertexNormals[i][j] /= sqrt(sum);
                    }
                }
            }
        }
/////////////
        else{
            triangulation = triangulate(vertices);
        }
    }
    else{
        cout << "Unable to open file \"" << filename << "\"\n";
        return false;
    }

    data.close();
    return true;
}

/* Returns the vertices that are specified in the file */
vector<vector<float>> OBJFileReader::getVertices(){
    return vertices;
}

/* Returns the vertices that are specified in the file */
vector<vector<float>> OBJFileReader::getTriangulation(){
    return triangulation;
}

/* Returns the vertices that are specified in the file */
vector<unsigned int> OBJFileReader::getVertexIndices(){
    return vertexIndices;
}

vector<vector<float>> OBJFileReader::getTextures(){
    return textures;
}

vector<vector<float>> OBJFileReader::getVertexNormals(){
    return vertexNormals;
}

// Normalize an object to fit it into the NDC cube
vector<vector<float>> OBJFileReader::normalize(vector<vector<float>> vec){
    float minX = 0.0, maxX = 0.0;
    float minY = 0.0, maxY = 0.0;
    float minZ = 0.0, maxZ = 0.0;

    for(int k = 0; k < (int)vec.size(); k++){
        vector<float> row = vec[k];
        float x = row[0];
        float y = row[1];
        float z = row[2];

        if(x < minX){ minX = x; }
        else if(x > maxX){ maxX = x; }

        if(y < minY){ minY = y; }
        else if(y > maxY){ maxY = y; }

        if(z < minZ){ minZ = z; }
        else if(z > maxZ){ maxZ = z; }
    }

    float scale = sqrt((minX - maxX)*(minX - maxX) +
            (minY - maxY)*(minY - maxY) +
            (minZ - maxZ)*(minZ - maxZ));

    vector<vector<float>> out;

    for(int i = 0; i < (int)vec.size(); i++){
        vector<float> vecrow = vec[i];
        vector<float> outrow;

        outrow.push_back(vecrow[0]/scale);
        outrow.push_back(vecrow[1]/scale);
        outrow.push_back(vecrow[2]/scale);

        out.push_back(outrow);
    }
    return out;
}



/*
        for(int i = 0; i <(int) normalIndices.size();i++){
            vector<int> row = normalIndices[i];
            for(int j = 0; j< (int)row.size();j++){
                cout<<row[j]<<" ";
            }
            cout << endl;
        }
*/









