#include "printArray.cpp"

// This MinHeap has the basic insert, and extract functions
// There are variations that allow direct modification of the array, but I
// only wanted enough for the heap sort
class MinHeap {
	int sz;
	vector<int> data;

	// When you add to a heap, you push to the end and then
	// bubble it up until it reaches it's right place
	// Complexity: O(logn)
	// Explanation: The duration is dependent on the height of the tree (h or logn).
	//		Sometimes, people don't make a heapifyUp function since it's
	// 		so small and doesn't need recursion like heapifyDown
	void heapifyUp(int index) {
		while (index != 0 && data[parent(index)] > data[index]) {
			swap(data[index], data[parent(index)]);
			index = parent(index);
		}
	}

	// When you delete from a heap, you swap with the end, decrease size
	// and then sinks it down to it's right place
	// Complexity: O(logn)
	// Explanation: The duration is dependent on the height of the tree (h or logn)
	void heapifyDown(int index) {
		int left = index * 2 + 1;
		int right = index * 2 + 2;
		int smallest = index;

		if (left < data.size() && data[left] < data[smallest]) {
			smallest = left;
		}
		if (right < data.size() && data[right] < data[smallest]) {
			smallest = right;
		}
		if (smallest != index) {
			swap(data[index], data[smallest]);
			heapifyDown(smallest);
		}
	}
public:
	MinHeap() {}
	int empty() {
		return data.size() == 0;
	}

	// Some people make parent, left, and right functions. I only needed this one
	int parent(int i) {
		return (i-1)/2;
	}

	// O(1)
	int top() {
		if (!empty()) {
			return data[0];
		}
		return -1;
	}

	// O(logn) bc of heapifyUp
	void insert(int val) {
		data.push_back(val);
		int index = data.size() -1;
		heapifyUp(index);

	}

	// O(logn) bc of heapifyDown
	// somtimes goes by the name of extractMin
	int extract() {
		if (!empty()) {
			int a = data[0];
			swap(data[0], data[data.size() -1]);
			data.pop_back();
			heapifyDown(0);
			return a;
		}
		return -1;
	}
};

