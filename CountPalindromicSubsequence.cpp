// Question: https://practice.geeksforgeeks.org/problems/count-palindromic-subsequences/1

// Count Palindromic Subsequence

//{ Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    long long int  countPS(string str) {
       int N = str.size();
       long MOD = 1000000007;
       long long int dp[N][N] = {-1};
       for (int i = N - 1; i >= 0; i --) {
           for (int j = 0; j < N; j ++) {
               if (i > j) dp[i][j] = 0;
               else if (i == j) dp[i][j] = 1;
               else if (str[i] == str[j]) dp[i][j] = (dp[i+1][j] + dp[i][j-1] + 1 + MOD)%MOD;
               else dp[i][j] = ((dp[i+1][j] + dp[i][j-1])%MOD - dp[i+1][j-1] + MOD)%MOD;
           }
       }
       return dp[0][N-1];
    }
     
};

//{ Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}
// } Driver Code Ends
