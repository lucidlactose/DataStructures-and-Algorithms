#include <fstream>
#include "sharedFunctions.cpp"

typedef void (*SortFuncPointer)(vector<int>&);

struct TestInput {
	vector<SortFuncPointer> *sortFunctions;
	vector<int> *arr;
	vector<string> *fileNames;
};

void test(TestInput *input, string test_number) {
    vector<int> arr;
	fstream inFile;
    string test = "Test" + test_number;
	
    int temp;
	inFile.open("unsortedArray" + test_number + ".txt");
	while (inFile >> temp) {
		arr.push_back(temp);
	}
	inFile.close();

	input->arr = &arr;
	int sz = (input->sortFunctions)->size();
	for (int i=0; i < sz; ++i) {
		vector<int> temp(*(input->arr));
		(*(input->sortFunctions))[i](temp);
		makeOutput(temp, (*(input->fileNames))[i], test);
	}
}
