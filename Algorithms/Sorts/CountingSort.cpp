/*
    NOTE: Similar to radix sort, this only works on numbers.
            Unlike radix sort, this doesn't use recursion and digits for memory efficiency.
            Instead of going digit by digit, it makes an array of size k, where k is the
            largest value in the array.
*/
#include <vector>

// Exact same process as radixSortHelper, but the size of the array varies
// Complexity: O(n)
// This helper has 4 steps in it
// 1. Fill the buckets. It's digit is it's index
// 2. Adjust the buckets for it's indexes
// 3. Iterate backwards through the list, using the equation above to find
//	their new indexes in the buckets
// 4. Copy everything over

#define RANGE 255

void countingSort( std::vector<int>& arr ) {
	// The output character array  
    // that will have sorted arr  
    char output[arr.size()];  
  
    // Create a count array to store count of inidividul  
    // characters and initialize count array as 0  
    int count[RANGE + 1];  
    memset(count, 0, sizeof(count));  
  
    // Store count of each character  
    for(int i = 0; arr[i]; ++i)  
        ++count[arr[i]];  
  
    // Change count[i] so that count[i] now contains actual  
    // position of this character in output array  
    for (int i = 1; i <= RANGE; ++i)  
        count[i] += count[i-1];  
  
    // Build the output character array  
    for (int i = 0; arr[i]; ++i)  
    {  
        output[count[arr[i]]-1] = arr[i];  
        --count[arr[i]];  
    }  
  
    /*  
    For Stable algorithm  
    for (i = sizeof(arr)-1; i>=0; --i)  
    {  
        output[count[arr[i]]-1] = arr[i];  
        --count[arr[i]];  
    }  
      
    For Logic : See implementation  
    */
  
    // Copy the output array to arr, so that arr now  
    // contains sorted characters  
    for (int i = 0; arr[i]; ++i)  
        arr[i] = output[i];  
}
