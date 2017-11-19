#ifndef OBJFILEREADER_H
#define OBJFILEREADER_H
#include <QObject>
#include <QVector>
class OBJFileReader
{
public:
    OBJFileReader();
    std::string getUserInput(std::string prompt);
    bool formatData(std::string filename);
    QVector<QVector<float>> getVertices();

private:
    QVector<float> getFloats(std::string line);
    QVector<std::string> getStrings(std::string line);
    QVector<std::string> parseFaceString(std::string str);
    QVector<float> normalizeVec(QVector<float> vec);
};

#endif
