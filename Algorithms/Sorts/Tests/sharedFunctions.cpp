#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

#ifndef PRINTARRAY
#define PRINTARRAY
void printArray( std::vector<int>& vec ) {
	for (int i=0; i < vec.size(); ++i) {
		cout << vec[i] << " ";
	}
	cout << endl;
}
#endif 

#ifndef TAKEINPUT
#define TAKEINPUT
void takeInput( vector<int>& vec, string file_name ) {
	int temp;
	fstream inFile;
	inFile.open(file_name);
	while (inFile >> temp) {
		vec.push_back(temp);
	}
	inFile.close();
}
#endif

#ifndef MAKEOUTPUT
#define MAKEOUTPUT
void makeOutput( const vector<int>& vec, string file_name, string test ) {
	ofstream out_file;
	file_name += test + ".txt";
	out_file.open(file_name);

	for (int i=0; i < vec.size(); ++i) {
		out_file << vec[i] << " ";
	}
	out_file << endl;

	out_file.close();
}
#endif
