#include "../BubbleSort.cpp"
#include "../SelectionSort.cpp"
#include "../MergeSort.cpp"
#include "../QuickSort.cpp"
#include "../HeapSort.cpp"
#include "../HeapSort2.cpp"
#include "../RadixSort.cpp"

#include <fstream>
#include "sharedFunctions.cpp"

struct TestInput {
	vector< void (*)(vector<int>&) > *sortFunctions;
	vector<int> *arr;
	vector<string> *fileNames;
};

void test(TestInput *t) {


/*
	okaaaaay so how do I do output...
	I can pass in an array that has the string of the file name so I can do
		string file_names[] = { "BubbleSort", ... }
	then I could do this here
		int i =0;
		for (auto& func: sortFunctions) [
			func(temp);
			output(temp, fileName[i++];
		}
	and in my output fiel I do
		out_file.open(filename + ".txt")
*/

	int sz = (t->sortFunctions)->size();
	for (int i=0; i < sz; ++i) {
		vector<int> temp(*(t->arr));
		(*(t->sortFunctions))[i](temp);
		makeOutput(temp, (*(t->fileNames))[i], "Test1");
	}

/*
	for (auto& func: *(t->sortFunctions)) {
		vector<int> temp(*(t->arr));
		func(temp);
		printArray(temp);
	}
*/
}

void test1( TestInput*& input ) {
	vector<int> arr;
	fstream inFile;
	int temp;
	inFile.open("unsortedArray.txt");

	while (inFile >> temp) {
		arr.push_back(temp);
	}

	inFile.close();

	input->arr = &arr;

	test(input);
}


int main() {
	TestInput *input = new TestInput;
	vector< void (*)(vector<int>&) > sortFunctions;
	vector< string > fileNames;

	sortFunctions.push_back(&bubbleSort);
	sortFunctions.push_back(&selectionSort);
	sortFunctions.push_back(&mergeSort);
	sortFunctions.push_back(&quickSort);
	sortFunctions.push_back(&heapSort);
	sortFunctions.push_back(&heapSort2);
	sortFunctions.push_back(&radixSort);

	fileNames.push_back("bubbleSort");
	fileNames.push_back("selectionSort");
	fileNames.push_back("mergeSort");
	fileNames.push_back("quickSort");
	fileNames.push_back("heapSort");
	fileNames.push_back("heap2Sort");
	fileNames.push_back("radixSort");
	
	input->sortFunctions = &sortFunctions;
	input->fileNames = &fileNames;
	
	test1(input);

	delete input;

	return 0;
}

