// Question: https://www.geeksforgeeks.org/ceiling-in-a-sorted-array/

// Ceiling in a Sorted Array

// Approach: Binary Search

int ceiling (vector<int> arr, int k) {
    int l = 0, r = arr.size() - 1;
    while (l < r) {
        int mid = l + (r-l) / 2;
        if (arr[mid] > k) {
            r = mid;
        }
        else 
            l = mid + 1;
    }
    if (arr[l] < k) return -1;
    return arr[l];
}
