#include <vector>

/*
	Complexity: O(n * log k) time
				O(1)		 space
				Where n is the size of the array and k is the largest integer
	Exlanation:
	    ******************************* TIME *******************************
		It's obvious we need to go through the array, but the amount of times
		is dependent on the largest integer. Because the helper sorts based on
		the decimal place, we need to go through every one for correctness.
	    
		******************************* SPACE *******************************
		This is a sort of "super sort" because it uses another sort in it's
		in-between steps. In this case, we use a modified CountingSort.
		The space RadixSort uses is tied to it's sub-sort. Since our modified
		CountingSort doesn't use a max value from an array and always does 10,
		it has O(10) or O(1).

		NOTES:
		This is a specialized sort that only works for integers because of
		the way the new index is calculated.
*/

// Complexity: O(n)
// This is a helper to find the max values in an array
int findMax( const std::vector<int>& vec ) {
	int _max = vec[0];
	for (int i=0; i < vec.size(); ++i) {
		_max = std::max(_max, vec[i]);
	}
	return _max;
}

// Complexity: O(n)
// This helper has 4 steps in it
// 1. Fill the buckets based on which digit you want
// 2. Adjust the buckets for it's indexes
// 3. Iterate backwards through the list, using the equation above to find
//	their new indexes in the buckets
// 4. Copy everything over
void radixSortHelper( std::vector<int>& vec, int digits ) {
	int buckets[10] = {0};

	// Step 1
	for (int i= 0; i < vec.size(); ++i) {
		buckets[ (vec[i]/digits) % 10]++;
	}

	// Step 2
	for (int i=1; i < 10; ++i) {
		buckets[i] += buckets[i-1];
	}
	
	// Step 3
	std::vector<int> neo(vec.size(), 0);
	for (int i=vec.size() -1; i >= 0; --i) {
		neo[ --buckets[(vec[i]/digits) % 10 ] ] = vec[i];
	}

	// Step 4
	for (int i=0; i < vec.size(); ++i) {
		vec[i] = neo[i];
	}

}

// Complexity: O(n * log(k))
// Explanation: To find the itself is O(n), but Big O means we take the biggest notation.
//		So, the radixSortHelper has a complexity of O(n) because it runs through
//		the whole array log(k) times.
void radixSort( std::vector<int>& vec ) {
	int _max = findMax(vec);

	// this loops log(k) times where k is the biggest digit in the array
	for (int digits = 1; _max/ digits > 0; digits *= 10) {
		radixSortHelper( vec, digits );
	}
}
