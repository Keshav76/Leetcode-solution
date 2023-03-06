// Question: https://practice.geeksforgeeks.org/problems/largest-number-formed-from-an-array1117

// Largest Number formed from an array

// Approach: Sort with new compare function

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
// 	static bool compare(string s1, string s2) {
// 	    return help(s1, s2, 0);
// 	}
	static bool help(string a, string b) {
	    string ab = a.append(b), ba = b.append(a);
	    return ab > ba;
	}
	// The main function that returns the arrangement with the largest value as
	// string.
	// The function accepts a vector of strings
	string printLargest(vector<string> &arr) {
	    
	    // code here
	    sort(begin(arr), end(arr), help);
	   // for (string ele: arr) cout << ele << " ";
	   
	   string ans = "";
	   for (auto ele: arr) {
	       ans.append(ele);
	   }
	   
	   return ans;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<string> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.printLargest(arr);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
