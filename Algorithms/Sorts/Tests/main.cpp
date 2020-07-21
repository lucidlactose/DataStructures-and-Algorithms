#include "../BubbleSort.cpp"
#include "../CountingSort.cpp"
#include "../HeapSort.cpp"
#include "../HeapSort2.cpp"
#include "../MergeSort.cpp"
#include "../QuickSort.cpp"
#include "../RadixSort.cpp"
#include "../SelectionSort.cpp"

#include "test.cpp"
#include <unordered_map>

int main() {
    unordered_map<string, SortFuncPointer> sortFunctions;

	// if for whatever reason this breaks at some point, it's counting sort's fault
    sortFunctions["bubbleSort"] = &bubbleSort;
    sortFunctions["countingSort"] = &countingSort;
	sortFunctions["heapSort"] = &heapSort;
	sortFunctions["heapSort2"] = &heapSort2;
	sortFunctions["mergeSort"] = &mergeSort;
	sortFunctions["quickSort"] = &quickSort;
	sortFunctions["selectionSort"] = &selectionSort;

    test(sortFunctions, "1");
    test(sortFunctions, "2");
    
    return 0;
}
