// Question: https://practice.geeksforgeeks.org/problems/counting-sort

// Counting Sort

// Approach: Count occurence of each element
// Fill array accordingly

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
#define RANGE 255


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    //Function to arrange all letters of a string in lexicographical 
    //order using Counting Sort.
    string countSort(string arr){
        // code here
        vector<int> count (26,0);
        for (auto ele: arr) count[ele-'a']++;
        int k = 0;
        for (int i = 0; i < 26; i ++) {
            for (int j = 0; j < count[i]; j ++) {
                arr[k++] = 'a' + i;
            }
        }
        return arr;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string arr;
        cin>>arr;
        Solution obj;
        cout<<obj.countSort(arr)<<endl;
    }
    return 0;
}

// } Driver Code Ends
