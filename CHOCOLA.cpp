// Question: https://practice.geeksforgeeks.org/problems/minimum-cost-to-cut-a-board-into-squares/

// Minimum Cost to break a board into squares

// Approach: Make the most expensive cuts first
// Then the cut in other direction will be one more than previous value


int minimumCostOfBreaking(vector<int> X, vector<int> Y, int M, int N){
  //Write your code here
  M--; N--;
  sort(begin(X), end(X), greater<int>());
  sort(begin(Y), end(Y), greater<int>());
  int ans = 0, xcost = 1, ycost = 1;
  int x = 0, y = 0;
  while (x < M && y < N) {
      if (X[x] > Y[y]) {
          ans += (X[x] * xcost);
          x++;
          ycost++;
      }
      else {
          ans += (Y[y] * ycost);
          y ++;
          xcost++;
      }
  }
  while (x < M) {
      ans += (X[x] * xcost);
      x++;
  }
  while (y < N) {
      ans += (Y[y] * ycost);
      y ++;
  }
  return ans;
}
