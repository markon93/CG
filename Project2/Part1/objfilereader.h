#ifndef OBJFILEREADER_H
#define OBJFILEREADER_H
#include <QObject>

class OBJFileReader
{
public:
    OBJFileReader(std::string filename);

    std::string getUserInput(std::string prompt);
    bool formatData();
    std::vector<std::vector<float>> getVertices();

private:
    std::vector<float> getFloats(std::string line);
    std::vector<std::string> getStrings(std::string line);
    std::vector<std::string> parseFaceString(std::string str);
    std::vector<float> normalizeVec(std::vector<float> vec);
    std::vector<std::vector<float>> centerVertices(std::vector<std::vector<float>> vertexList);
    std::vector<std::vector<float>> triangulate(std::vector<std::vector<float>> verticeData);

    std::string filename;
    std::vector<std::vector<float>> vertexList, vertices, normals, textures;
    std::vector<std::vector<std::string>> faces;
};

#endif
