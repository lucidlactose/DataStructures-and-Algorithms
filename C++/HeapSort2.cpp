// Complexity: O(n * logn)
// Explanation: You only need a single heapify helper to sort the array.
// 		What the helper does is dependent on your type of heap
// 		If you're going to use a max heap, use the heapifyDown
// 		If you're going to use a min heap, use the heapifyUp
//		The idea is that you shrink the size of the array passed into the
// 		helper so the max/min bubbles to the edge, and then cut it from the heap
void heapifyHelper( vector<int>& vec, int size, int index ) {
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
		swap(vec[index], vec[largest]);
		heapifyHelper(vec, size, largest);
	}
}

void heapSort2( vector<int>& vec, int size ) {
	for (int i= size/2 -1; i >= 0; --i) {
		heapifyHelper(vec, size, i);
	}
	for (int i= size-1; i > 0; --i) {
		swap(vec[0], vec[i]);
		heapifyHelper(vec, i, 0);
	}
	
}
