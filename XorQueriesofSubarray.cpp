// Question: https://leetcode.com/problems/xor-queries-of-a-subarray/

// XOR QUeries of subarray

// Approach: 
// 1. O(N*Q) Brute Force
// 2. Prefix Xor array O(Q + N) soln
// 3. Mo's Algorithm

// For Mo's Algo to work => 
      // Array non mutable
      // Offline Queries (all available at a time)
      // Queries of the type [left, right]
      // To apply an operation on subarray left to right

// Divide left index in blocks of size sqrt(N)
// Sort queries in a specific order
// First in ascending order of Blocks
// Then in descending order of right index

class Query {
    public:
    Query(int l, int r, int i) {
        this->l = l;
        this->r = r;
        this->i = i;
    }
    int l, r, i;
};

const int BLK = 100;

bool comp(Query a, Query b) {
    if (a.l / BLK != b.l / BLK) 
        return (a.l / BLK) <= (b.l / BLK);
    return a.r <= b.r;
}

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
       int q = queries.size();
        vector<Query> qs;
        for (int i = 0; i < q; i ++) {
            auto ele = queries[i];
            Query query(ele[0], ele[1], i);
            qs.push_back(query);
        }
        sort(begin(qs), end(qs), comp);

        vector<int> ans;
        // solving first case
        int x = 0, prevL = qs[0].l, prevR = qs[0].r;
        for (int i = prevL; i <= prevR; i ++) {
            x ^= arr[i];
        }
        ans[qs[0].i] = x;

        for (int m = 1; m < qs.size(); m ++) {
            auto query = qs[m];
            while (query.l < prevL) {
                // Add elements on left
                prevL --;
                x ^= arr[prevL];
            }
            while (query.l > prevL) {
                // Remove elements on left
                prevL ++;
                x ^= arr[prevL];
            }
            while (query.r < prevR) {
                // Remove elements from right
                prevR --;
                x ^= arr[prevR];
            }
            while (query.r > prevR) {
                // Add elements on right
                prevR ++;
                x ^= arr[prevR];
            }
            ans[query.i] = x;
            // prevL = query.l;
            // prevR = query.r;
        }
        return ans;
    }
};
