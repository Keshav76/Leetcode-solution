// Question: 

// Longest Prefix Suffix

// Approach: use Dynamic Programming
// if lps of string of length n is 5 then for string of length n + 1 => We need to compare n + 1 th index and 5th index
// If they are equal then increment the last value and put it in lcs[n+1]
// If not check if previous element is matching 
// If we cant go any back further mark it 0

class Solution{
  public:		
	int lps(string s) {
	    // Your code goes here
	    int n = s.length();
	    vector<int> ans(n, 0);
	    int i = 1, prev = 0;
	    while (i < n) {
	        if (s[i] == s[prev]) {
	            prev ++;
	            ans[i] = prev;
	        }
	        else if (prev == 0) {
	            ans[i] = 0;
	        }
	        else {
	            prev = ans[prev-1];
	            i --;
	        }
	        i ++;
	    }
	    return ans[n-1];
	}
};
