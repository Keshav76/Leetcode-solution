// Question: https://leetcode.com/problems/next-permutation/

// next Permutation

// Intuition: any permutation has a decreasing order at the end of array

// Algo:

// First: Find the right most element which arr[i] < arr[i+1]  name this index id1    //start of non sorted part from right

// Edge case: if id1 is not found { reverse the array and return }

// Second: Find the rightmost element which is greater than arr[id1]   name this index id2
// Swap arr[id1] and arr[id2]
// Reverse array from id1 + 1 to last

class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        int n = arr.size(), ind1 = -1, ind2 = -1;
        for (int i = n - 2; i >= 0; i --)
            if (arr[i] < arr[i+1]) {
                ind1 = i;
                break;
            }
        if (ind1 == -1) {
            reverse(arr.begin(), arr.end());
            return;
        }
        for (int i = n - 1; i >= ind1; i --)
            if (arr[i] > arr[ind1]) {
                ind2 = i; 
                break;
            }
        
        swap(arr[ind1], arr[ind2]);
        reverse(arr.begin() + ind1 + 1, arr.end());
    }
};
