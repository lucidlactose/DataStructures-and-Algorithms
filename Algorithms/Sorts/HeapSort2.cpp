#include <vector>

/*
	Complexity: O(n * logn)
	Explanation: You only need a single heapify helper to sort the array.
		What the helper does is dependent on your type of heap

 		If you're going to use a max heap, use the heapifyDown
 		If you're going to use a min heap, use the heapifyUp
		The idea is that you shrink the size of the array passed into the
 		helper so the max/min bubbles to the edge, and then cut it from the heap
*/

// Complexity: O(log n)
// Technically, we don't need an entire MinHeap. We only need a function that makes
// our array into a heap. Whether you heapifyDown or heapifyUp depends on the main
// functions final loop.
// -	If we heapifyDown, we'll result with a min heap and a min index parameter.
// -	if we heapifyUp, we'll result with a max heap and a max index parameter.
// The reason we take in an index, is because we don't want to heapify the entire
// array, just until a certain index.
//
// (P.S. This one is a max heap)
void heapifyHelper( std::vector<int>& vec, int size, int index ) {
	int largest= index;
	int left = 2 * index + 1;
	int right = 2 * index + 2;

	if (left < size && vec[left] > vec[largest]) {
		largest= left;
	}
	if (right < size && vec[right] > vec[largest]) {
		largest = right;
	} 
	if (largest != index) {
		std::swap(vec[index], vec[largest]);
		heapifyHelper(vec, size, largest);
	}
}

// Complexity: O(n * log n)
// We need two loops here.
// 1. First one max it into a prime and proper min heap.
// 2. Second, we do the equivalent of an extract and move the largest value to the back.
//	Then, we shrink the total size passed into our heapify function so we don't
//	mess with the already sorted values.
//	Now we loop until finish.
void heapSort2( std::vector<int>& vec ) {
	int size = vec.size();

	// Complexity: O(n * log n)
	for (int i= size/2 -1; i >= 0; --i) {
		heapifyHelper(vec, size, i);
	}

	// Complexity: O(n * log n)
	for (int i= size-1; i > 0; --i) {
		std::swap(vec[0], vec[i]);
		heapifyHelper(vec, i, 0);
	}
	
}

