// Question: https://practice.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621

// Smallest window in a string containing all the characters of another string

// Approach: Sliding Window Protocol
// Make a map for storing count of characters and a counter for checking how many are already satisfied

class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        // Your code here
        unordered_map<char, int> need, have;
        int currFound = 0, req = 0;
        for (auto chr: p) {
            need[chr] ++;
            if (need[chr] == 1) req ++;
        }
        int i = 0, currAnsLength = INT_MAX, ans = 0;
        for (int j = 0; j < s.length(); j ++) {
            // add jth element to window
            char chr = s[j];
            have[chr] ++;
            if (have[chr] == need[chr]) currFound ++;
            while (currFound == req) {
                // remove ith element
                char rem = s[i];
                if (j - i + 1 < currAnsLength) {
                    currAnsLength = j - i + 1;
                    ans = i;
                }
                if (have[rem] == need[rem]) currFound--;
                have[rem] --;
                i++;
            }
        }
        if (currAnsLength == INT_MAX) return "-1";
        return s.substr(ans, currAnsLength);
    }
};
