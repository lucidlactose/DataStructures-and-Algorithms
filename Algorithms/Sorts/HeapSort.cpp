#include "../../DataStructures/MinHeap.cpp"

/*
	Complexity: O(n * log n)
	Explanation: First we have to go through the entire list and insert it into
		the heap. Traversing an array of length n, will take O(n) time, and
		the insertion of the MinHeap will take O(log n) because it is a 
		complete binary tree. Ultimately resulting in a O(n * log n) complexity.

		The main challenge of this version of heapSort is how we implement
		the MinHeap (very minimal version for the problem found in Data
		Structures folder).
*/
void heapSort( std::vector<int>& vec ) {
	MinHeap h;
	int size = vec.size();

	// Complexity O(n * log n)
	// Every time we add to our complete tree, the size grows and we need to
	// heapify. Since it's is a complete tree, the max size and time needed to
	// traverse will always be log(n) where n is the size of the array.
	for (int i=0; i < size; ++i) {
		h.insert(vec[i]);
	}

	// Complexity: O(n * log n)
	// When we extract with O(log n) time, we get our smallest value every time.
	// We repeat until we fill our original array of size n.
	for (int i=0; i < size; ++i) {
		vec[i] = h.extract();
	}
}

