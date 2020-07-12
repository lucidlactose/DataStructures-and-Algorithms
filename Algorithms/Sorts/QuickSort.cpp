#include <vector>

/*
	Complexity: O(n * log n)
	Explanation: This is also a divide and conquer algorithm similar to
		MergeSort and has similar runtime. The difference being that
		QuickSort sorts as it is breaks down into subarrays as a pre-order
		sort vs MergeSort that connects everything once it's broken down
		being a post-order sort.

		The array is split in half everytime result in a O(log n/ log 2),
		but since log 2 is constant, we usually say O(log n). We get O(n)
		because we must break down the array to single bits, therefore
		going through the whole array. The length of the array being n.

		The effectiveness of QuickSort is dependent on you pivot. There
		is debate over whether quick sort and merge sort is faster, but
		there are variations of Quick sort that is faster than both. The
		main problem is that it needs to have an educated guess before
		choosing the pivot, and the methods for doing that can slow down
		the sort. Because of this random pivots are *usually* better than
		educated guesses and result in faster sorts.
*/

// Complexity: O(n)
// This function only wants 2 things
// Everything to the LEFT of the pivot is LESS and
// Everything to the RIGHT of the pivot is MORE
// Once this happens, place the pivot snuggly in it's new index and return that index
int partition( std::vector<int>& vec, int start, int end) {
	int pivot = vec[end];
	int i = start -1;

	for (int j=start; j <= end -1; ++j) {
		if (vec[j] < pivot) {
			i++;
			std::swap(vec[i], vec[j]);
		}
	}
	std::swap(vec[++i], vec[end]);
	return i;
}


// Complexity: O(n * log n)
// this is a recursive 
void quickSort( std::vector<int>& vec, int start, int end) {
	if (start < end) {
		int pivot = partition(vec, start, end);
		quickSort(vec, start, pivot - 1);
		quickSort(vec, pivot + 1, end);
	}
}

// *with a cowboy accent* sometimes, we just want to pass in a vector and stop thinking
// about the specifics
void quickSort( std::vector<int>& vec ) {
	quickSort(vec, 0, vec.size() -1);	
}

