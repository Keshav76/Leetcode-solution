// Question: https://www.geeksforgeeks.org/count-natural-numbers-whose-permutation-greater-number/

// Count natural numbers whose all permutation are greater than that number

// Approach: Check if each element is sorted or not

#include<bits/stdc++.h>
using namespace std;

bool isSorted(int n) {
    int old = 10;
    while (n) {
        int neww = n % 10;
        if (neww > old) return false;
        n = n / 10;
        old = neww;
    }
    return true;
}

int count(int n) {
    int c = 0;
    for (int i = 1; i <= n; i ++) {
        if (isSorted(i)) c++;
    }
    return c;
}
int main() {
    cout << count(100);
}
