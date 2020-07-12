#include <vector>

/*
	Complexity: O(n * log n)
	Explanation: This is one of the fastest sorts matching QuickSort and HeapSort.
		Merge Sort starts by breaking down a list until the smallest subarray
		possible of size 1. Now that it's small, it's easy to sort because it
		starts with a comparison of 2 numbers, then it's a comparison of sorted
		arrays.
		Since it takes O(n) time to combine sorted lists and this
		makes a total of log(n) total lists, it will take n * log(n) time.

		This is an example of a divide and conquer algorithm.
		(Breakdown the problem into small problems and combine them)
*/

// Complexity: O(n)
// There are 3 steps in merge
//	1. Copy the left and right sorted subarrays.
//	2. Modify the original by comparing the subarrays. It's easy since they're sorted.
//	3. One of the subarrays has leftovers. Put them into the original.
void merge( std::vector<int>& vec, int start, int mid, int end ) {
	// Step 1
	int left = mid - start + 1;
	int right = end - mid;

	std::vector<int> L( left );
	std::vector<int> R( right );

	for (int i=0; i < left; ++i) {
		L[i] = vec[ start + i ];
	}
	for (int j=0; j < right; ++j) {
		R[j] = vec[ mid + 1 + j ];
	}

	// Step 2
	int i=0;
	int j=0;
	int k=start;
	while ( i < left && j < right) {
		if ( L[i] <= R[j] ) {
			vec[k] = L[i];
			i++;
		}
		else {
			vec[k] = R[j];
			j++;
		}
		k++;
	}

	// Step 3
	while ( i < left ) {
		vec[k] = L[i];
		i++;
		k++;
	}

	while ( j < right ) {
		vec[k] = R[j];
		j++;
		k++;
	}
}

// Complexity: O(n * log n)
// This does a post-order breakdown to make sure all subarrays are as small as possible.
// Since it breakds down the array in half each time, the recursion stops at log n where
// n is the size of the array.
// It then calls the merge function 
void mergeSort( std::vector<int>& vec, int start, int end ) {
	if (start >= end) {
		return;
	}

	// You might recognize this as post-order traversal.
	// Since we are dividing the array by two every time,
	// we are doing a left and right division too.

	// this equation for mid is faster than (l + r)/2. idk why
	int mid = start + (end - start)/ 2;
	mergeSort(vec, start, mid);
	mergeSort(vec, mid + 1, end);
	merge(vec, start, mid, end);
}

// *with a cowboy voice* let the program handle itself for moment
void mergeSort( std::vector<int>& vec ) {
	mergeSort(vec, 0, vec.size() - 1);
}

