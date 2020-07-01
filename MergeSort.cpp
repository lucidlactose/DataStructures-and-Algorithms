#include "printArray.cpp"

/*
	Complexity: O(n * logn)
	Explanation: This is one of the fastest sorts matching quicksort.
		Since it starts by breaking down list by halves, it's easy to
		sort. Since it takes O(n) time to combine sorted lists and this
		makes a total of log(n) total lists, it will take n * log(n) time.

		This is an example of a divide and conquer algorithm.
		(Breakdown the problem into small problems and combine them)
*/

void merge( vector<int>& vec, int start, int mid, int end ) {
	/*
		There are 3 steps in merge
			1. Copy the left and right sorted subarrays
			2. Modify the original by comparing the subarrays
			3. Add the leftovers of the sorted subarrays

	*/

	// We want to modify the original, but it has it has two sorted
	// subarrays. Let's copy them first.
	int left = mid - start + 1;
	int right = end - mid;

	vector<int> L( left );
	vector<int> R( right );

	for (int i=0; i < left; ++i) {
		L[i] = vec[ start + i ];
	}
	for (int j=0; j < right; ++j) {
		R[j] = vec[ mid + 1 + j ];
	}

	// Now that we copied the two sorted arrays, we can modify the original.
	//Since these are two sorted arrays, it's easy to combine them.
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

	// Now either Left or Right subarray is empty because of "i" or "j".
	// One of these has leftovers, so let's add the leftovers.
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

void MergeSort( vector<int>& vec, int start, int end ) {
	if (start >= end) {
		return;
	}

	// You might recognize this as post-order traversal.
	// Since we are dividing the array by two every time,
	// we are doing a left and right division too.

	// this equation for mid is faster than (l + r)/2. idk why
	int mid = start + (end - start)/ 2;
	MergeSort(vec, start, mid);
	MergeSort(vec, mid + 1, end);
	merge(vec, start, mid, end);
}

// this function does nothing but call the bigger function
void MergeSort( vector<int>& vec ) {
	MergeSort(vec, 0, vec.size() - 1);
}

int main() {
	vector<int> arr = {  5, 1, 190, 374, 14, 21, 4, 1241, 
			341, 532, 6235, 364, 425, 37, 86745, 89,
			411, 601, 546, 6, 87, 16, 7, 458, 145, 45, 
			7, 8457, 34 };

	MergeSort(arr);
	printArray(arr);

	return 0;
}
