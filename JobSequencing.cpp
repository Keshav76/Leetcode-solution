// Question: https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1

// Job Sequencing

// Approach: Sort in descending order of profit
// Assign each job at the highest time possible under deadline
// If you can assign the job, increment count and update total profit

static bool cmp(Job a, Job b) {
  return a.profit > b.profit;
}
vector<int> JobScheduling(Job arr[], int n) 
{ 
  // your code here
  sort(arr, arr + n, cmp);
  int count = 0, profit = 0, maxDead = INT_MIN;
  for (int i = 0; i < n; i ++) 
      maxDead = max(maxDead, arr[i].dead); 
  vector<int> deadline(maxDead + 1, -1);
  for (int i = 0; i < n; i ++) {
      auto ele = arr[i];
      for (int k = ele.dead; k > 0; k --) {
          if (deadline[k] == -1) {
              deadline[k] = ele.id;
              profit += ele.profit;
              count ++;
              break;
          }
      }
  }
  return {count, profit};
}




// Approach 2: Use disjoint set instead of array for storing deadlines

class DisjointSet {
    public: 
    vector<int> parent;
    DisjointSet(int n) {
        parent = vector<int>(n);
        for (int i = 0; i < n; i ++) parent[i] = i;
    }
    int findParent(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findParent(parent[node]);
    }
    void unionSet(int u, int v) {
        parent[u] = v;
    }
};

class Solution {
    public:
    static bool cmp(Job a, Job b) {
        return a.profit > b.profit;
    }
    vector<int> JobScheduling(Job arr[], int n) {
        sort (arr, arr + n, cmp);
        int maxDead = 0;
        for (int i = 0; i < n; i ++) {
            maxDead = max(maxDead, arr[i].dead);
        }
        int ans = 0, count = 0;
        DisjointSet djs(maxDead + 1);
        for (int i = 0; i < n; i ++) {
            Job ele = arr[i];
            int d = djs.findParent(ele.dead);
            if (d != 0) {
                djs.unionSet(d, d-1);
                ans += ele.profit;
                count ++;
            }
        }
        return {count, ans};
    } 
};
