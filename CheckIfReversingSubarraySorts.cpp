// Question: https://www.geeksforgeeks.org/check-reversing-sub-array-make-array-sorted/

// Check if reversing a subarray will make array sorted

// Approach: Find the subarray with reverse order and check if it is the only subarray that is reversed

bool checkSort(vector<int> arr) {
    int n = arr.size(), i;
    for (i = 0; i < n-1; i ++) {
        if (arr[i] > arr[i+1]) {
            break;
        }
    }
    int last;
    if (i == 0) last = INT_MIN;
    else last = arr[i-1];
    int first = arr[i];
    if (i == n - 1) return true;
    for (;i < n-1; i ++) {
        if (arr[i] < arr[i+1]) {
            break;
        }
    }
    if (arr[i] < last) return false;
    if (i == n - 1) return true;
    if (arr[i+1] < first ) return false;
    i++;
    for (; i < n - 1; i ++) {
        if (arr[i] > arr[i+1]) return false;
    }
    return true;
}
