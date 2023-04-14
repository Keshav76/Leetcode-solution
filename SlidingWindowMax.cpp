// Question: https://leetcode.com/problems/sliding-window-maximum/

// Sliding Window Maximum

// Approach: Use Monotonic Decreasing Queue
// Have a deque that holds elements of curr window only and in decreasing order
// If a new element is bigger remove the smaller elements from dq => as they cant be greatest even in future
// If a left most element goes out of bound => remove it  i.e (left most element is out of window now)

// Ans is left most value from dq for every iteration

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int l = 0, n = nums.size();
        deque<int> dq;
        vector<int> ans;
        for (int r = 0; r < n; r ++) {

            while (!dq.empty() && nums[dq.front()] < nums[r]) dq.pop_front();
            if (!dq.empty() && dq.back() < l) dq.pop_back();
            dq.push_front(r);
            if (r >= k-1) {
                ans.push_back(nums[dq.back()]);
                l ++;
            }
        }
        return ans;
    }
};
