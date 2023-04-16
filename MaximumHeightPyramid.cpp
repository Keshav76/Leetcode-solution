// Question : https://www.geeksforgeeks.org/find-maximum-height-pyramid-from-the-given-array-of-objects/

// Maximum Height Pyramid From Given Array

// Approach : Check how many levelss can be added. 
// By sorting

#include<bits/stdc++.h>
using namespace std;
int maxLevel(int boxes[], int n) {
    int a = sqrt(2 * n);
    if (a * (a + 1) < 2 * n) return a;
    return a - 1;
}
int main() {
    int n; cin >> n;
    int arr[n];
    for (int i=0; i < n; i++) cin >> arr[i];
    cout << maxLevel(arr, n);
}
