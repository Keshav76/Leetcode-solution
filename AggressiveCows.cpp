// Question: https://practice.geeksforgeeks.org/problems/aggressive-cows/1

// Aggressive Cows

// Approach: Search in the entire search space 0 - 10^9
// Use binary search
// for match condition : Check wether we can put k cows in arr with that distance b/w each of them

bool check(vector<int> arr, int cow, int dist, int n) {
        
        for (int i = 0; i < n;) {
            // place one cow at arr[i];
            cow --;
            int curr = arr[i];
            i++;
            while (i < n && arr[i] - curr < dist) i ++;
        }
        return cow <= 0;
    }

    int solve(int n, int k, vector<int> &arr) {
    
        // Write your code here
        sort (begin(arr), end(arr));
        int l = 0, r = 1e9, ans = 0;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (check(arr, k, mid, n)) {
                l = mid + 1;
                ans = mid;
            }
            else {
                r = mid - 1;
            }
        }
        return ans;
    }
