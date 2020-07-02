#include "MinHeap.cpp"
#include "HeapSort2.cpp"

// Complexity: O(n * logn)
// Explanation: This sort is just two for loops that go through the length of the array n.
// 		The logn comes from the heap's inserting and extracting complexity.
//
void heapSort( vector<int>& vec, int size ) {
	MinHeap h;

	// push everything into the heap
	for (int i=0; i < size; ++i) {
		h.insert(vec[i]);
	}

	// when extracting min values from the heap repeatedly, it comes out sorted
	for (int i=0; i < size; ++i) {
		vec[i] = h.extract();
	}
}

int main() {
	vector<int> arr = { 29, 36, 83, 71, 6, 80, 28, 41, 66, 54, 10,
				12, 60, 32, 7, 1, 12, 98, 5, 32, 125 };
	heapSort(arr, 21);
	//heapSort2(arr, 21);
	printArray(arr);


	return 0;
}
