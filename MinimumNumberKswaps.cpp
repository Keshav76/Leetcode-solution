// Question: https://leetcode.com/problems/minimum-possible-integer-after-at-most-k-adjacent-swaps-on-digits/description/

// Minimum Possible Integer After at Most K Adjacent Swaps On Digits

// Approach: Apply insertion sort with limit to k swaps
// Find min value in range k
// And bring it to 1st pos
// Repeat for second and further

class Solution {
public:
  string minInteger(string num, int k) {
      int n = num.length();
      int i = 0;
      while (i < n && k > 0) {
          int mnIdx = i;
          char mnVal = num[i];
          for (int j = i; j <= i + k && j < n; j ++) {
              if (mnVal > num[j]) {
                  mnIdx = j;
                  mnVal = num[j];
              }
          }
          for (int j = mnIdx; j > i; j --) {
              swap(num[j], num[j-1]);
              k --;
          }
          i ++;
      }
      return num;
  }
};
