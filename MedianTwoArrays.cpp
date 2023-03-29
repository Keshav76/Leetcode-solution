// Question: https://leetcode.com/problems/median-of-two-sorted-arrays

// Median of two sorted array

// Approach: Have the smaller array as the first one
// Apply binary search over first array,
// find an index(mid) for arr1 and find an index for arr2 such that two partitions sum up to half of the total array (n1+n2)
// find Aleft , Aright, Bleft, Bright

// check if partion is at correct place -> aleft <= Bright and bleft <= aright 
// then solve for median

// else update l, r of binary search accordingly

class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        int n1 = A.size(), n2 = B.size();
        if (n1 > n2) {
            return findMedianSortedArrays(B, A);
        }
        // Now A is shorter

        int l = 0, r = n1 - 1;
        int full = (n1 + n2);
        int half = (n1 + n2) / 2;
        while (true) {
            int i = l + (r - l) / 2;
            if(r == -1) i = -1;
            int j = half - i - 2;
            int Aleft, Aright, Bleft, Bright;

            if (i >= 0) Aleft = A[i]; else Aleft = INT_MIN;
            if (i+1 < n1) Aright = A[i+1]; else Aright = INT_MAX;

            if (j >= 0) Bleft = B[j]; else Bleft = INT_MIN;
            if (j+1 < n2) Bright = B[j+1]; else Bright = INT_MAX;

            if (Aleft <= Bright && Bleft <= Aright) {
                // found the partition
                if (full % 2) {   // odd
                    return min(Aright, Bright);
                } 
                else {
                    return float(max(Aleft, Bleft) + min(Aright, Bright)) / 2;
                }
            }
            else if (Bleft > Aright){
                l = i + 1;
            }
            else /*if (Aleft > Bright)*/ {
                r = i - 1;
            }
        }
        return 0;
    }
};
