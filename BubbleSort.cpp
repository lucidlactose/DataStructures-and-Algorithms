#include <iostream>
#include <vector>
#include "printArray.cpp"
using namespace std;

void bubbleSort( vector<int>& vec ) {

	for (int i=0; i < vec.size() - 1; ++i) {
		for (int j=i; j < vec.size(); ++j) {
			if (vec[i] > vec[j]) {
				swap(vec[i], vec[j]);
			}
		}
	}

}

int main() {
	vector<int> arr = { 6, 4, 50, 23, 54, 12, 54, 12, 61, 98 };
	
	bubbleSort(arr);
	printArray(arr);

	return 0;
}
