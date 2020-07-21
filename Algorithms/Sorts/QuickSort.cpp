#include <vector>

/*
	Complexity: O(n * log n) time
				O(log n) 	 implicit space
				O(1)		 explicit space
				Where n is the size of the array.
	Explanation:
		******************************* TIME *******************************
		The array is O(log n) because ideally, we will split the array in half
		every time based on our pivot. A typical unsorted won't split perfectly
		in half, but the result is still logarithmic.

		******************************* SPACE *******************************
		The maximum amount of recursive calls will be O(log n) because the
		pivot will always make the array smaller to some logarithmic scale.
		However, this depends on the implementation. This is in-place so O(log n)
		and there exists a variation of O(n) space to copy over values.

		NOTES:
		Fun fact: How fast this is is how fast we can guess our perfect pivot
		that always lands in the middle. There are variations of QuickSort that
		try to makes this faster.

		This is an example of a divide and conquer algorithm.
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
