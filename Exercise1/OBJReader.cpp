#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

/* Put float values from a string in a vector */
vector<float> getFloats(string line) {
	istringstream iss(line);
	vector<float> values;
  string token;
  while (iss >> token) {
    values.push_back(stof(token));
	}
	return values;
}

/* Put int values from a string in a vector */
vector<string> getStrings(string line) {
	istringstream iss(line);
	vector<string> strings;
  string token;
  while (iss >> token) {
    strings.push_back(token);
	}
	return strings;
}

/*  */
void formatData(string filename){

	// Open file for reading
	ifstream data(filename);

	// Read a line at a time
  vector <vector<float>> vertices, normals, textures;
  vector <vector<string>> faces;

	string line;
	if (data.is_open()) {
		while (getline(data, line)) {
			char tag = line[0];
			if (tag == 'v') {
        if (line[1] == 'n'){
          line = line.substr(2, line.size());
          normals.push_back(getFloats(line));
        }
        else if(line[1] == 't'){
          line = line.substr(2, line.size());
          textures.push_back(getFloats(line));
        }
        else{
          line = line.substr(1, line.size());
          vertices.push_back(getFloats(line));
        }
      }
      else if(tag == 'f'){
        line = line.substr(1, line.size());
        faces.push_back(getStrings(line));
      }
		}
		data.close();
	}
	else{
    cout << "Unable to open file\n";
    exit(1);
  }

  // Normalizing the object?
  for (std::vector<vector<float>>::iterator it1 = vertices.begin() ; it1 != vertices.end(); ++it1){
    vector<float> row = *it1;
    for (std::vector<float>::iterator it2 = row.begin() ; it2 != row.end(); ++it2){
      std::cout << *it2 << ' ';
    }
    std::cout << '\n';
  }
}

int main(){
  string filename = "cube.obj.txt";
	formatData(filename);
}
