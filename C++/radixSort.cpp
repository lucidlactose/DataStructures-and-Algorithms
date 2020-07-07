#include "printArray.cpp"

// Complexity: O(n)
// This is a helper to find the max values in an array
int findMax( const vector<int>& vec ) {
	int _max = vec[0];
	for (int i=0; i < vec.size(); ++i) {
		_max = max(_max, vec[i]);
	}
	return _max;
}


// Complexity: O(n)
// This helper has 4 steps in it
// 1. Fill the buckets based on which digit you want
//	- the equation for this is (vec[i]/ digits) % 10 where "digits" is
//		the 1s place, 10ths, or 1000s
// 2. Adjust the buckets for it's indexes
// 3. Iterate backwards through the list, using the equation above to find
//	their new indexes in the buckets
// 4. Copy everything over
void radixSortHelper( vector<int>& vec, int digits ) {
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
	vector<int> neo(vec.size(), 0);
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
//		the whole array 3 times.
//		The number of times the helper runs is based on the digits of the max
//		number in the array, aka k or log(k).
void radixSort( vector<int>& vec ) {
	int _max = findMax(vec);

	// this loops log(k) times where k is the biggest digit in the array
	for (int digits = 1; _max/ digits > 0; digits *= 10) {
		radixSortHelper( vec, digits );
	}
}

int main() {
	vector<int> arr = { 5, 8, 65, 12, 43, 54, 65, 76, 87, 91, 14, 25, 37, 74, 85, 42 };

	radixSort(arr);
	printArray(arr);
	
	return 0;
}
