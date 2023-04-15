// Question: https://practice.geeksforgeeks.org/problems/interesting-queries4742/

// Interesting Queries

// Approach: Mo's Algorithm
// See details in XOR of subarrays

const int BLK = 100;
class Query {
    public:
    int l, r, i;
    Query(int L, int R, int I) {
        l = L;
        r = R;
        i = I;
    }
};
bool comp(Query a, Query b) {
    if (a.l / BLK != b.l / BLK) 
        return a.l < b.l;
    return a.r > b.r;
}
class Solution {
public:
    void remove(int num, unordered_map<int, int> &mp, int &count, int k) {
        if (mp[num] == k) count --;
        mp[num]--;
    }
    void add(int num, unordered_map<int, int> &mp, int &count, int k) {
        mp[num]++;
        if (mp[num] == k) count ++;
    }
	vector<int>solveQueries(vector<int>arr, vector<vector<int>>Queries, int k){
	    // Code here
	    int q = Queries.size();
	    vector<Query> qs;
	    vector<int> ans(q);
	    for (int i = 0; i < q; i ++) {
	        Query query(Queries[i][0]-1, Queries[i][1]-1, i);
	        qs.push_back(query);
	    } 
	    sort(begin(qs), end(qs), comp);
	   // for (auto ele: qs) cout << ele.l << " " << ele.r << " " << ele.i << endl;
	    int prevL = qs[0].l, prevR = qs[0].r, count = 0;
	    unordered_map<int, int> mp;
	    for (int i = prevL; i <= prevR; i ++) {
	        add(arr[i], mp, count, k);
	    }
	    ans[qs[0].i] = count;
	    for (int x = 1; x < q; x ++) {
	        auto query = qs[x];
	        while (query.l < prevL) {
	            prevL--;
	            add(arr[prevL], mp, count, k);
	        }
	        while (query.l > prevL) {
	            remove(arr[prevL], mp, count, k);
	            prevL++;
	        }
	        while (query.r < prevR) {
	            remove(arr[prevR], mp, count, k);
	            prevR--;
	        }
	        while (query.r > prevR) {
	            prevR++;
	            add(arr[prevR], mp, count, k);
	        }
	        ans[query.i] = count;
	    }
	    return ans;
	}
};
