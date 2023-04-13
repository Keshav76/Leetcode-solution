// Question: https://leetcode.com/problems/gas-station/description/

// Gas Station (Circular Path)

// Approach: Kadane's Algorithm
// Use kadane's algorithm on gas-cost array
// first index of the soln is only candidate for first petrol pump

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // Applying sort of kadane's algorithm
        int n = gas.size(), curr = 0, mx = INT_MIN, currIdx = 0, mxIdx = 0;
        for (int i = 0; i < 2 * n; i ++) {
            int idx = i % n;
            int ele = gas[idx] - cost[idx];
            curr += ele;
            if (curr < 0) {
                curr = 0;
                currIdx = (idx + 1) % n;
            }
            if (curr > mx) {
                mx = curr;
                mxIdx = currIdx;
            }
        }
        int petrol = 0;
        for (int i = 0; i < n; i ++) {
            int idx = (currIdx + i) % n;
            petrol += gas[idx];
            if (petrol < cost[idx]) return -1;
            petrol -= cost[idx];
        }
        return mxIdx;
    }
};
