#include <vector>

/*
	Complexity: O(n * log k)
	Exlanation: O(n) where n is size of the array. O(log k) where k is the largest
		integer in the array. log(k) will give the number of digits of the max
		number. Because of the hashing process, the sorting is very fast.
		We hash based on the current digit starting at the first place to
		10 ^ log(k)th place (ex log(1234) is 4, so 10^4 is 1000)

		This is the fastest sort for integers and will only work for integers.
		If it doesn't use decimals and is a number(short int, HEX, etc), 
		it'll work.
*/
// Complexity: O(n)
// This is a helper to find the max values in an array
int findMax( const std::vector<int>& vec ) {
	int _max = vec[0];
	for (int i=0; i < vec.size(); ++i) {
		_max =std:: max(_max, vec[i]);
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

