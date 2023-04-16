// Question: https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1

// Fractional Knapsack

// Approach : (Greedy) => Sort on value/weight

static bool cmp(Item a, Item b) {
  return double(a.value) / a.weight > double(b.value) / b.weight;
}
//Function to get the maximum total value in the knapsack.
double fractionalKnapsack(int W, Item arr[], int n)
{
  // Your code here
  sort(arr, arr + n, cmp);
  double ans = 0;
  for (int i = 0; i < n; i ++) {
      auto item = arr[i];
      if (W >= item.weight) {
          W -= item.weight;
          ans += item.value;
      }
      else {
          ans += item.value * (W / float(item.weight));
          break;
      }
  }
  return ans;
}
