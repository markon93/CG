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

//--------- SPLIT THIS INTO 2 FUNCTIONS!!!! -----------//
/*  */
QVector<string> OBJFileReader::getStrings(string line){
    istringstream iss(line);
    QVector<string> faces;
    string token;
    while (iss >> token) {
        faces.push_back(token);
        QVector<string> parsedToken = parseFaceString(token);
        vertices.push_back(vertexList[stoi(parsedToken[0]) - 1]);
    }
    return faces;
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

    cout << "SCALE: " << scale << endl;

    for(it = vec.begin(); it != vec.end(); it++){
        *it = *it/scale;
        cout << *it << endl;
    }
    return vec;
}

/* Puts the vertex-, face- and texture data from a file in vectors. */
bool OBJFileReader::formatData(string filename){
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
                    vertexList.push_back(normalizeVec(getFloats(rest)));
                }

                // Add face data x/y/z to a list (vector with strings)
                else if(tag == "f "){
                    fGiven = true;
                    faces.push_back(getStrings(rest));
                }
            }
        }
    }
    else{
        cout << "Unable to open file \"" << filename << "\"\n";
        return false;
    }
    return true;
}



