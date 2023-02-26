// Question: https://leetcode.com/problems/squares-of-a-sorted-array

// Squares of Sorted Arrray

// Approach: Two Pointers
// Maintain two pointers indicating biggest negative number and smallest positive number
// These numbers will be giving smallest squares
// Check between these two and add to ans 

class Solution {
public:
    vector<int> sortedSquares(vector<int>& arr) {
        int neg = INT_MIN, pos = INT_MAX, n = arr.size();
        for (int i = 0; i < n; i ++) {
            if (arr[i] < 0) neg = i;
            else {
                pos = i;
                break;
            }
        }
        vector<int> ans;
        while (neg >= 0 && pos < n) {
            int neg2 = arr[neg] * arr[neg], pos2 = arr[pos] * arr[pos];
            if (neg2 > pos2) {
                ans.push_back(pos2);
                pos ++;
            }
            else {
                ans.push_back(neg2);
                neg--;
            }
        }
        while (neg >= 0){ 
            ans.push_back(arr[neg]*arr[neg]); 
            neg--;
        }
        while (pos < n) {
            ans.push_back(arr[pos]*arr[pos]);
            pos++; 
        }
        return ans;
    }
};
