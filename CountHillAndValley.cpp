//Problem: https://leetcode.com/problems/count-hills-and-valleys-in-an-array/description/

//Count Hill and Valley in an Array

//Approach: Maintain left height and traverse the whole array

class Solution {
public:
    int countHillValley(vector<int>& arr) {
        int n = arr.size(), left = arr[0], ans = 0;
        for (int i = 1; i < n-1; i ++) { 
            if (arr[i] > left && arr[i] > arr[i+1]) ans ++; //hill
            if (arr[i] < left && arr[i] < arr[i+1]) ans ++; //valley
            if (arr[i+1] != arr[i]) left = arr[i];
        }
        return ans;
    }
};
