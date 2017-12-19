#ifndef OBJFILEREADER_H
#define OBJFILEREADER_H
#include <QObject>

class OBJFileReader
{
public:
    OBJFileReader();
    void updateData(std::string filename);

    std::string getUserInput(std::string prompt);
    bool formatData();
    std::vector<std::vector<float>> getVertices();
    std::vector<unsigned int> getVertexIndices();
    std::vector<std::vector<float>> getTriangulation();
    std::vector<std::vector<float>> getTextures();
    std::vector<std::vector<float>> getNormals();
//    std::vector<unsigned int> getTextureIndices();

private:
    std::vector<float> getFloats(std::string line);
    std::vector<std::string> getStrings(std::string line);
    std::vector<std::string> parseFaceString(std::string str);
    std::vector<float> normalizeVec(std::vector<float> vec);
    std::vector<std::vector<float>> centerVertices(std::vector<std::vector<float>> vertexList);
    std::vector<std::vector<float>> triangulate(std::vector<std::vector<float>> verticeData);

    std::string filename;
    std::vector<std::vector<float>> vertices, triangulation, normals, textures;
    std::vector<std::vector<std::string>> faces;
    std::vector<unsigned int> vertexIndices;

    std::vector<std::vector<float>> normalize(std::vector<std::vector<float>>);
    void clearData();
};

#endif
