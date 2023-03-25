// Question: https://www.geeksforgeeks.org/permute-two-arrays-sum-every-pair-greater-equal-k/

// Permute two arrays such that sum of every pair is greater or equal to K

// Approach: Sort first array in ascending and other in descending

#include<bits/stdc++.h>
using namespace std;

string checkPermute (vector<int> &a, vector<int> &b, int k) {
    sort(begin(a), end(a));
    sort(begin(b), end(b), greater<int>());
    for (int i = 0; i < a.size(); i++) {
        if (a[i] + b[i] < k) 
            return "False";
    }
    return "True";
}

int main() {
    vector<int> v1 = {2,4,5};
    vector<int> v2 = {7,8,10};
    int k = 12;
    cout << checkPermute(v1, v2, k);
}
