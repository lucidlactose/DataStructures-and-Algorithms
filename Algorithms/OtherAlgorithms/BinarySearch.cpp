#include "../printArray.cpp"
/*
	Complexity: 
		Best: O(1) Worst: O(log n)
	Explanation: This only works on SORTED arrays and works by dividing
		the array in half each time. Using the variable n for length
		of the array, and the constant division by 2 results in a
		complexity that is logarithmic: O(log n)

	Extra:
		Always remember this went talking about traversing arrays.
		If the array is sorted in ANY way, then you're using binary
		search.

		There is also a sometimes case, where both "mid + 1" and the
		"mid - 1" is not needed (only 1 is needed).
*/

// Basic binary search that returns the index of the searched item
// Else it returns -1
int binarySearch( const vector<int>& vec, int val) {
	int left = 0;
	int right = vec.size() -1;
	while (left <= right) {
		int mid = left + (right - left)/2;

		if (vec[mid] == val) {
			return mid;
		}
		else if (vec[mid] < val) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	return -1;
}

int main() {
	vector<int> arr = { 9, 13, 14, 21, 25, 28, 37, 39, 42, 44, 55, 56, 65, 72, 77, 80, 82, 87, 92, 96 };

	cout << "index: " << binarySearch(arr, 92) << endl;
	cout << "index: " << binarySearch(arr, 91) << endl;

	return 0;
}
