#include <vector>

/*
	Complexity: O(n * n) time
				O(1)	 explicit space
				Where n is the size of the array.
	Explanation: n is the length of the list.
			The first for loop runs from i=0 to n times while the second
			runs from any place of the array until the end. Both loops are
			n since the both run to the end and the nesting results in O(n * n).
*/

void bubbleSort( std::vector<int>& vec ) {
	for (int i=0; i < vec.size() - 1; ++i) {
		for (int j=i; j < vec.size(); ++j) {
			if (vec[i] > vec[j]) {
				std::swap(vec[i], vec[j]);
			}
		}
	}
}
