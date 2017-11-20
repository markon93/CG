#include <iostream>
#include <fstream>
#include <sstream>
#include <QVector>
#include <string>
#include <math.h>
using namespace std;
#include "objfilereader.h"

OBJFileReader::OBJFileReader(){

}

QVector<QVector<float>> vertexList, vertices, normals, textures;
QVector<QVector<string>> faces;

/* Get user input.
    - prompt: Message to the user with what to enter.
    - returns: The string that the user entered.
*/
string OBJFileReader::getUserInput(string prompt){
    cout << prompt;
    string input;
    cin >> input;
    return input;
}

/* Returns a vector with floats from a string where they are separated by spaces. */
QVector<float> OBJFileReader::getFloats(string line){
    istringstream iss(line);
    QVector<float> values;
    string token;
    while (iss >> token) {
        QString qtoken = QString::fromStdString(token);
        float val = qtoken.toFloat();
        values.push_back(val);
    }
    return values;
}

/* Takes a string on the form x/y/z (y and/or z not mandatory) and return a vector on the form [x, y, z].
*/
QVector<string> OBJFileReader::parseFaceString(string str){
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
    QVector<string> output;
    output.push_back(vertexIndex);
    output.push_back(textureIndex);
    output.push_back(normalIndex);
    return output;
}

/* Splits a line consisting of strings into a vector */
QVector<string> OBJFileReader::getStrings(string line){
    istringstream iss(line);
    QVector<string> out;
    string token;
    while (iss >> token) {
        out.push_back(token);
    }
    return out;
}

/* Returns the vertices that are specified in the file */
QVector<QVector<float>> OBJFileReader::getVertices(){
    return vertices;
}

/* Normalize a 3d vector */
QVector<float> OBJFileReader::normalizeVec(QVector<float> vec){
    QVector<float>::iterator it;
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
QVector<QVector<float>> OBJFileReader::triangulate(QVector<QVector<float>> verticeData){
    QVector<QVector<float>> triangulation;
    QVector<QVector<float>>::iterator i;
    QVector<QVector<float>>::iterator j;
    QVector<QVector<float>>::iterator k;

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
QVector<QVector<float>> OBJFileReader::centerVertices(QVector<QVector<float>> vertexList){
    double sumX = 0.0, sumY = 0.0, sumZ = 0.0;
    QVector<QVector<float>>::iterator it;
    for(it = vertexList.begin(); it != vertexList.end(); it++){

        QVector<float> row = *it;
        QVector<float>::iterator it2;
        for(it2 = row.begin(); it2 != row.end(); it2++){
            sumX += row[0];
            sumY += row[1];
            sumZ += row[2];
        }
    }
    double aveX = sumX/(3*vertexList.size());
    double aveY = sumY/(3*vertexList.size());
    double aveZ = sumZ/(3*vertexList.size());

    for(int i = 0; i < vertexList.size(); i++){
        vertexList[i][0] -= aveX;
        vertexList[i][1] -= aveY;
        vertexList[i][2] -= aveZ;
    }
    return vertexList;
}


/* Puts the vertex-, face- and texture data from a file in vectors. */
bool OBJFileReader::formatData(string filename){
    bool fGiven = false;
    vertexList.clear();
    vertices.clear();
    faces.clear();
    ifstream data(filename);
    string line;
    if(data.is_open()){
        while(getline(data, line)){
            if (line.size() > 1){
                string tag = line.substr (0,2);
                string rest = line.substr(2,line.size());

                // Add vertices to a list (vector with float values)
                if(tag == "v "){
                    vertexList.push_back(normalizeVec(getFloats(rest)));
                }

                // Add face data x/y/z to a list (vector with strings)
                else if(tag == "f "){
                    fGiven = true;
                    faces.push_back(getStrings(rest));
                }
            }
        }

        // Center the vertices at the origin
        vertexList = centerVertices(vertexList);

        // Use face data to calculate triangulation if it is given
        QVector<QVector<string>>::iterator it;
        if(fGiven){
            for(it = faces.begin(); it != faces.end(); it++){
                QVector<string>::iterator it2;
                QVector<string> row = *it;
                for(it2 = row.begin(); it2 != row.end(); ++it2){
                    QVector<string> parsedFaceData = parseFaceString(*it2);
                    vertices.push_back(vertexList[stoi(parsedFaceData[0]) - 1]);
                }
            }
        }
        else{
            vertices = triangulate(vertexList);
        }
    }
    else{
        cout << "Unable to open file \"" << filename << "\"\n";
        return false;
    }
    return true;
}



