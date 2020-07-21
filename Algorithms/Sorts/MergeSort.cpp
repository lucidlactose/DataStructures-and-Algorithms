#include <vector>

/*
	Complexity: O(n * log n) time
				O(log n) 	 implicit space
				O(n)		 explicit space
				Where n in all cases is the size of the array
	Explanation: 
		******************************* TIME *******************************
		Merge Sort starts by breaking down a list until the smallest subarray
		possible of 1 item. Now that it's 1 item, it takes O(n) time to merge
		sorted arrays. As they merge into bigger and bigger arrays, it stays O(n).
		
		It breaks down lists O(log n) times. Since it takes O(n) to merge a list,
		then it takes O(n * log n) time.

		******************************* SPACE *******************************
		Implicit:
			Because it needs to break down the array, it does a recursive amount of
			calls. The most amount it will do is log(n) amount, therefore O(log n)
		Explicit:
			Note that this is not an in-place algorithm or else this would have
			constant space.

			When merging arrays, it needs to copy over the left and right values
			into two arrays. The max size of these arrays will be half of the
			total array. This means O(n/2 + n/2) or O(n).

		NOTES: This is often compared to QuickSort and HeapSort for also having
		O(n * log n) runtime and being very fast. Notice this is a post-order
		function when coding this from scratch.

		This is an example of a divide and conquer algorithm.
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
