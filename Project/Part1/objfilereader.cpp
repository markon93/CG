#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;
#include "objfilereader.h"

OBJFileReader::OBJFileReader(string filename){
    this->filename = filename;
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
    while (iss >> token) {
        out.push_back(token);
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
vector<vector<float>> OBJFileReader::centerVertices(vector<vector<float>> vertexList){
    double sumX = 0.0, sumY = 0.0, sumZ = 0.0;
    vector<vector<float>>::iterator it;
    for(it = vertexList.begin(); it != vertexList.end(); it++){
        vector<float> row = *it;
        sumX += row[0];
        sumY += row[1];
        sumZ += row[2];
    }

    double aveX = sumX/(vertexList.size());
    double aveY = sumY/(vertexList.size());
    double aveZ = sumZ/(vertexList.size());

    for(int i = 0; i < (int) vertexList.size(); i++){
        vertexList[i][0] -= aveX;
        vertexList[i][1] -= aveY;
        vertexList[i][2] -= aveZ;
    }
    return vertexList;
}

/* Puts the vertex-, face- and texture data from a file in vectors. */
bool OBJFileReader::formatData(){
    bool fGiven = false;
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
                    faces.push_back(getStrings(rest));
                }

                // Add texture data to a list (vector with floats)
                else if(tag == "vt"){
                    cout << rest << endl;
                    textures.push_back(getFloats(rest));
                }
            }
        }

        // Center the vertices at the origin
        vertices = centerVertices(vertices);

        // Normalize the object row-wise
        vector<vector<float>>::iterator IT;
        for(IT = vertices.begin(); IT != vertices.end(); IT++){
            *IT = normalizeVec(*IT);
        }

        // Use face data to calculate triangulation if it is given, else make one manually
        vector<vector<string>>::iterator it;
        if(fGiven){
            for(it = faces.begin(); it != faces.end(); it++){
                vector<string>::iterator it2;
                vector<string> row = *it;
                for(it2 = row.begin(); it2 != row.end(); ++it2){
                    vector<string> parsedFaceData = parseFaceString(*it2);
                    int index = stoi(parsedFaceData[0]) - 1;
                    triangulation.push_back(vertices[index]);
                    unsigned int uiIndex = index;
                    vertexIndices.push_back(uiIndex);
                }
            }
        }
        else{
            triangulation = triangulate(vertices);
        }
    }
    else{
        cout << "Unable to open file \"" << filename << "\"\n";
        return false;
    }
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

/*
vector<unsigned int> getTextureIndices(){
    return textureIndices;
}
*/












