// Question: https://www.geeksforgeeks.org/given-a-sorted-and-rotated-array-find-if-there-is-a-pair-with-a-given-sum/

// Pair sum in a rotated sorted array

// Approach: Binary Search => Two Pointer

#include <bits/stdc++.h>
using namespace std;

bool findPair(vector<int> arr, int target) {
    int l = 0, r = arr.size() - 1, pi = 0, n = arr.size();
    while (l <= r) {
        int mid = l + (r-l)/2;
        if (arr[mid] >= arr[0]) l = mid + 1;
        else {
            pi = mid;
            r = mid - 1;
        }
    }
    
    // New Sorted array starts from pi and goes upto (pi + n)%n i.e. pi - 1
    
    // Two Pointer approach
    
    int i = pi, j = pi + n - 1;
    while (i < j) {
        int I = i % n, J = j % n;
        if ( arr[I] + arr[J]  == target) {
            return true;
        }
        else if (arr[I] + arr[J] > target){
            j --;
        }
        else {
            i ++;
        }
    }
    return false;
}

int main() {
	
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i ++) {
        cin >> arr[i];
    }
    cin >> n;
    auto ans = findPair(arr, n);
    cout << (ans ? "True" : "False");
	return 0;
}
