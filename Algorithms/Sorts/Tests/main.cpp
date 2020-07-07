#include "../BubbleSort.cpp"
#include "../SelectionSort.cpp"
#include "../MergeSort.cpp"
#include "../QuickSort.cpp"
#include "../HeapSort.cpp"
#include "../HeapSort2.cpp"
#include "../RadixSort.cpp"
#include "../CountingSort.cpp"

#include "test.cpp"
#include <iostream>

int main() {
	TestInput *input = new TestInput;
	vector<SortFuncPointer> sortFunctions;
	vector<string> fileNames;

	// instead of "&bubbleSort", without the & is fine
	sortFunctions.push_back(&bubbleSort);
	sortFunctions.push_back(&countingSort);
	sortFunctions.push_back(&heapSort);
	sortFunctions.push_back(&heapSort2);
	sortFunctions.push_back(&mergeSort);
	sortFunctions.push_back(&quickSort);
	sortFunctions.push_back(&radixSort);
	sortFunctions.push_back(&selectionSort);

	fileNames.push_back("bubbleSort");
	fileNames.push_back("countingSort");
	fileNames.push_back("heapSort");
	fileNames.push_back("heap2Sort");
	fileNames.push_back("mergeSort");
	fileNames.push_back("quickSort");
	fileNames.push_back("radixSort");
	fileNames.push_back("selectionSort");
	
	input->sortFunctions = &sortFunctions;
	input->fileNames = &fileNames;
	
	test(input, "1");
	test(input, "2");

	delete input;

	return 0;
}

