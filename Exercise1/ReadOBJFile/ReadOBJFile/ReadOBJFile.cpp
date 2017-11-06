// test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <String>
#include <vector>
#include <sstream>
using namespace std;

/* Get filename from  user via command line */
string getFilename() {
	cout << "Enter file name: ";
	string filename;
	cin >> filename;
	return filename;
}

/* Check which tag type is on a certain line in the file */
string checkTag(string line) {
	string tag;
	if (line.length() > 0) {
		tag = line[0];
		if (line[0] == 'v') {
			if (line[1] == 't') {
				tag = line[1];
			}
			else if (line[1] == 'n') {
				tag = line[1];
			}
		}
	}
	return tag;
}

vector <float> getVertices(string line) {

	std::istringstream iss(line);
	string word;
	while (iss >> word) {
		cout << word << endl;
	}
	vector<float> p = { 1.1f };
	return p;
}


/* Main */
int main()
{
	// Get file name, open it for reading
	string filename = "cube.obj.txt";// getFilename();
	cout << "Entered filename " << filename << ".\n";
	ifstream data(filename);

	vector < vector <float> > vertices;

	// Read a line at a time
	string line;
	if (data.is_open()) {
		while (getline(data, line)) {
			string tag = checkTag(line);
			if (tag == "v") {
				vertices.push_back(getVertices(line));
			}
		}
		data.close();
	}
	else cout << "Unable to open file\n";

	return 0;
}
