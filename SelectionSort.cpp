#include <iostream>
#include "printArray.cpp"

void SelectionSort( vector<int>& vec ) {
	
	for (int i=0; i < vec.size(); ++i) {
		int _min = i;
		for (int j=i; j < vec.size(); ++j) {
			if ( vec[j] < vec[_min] ) {
				_min = j;
			}
		}

		if (_min != i) {
			swap( vec[i], vec[_min] );
		}
	}

}

int main() {
	vector<int> arr = {4, 1, 22, 4, 5, 5, 2, 7, 6235, 6, 362531, 2532, 454 };

	SelectionSort(arr);
	printArray(arr);

	return 0;
}

