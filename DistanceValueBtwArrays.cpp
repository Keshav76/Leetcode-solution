// Question: https://leetcode.com/problems/find-the-distance-value-between-two-arrays/

// Find the Distance Value Between Two Arrays

//Approach: 
// Sort 2nd array
// Search for inserting position for (each element of arr1) in arr2
// Check if its left and right is in unwanted range
// Maintain ans accordingly


class Solution {
    int searchInsert(vector<int>& arr, int target) {
        int l = 0, r = arr.size() - 1; 
        int ans = -1;
        while (l <= r) {
            int mid = l + (r-l) / 2;
            if (arr[mid] < target) {
                ans = mid; 
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return ans + 1;
    }
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort (arr2.begin(), arr2.end());
        int ans = 0;
        arr2.push_back(INT_MAX);
        arr2.insert(arr2.begin(), INT_MIN);
        for (auto ele : arr1) {
            int index = searchInsert(arr2, ele);
            // cout << index << "->";
            if ((arr2[index] - long(ele) > d )&& long(ele) - arr2[index-1] > d) ans ++;
        }
        return ans;
    }
};
