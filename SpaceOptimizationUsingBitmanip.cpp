// Question: https://www.geeksforgeeks.org/space-optimization-using-bit-manipulations/

// Space optimization using Bit Manipulation

// Approach: Use bits to store 0 or 1 instead of bool (1byte)

#include<bits/stdc++.h>
using namespace std;

vector<int> mul25(int a, int b) {
    vector<int> ans((b-a+1)/32+1);
    for (int i = a; i <= b; i ++) {
        if(i % 2 == 0 || i % 5 == 0) {
            //set bit
            ans[(i-a)/32] = ans[(i-a)/32] | (1 << (31 - (i-a) % 32));
        }
    }
    return ans;
}
int bitVal(int a, int ind) {
    return (a & (1 << ind)) != 0;
}
int main() {
    auto ans = mul25(2,21);
    for (int i = 0; i <= 19; i ++) {
        cout << bitVal(ans[i / 32], (31 - i % 32)) << " ";
    }
}
