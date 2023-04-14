// Question: https://practice.geeksforgeeks.org/problems/maximum-of-minimum-for-every-window-size3453/



// Maximum of minimum for every window size



// Approach: Use concept of next smaller and prev smaller to find range in which that lement is smallest
// That element is candidate for soln of that window size and all the smaller window sizes

// Calculate window size for all elements
// Put the elements in ans array according to their window size 
// (for eg. element 25 with maxWindowSize 3 will be placed in ans[3]         //1 based indexing for example
// Also we need to put only maximum of all elements in ans
// for eg. 25 and 35 both have maxWindowSize 3 => ans[3] will have 35

// For entire ans array => find max of (arr[i], arr[i+1]) from back
// This is for the condition that says element with maxWindowSize 3 can be in 3 as well as 2 and 1 also



vector <int> maxOfMin(int arr[], int n)
{
  // Your code here
  vector<int> width(n, -1);
  vector<int> ans(n, -1);
  stack<int> st;
  for (int i = 0; i < n; i ++) {
      while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
      if (!st.empty()) width[i] = st.top();
      else width[i] = -1;
      st.push(i);
  }
  while (!st.empty()) st.pop();
  for (int i = n - 1; i >= 0; i --) {
      while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
      if (st.empty()) width[i] = n - width[i] - 1;
      else width[i] = st.top() - width[i] - 1;
      st.push(i);
      ans[width[i]-1] = max(ans[width[i]-1], arr[i]);
  }
  for (int i = n-2; i >= 0; i --) {
      ans[i] = max(ans[i], ans[i+1]);
  }
  return ans;
}
