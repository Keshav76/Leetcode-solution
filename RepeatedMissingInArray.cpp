// Question: https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/

// Find Missing and Repeating 

// Approach: let x = missing num, y = repeated num
//Find sum of all the elements => sum_arr, sum of all the nums from 1 to n => sum_n
//Same for squared sum


// Solve equations for getting the result

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        long long sum_n=0, sum_arr=0, ssa=0, ssn = 0;
        for (int i = 0; i < n; i ++) {
            sum_n += (i+1);
            ssn += (i+1)*(i+1);
            sum_arr += arr[i];
            ssa += arr[i] * arr[i];
        }
        long long diff = sum_n - sum_arr;
        long long plus = (ssn - ssa) / diff;
        int *ans = new int[2]; 
        ans[0] = (plus - diff)/2; 
        ans[1] = (plus + diff)/2;
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends
