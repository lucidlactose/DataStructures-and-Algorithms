#include <vector>

/*
	Complexity: O(n * n) time
				O(1)	 explicit space
	Explanation: n is the length of the list.
			The first for loop runs from i=0 to n times while
			the second runs from j=i to n times. Both loops
			are n and since they are nested, n * n complexity
*/

void selectionSort( std::vector<int>& vec ) {
	for (int i=0; i < vec.size(); ++i) {
		int _min = i;
		for (int j=i; j < vec.size(); ++j) {
			if ( vec[j] < vec[_min] ) {
				_min = j;
			}
		}

		if (_min != i) {
			std::swap( vec[i], vec[_min] );
		}
	}
}
