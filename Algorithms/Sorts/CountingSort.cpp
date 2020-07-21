#include <vector>

// WARNING THIS FILE RANDOMLY GETS A SEGMENTATION FAULT

/*
    Complexity: O(n + k) time
                O(k)     explicit space
                Where n is the size of the array and k is the largest integer.
    Explanation: 
        ******************************* TIME *******************************
        This array counts the occurance of every number and assigns it's index
        based on that. The smaller numbers will have a smaller index so it comes
        out sorted. There is no nested loops or recusive calls. Just very long
        for loops.
        
        ******************************* SPACE *******************************
        In order to accomidate every integer possible in the array, we need to
        make sure its biggest value fits. This can mean a very large array since
        it will be made from 0 - k.

        NOTES:
        This may look similar to radix sort, but this is faster with worse space
        efficiency. While radix sort only needs a few buckets based on its base,
        this sort makes a bucket for every possible number.

        This, for obvious index reasons, is a specialized sort that only works
        with positive integers.
*/

int findMax( std::vector<int>& arr ) {
    int _max = arr[0];
    for (int i=0; i < arr.size(); ++i) {
        _max = std::max(_max, arr[i]);
    }
    return _max;
}

// Complexity: O(n)
// 1. Fill the buckets. It's digit is it's index
// 2. Use size of buckets to calculate indexes
// 3. Iterate backwards through the list, using their index in the buckets
// 4. Copy everything over
void countingSort( std::vector<int>& arr ) {
    if (arr.size() == 0) {
        return;
    }
    int RANGE = findMax(arr) +1;
    // the range is the max value, bc this is for "char", the max value is 255 for ascii characters
    std::vector<int> count(RANGE, 0);
    std::vector<char> output(arr.size());

    // Step 1
    for (int i=0; i < arr.size(); ++i) {
        ++count[arr[i]];
    }

    // Step 2
    for (int i=1; i < RANGE; ++i) {
        count[i] += count[i-1];
    }

    // Step 3
    for (int i=0; i < arr.size(); ++i) {
        output[count[arr[i]]-1] = arr[i];
        --count[arr[i]];
    }

    // Step 4
    for (int i=0; i < arr.size(); ++i) {
        arr[i] = output[i];
    }
}
