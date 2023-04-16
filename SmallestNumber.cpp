// QUestion: https://practice.geeksforgeeks.org/problems/smallest-number5829/

// Smallest Number

// Approach: Decrease sum by 1 so that we can make a D digit number "putting 1 at start => 100009"
// Start from right or lsb and put everything as 9
// If sum goes over required put the remaining on that position and break out of loop
// Put 1 at the begining 
// If whole D digits are already filled => Increment the MSB

string smallestNumber(int S, int D){
  // code here
  if (S > D * 9) return "-1";
  vector<int> ans(D, 0);
  S --;
  int i;
  for (i = 0; i < D; i ++) {
      if (S > 9) {
          ans[i] = 9;
          S -= 9;
      }
      else {
          ans[i] = S;
          break;
      }
  }
  if (i == D - 1){
      ans[i] ++;
  }
  else {
      ans[D-1] = 1;
  }
  string num = "";
  for (int i = D - 1; i >= 0; i --) {
      num += ('0' + ans[i]);
  }
  return num;
}
