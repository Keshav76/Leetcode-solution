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
