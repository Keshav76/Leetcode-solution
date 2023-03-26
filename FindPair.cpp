// Question: https://practice.geeksforgeeks.org/problems/find-pair-given-difference1559

// Find Pair Given Difference

// Sort then two pointers both from left

bool findPair(int arr[], int n, int k){
    //code
    sort(arr, arr+n);
    int i = 0, j = 0;
    while (i < n && j < n) {
        if (i != j && arr[j] - arr[i] == k) return true;
        else if (arr[j] - arr[i] > k) i ++;
        else j ++;
    }
    return false;
}
