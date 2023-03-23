// Question: https://leetcode.com/problems/rotate-image/submissions

// Rotate Image

// Approach: 4 way swap b/w required elements
// Also keep a top and bottom variable to access change points easily

class Solution {
public:
    void fourWaySwap(int &a, int &b, int &c, int &d) {
        int t = d;
        d = c;
        c = b; 
        b = a;
        a = t;
    }
    void rotate(vector<vector<int>>& arr) {
        int s = 0, e = arr.size()-1;  
        while (s <= e) {
            for (int i = s; i < e; i ++) {
                fourWaySwap(arr[s][i], arr[i][e], arr[e][e+s-i], arr[e+s-i][s]);
            }
            s++;
            e--;
        }
        return;
    }
};
