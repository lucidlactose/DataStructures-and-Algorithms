#include <vector>

/*
	Complexity: O(n * logn) time
				O(1)		explicit space
	Explanation:
		******************************* TIME *******************************
		You only need a single heapify helper to sort the array. The best way
		to do this is using the heapifyDown from the data structure function.
		Here we call it our helper function that turns the array into a MaxHeap
		and is O(log n). We call that function once for every value, resulting
		in O(n * log n) time.

		NOTE:
		This solution exists because we technically don't need an entire MaxHeap
		to solve this problem. All we need is an in-place MaxArray. 
*/

// Complexity: O(log n)
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

