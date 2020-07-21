#include "../../DataStructures/MinHeap.cpp"

/*
	Complexity: O(n * log n) time
				O(n)		 explicit space
				Where n is the size of the array.
	Explanation:
		******************************* TIME *******************************
		In order to use our MinHeap, we have to insert and extract every single
		value. The insertion time for this MinHeap is O(log n). Because we are
		doing this to every value in our array, we will have O(n * log n).

		******************************* SPACE *******************************
		The amount of space is dependent on the implementation, but this MinHeap
		makes a new node in the tree for a total of O(n) space.

		NOTES:
		The main challenge of this version of heapSort is how we implement
		the MinHeap (very minimal version for this sort found in Data Structures
		folder).
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
