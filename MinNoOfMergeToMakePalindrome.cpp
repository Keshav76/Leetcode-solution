// Question: https://www.geeksforgeeks.org/find-minimum-number-of-merge-operations-to-make-an-array-palindrome/

// Find minimum number of merge operations to make an array palindrome

// Approach: 2 pointer + greedy

#include <bits/stdc++.h>
using namespace std;

int makePalindrome(vector<int> arr) {
    int n = arr.size(), i = 0, j = n - 1, ans = 0;
    while (i < j) {
        if (arr[i] == arr[j]) {
            i ++; 
            j --;
        }
        else if (arr[i] > arr[j]) {
            arr[j-1] += arr[j];
            j --; ans ++;
        }
        else {
            arr[i+1] += arr[i];
            i ++; ans ++;
        }
    }
    return ans;
}

int main() {
    cout << makePalindrome({11,14,15,99});
}
