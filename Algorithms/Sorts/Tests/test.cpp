#include <fstream>
#include <unordered_map>
#include "sharedFunctions.cpp"

typedef void (*SortFuncPointer)(vector<int>&);

void test(unordered_map<string, SortFuncPointer> input, string test_number) {
	string test_name = "Test" + test_number;
	vector<int> arr;

	takeInput(arr, "unsortedArray" + test_number + ".txt");	
	for (pair<string, SortFuncPointer> curr : input) {
		vector<int> temp(arr);
		curr.second(temp);
		makeOutput(temp, curr.first, test_name);
	}
}