#include "../printArray.cpp"
using namespace std;

/*
	Complexity: O(n * n)
	Explanation: n is the length of the list.
			The first for loop runs from i=0 to n times while
			the second runs from j=i to n times. Both loops
			are n and since they are nested, n * n complexity

			Even in the best case, this sort will run through
			the entire list every time so Omega(n * n)

*/
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
