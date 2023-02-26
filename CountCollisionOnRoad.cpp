//Question: https://leetcode.com/problems/count-collisions-on-a-road/

// Count Collisions on Road
// Approach: 

//Maintain a left condition variable that denotes state of road on left side;
// 0 means their is no one on left
// 1 means their is a stationory object on left
// 2 means their is 1 car coming from left
// more than 2 means their are (n-1) cars coming from left


//Made conditions for diffrent state of left and different state of current 

class Solution {
public:
    int countCollisions(string str) {
        int left = 0; // 0 for no one , 1 for stationary object, 2 for car coming
        int n = str.length(), ans = 0;
        for (int i = 0; i < n; i ++) {
            if (str[i] == 'S') {
                if (left >= 2) ans += (left-1);
                left = 1;
            }
            else if (str[i] == 'L') {
                if (left == 1) {ans += 1; left = 1;}
                if (left >= 2) {ans += (left); left = 1;}
            }
            else {
                if (left >= 2) left++;
                else left = 2;
            }
        }
        return ans;
    }
};
