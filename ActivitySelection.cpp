// Question: https://practice.geeksforgeeks.org/problems/activity-selection-1587115620/1

// Activity Selection

// Approach: Use greedy methodology
// Sort on activity end time
// Add activities with higher start time than prev selected end time


static bool comp(pair<int, int> a, pair<int, int> b) {
  return a.second < b.second;
}
int activitySelection(vector<int> start, vector<int> end, int n)
{
  // Your code here
  vector<pair<int, int>> activity;
  for (int i = 0; i < n; i ++) {
      activity.push_back({start[i], end[i]});
  }
  sort(activity.begin(), activity.end(), comp);
  int count = 1, tim = activity[0].second;
  for (int i = 1; i < n; i ++) {
      if (activity[i].first > tim) {
          count ++;
          tim = activity[i].second;
      }
  }
  return count;
}
