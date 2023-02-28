// Question: https://www.geeksforgeeks.org/chocolate-distribution-problem/

// Chocolate Distribution Problem

// Approach: Sort + Sliding Window

#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<int> arr = { 12, 4,  7,  9,  2,  23, 25, 41, 30, 40, 28, 42, 30, 44, 48, 43, 50 };
    int m = 7, ans = INT_MAX, n = arr.size();
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n - m + 1; i ++) {
        ans = min (ans, arr[i + m - 1] - arr[i]);
    }
    cout << ans;
    return 0;
}
