// Question : https://practice.geeksforgeeks.org/problems/swap-and-maximize5859

// Swap and Maximize

// Approach: Rearrange the array in a way that gives most return
// Use smallest element and next the largest element => this will give largest result

long long int maxSum(int arr[], int n)
{
  sort(arr, arr+n); 
  int i = 0, j = n - 1;
  long long ans = 0;
  while (i < j) {
      ans += arr[j] - arr[i];
      // ans += arr[j] - arr[i+1];
      i += 1;
      j -= 1;
  }
  i = 1, j = n - 1;
  while (i < j) {
      ans += arr[j] - arr[i];
      i += 1;
      j -= 1;
  }
  ans += arr[j] - arr[0];
  return ans;
}
