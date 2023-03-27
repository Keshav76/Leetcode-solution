// Question: https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620

// Count Inversions

// Approach: Merge Sort and increment count whenever you find an out of order value;
// Also consider the update for all elements that might be there but not getting checked

long long merge(long long arr[], long long l, long long mid, long long h) {
    long long i = l, j = mid, k = 0;
    long long count = 0;
    long long ans[h - l + 1];
    while (i < mid && j <= h) {
        if (arr[i] > arr[j]) {
            ans[k] = arr[j];
            j ++;
            k ++;
            count += mid - i;
        }
        else {
            ans[k] = arr[i];
            k ++;
            i ++;
        }
    }
    while (i < mid) {
        ans[k++] = arr[i];
        i++;
    }
    while (j <= h) {
        ans[k++] = arr[j];
        j ++;
    }
    for (long long i = l; i <= h; i ++) {
        arr[i] = ans[i - l];
    }
    return count;
}
long long mergeSort(long long arr[], long long l, long long r) {
    if (l >= r) return 0; 
    long long mid = l + (r - l) / 2;
    long long left = mergeSort(arr, l, mid);
    long long right = mergeSort(arr, mid+1, r);
    long long merging = merge(arr, l, mid+1, r);
    return left + right + merging;
}
long long inversionCount(long long arr[], long long N) {
    long long ans = mergeSort(arr, 0, N-1);
    return ans;
}
