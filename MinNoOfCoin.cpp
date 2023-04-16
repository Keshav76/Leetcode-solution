// Question: https://practice.geeksforgeeks.org/problems/-minimum-number-of-coins4426

// Minimum number of coins

// Approach: Assign largest coins first (greedy)

vector<int> minPartition(int N)
{
  // code here
  vector<int> notes = { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 };
  vector<int> ans;
  int i = notes.size() - 1;
  while (N) {
      if (N >= notes[i]){
          N -= notes[i];
          ans.push_back(notes[i]);
      }
      else {
          i --;
      }
  }
  return ans;
}
