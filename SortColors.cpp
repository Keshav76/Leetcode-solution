// Question: https://leetcode.com/problems/sort-colors/

// Sort Colors

// Transfer all 0's to left, 2's to right

class Solution {
public:
    void sortColors(vector<int>& arr) {
        int low = 0, high = arr.size() - 1;
        for (int i = 0; i <= high; i ++) {
            if (arr[i] == 0) {
                swap(arr[low], arr[i]);
                low ++;
            }
            else if (arr[i] == 2) {
                swap(arr[high], arr[i]);
                i --;
                high --;
            }
        }
        return;
    }
};
