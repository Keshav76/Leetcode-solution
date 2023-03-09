// Question: https://practice.geeksforgeeks.org/problems/consecutive-elements2306/1

// Remove Consecutive Elements

// Approach: Nothing

//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
class Solution{
    public:
    string removeConsecutiveCharacter(string S)
    {
        // code here.
        string ans = "";
        for (int i = 0; i < S.size(); i ++) {
            ans += S[i];
            while (i < S.size() && S[i] == S[i+1]) i ++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.removeConsecutiveCharacter(s)<<endl;
    }
} 




// } Driver Code Ends
