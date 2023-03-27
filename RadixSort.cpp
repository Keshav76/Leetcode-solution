// Question: https://practice.geeksforgeeks.org/problems/radix-sort

// Radix Sort

// Approach: Sort based on digits starting from last digit
// Sort on every digit from ones place to largest
// Keep a map for storing all elements of every particular digit [0-9]
// Maintain the order of elements

void radixSort(int arr[], int n) { 
    // creating map
    map<int, vector<int>> mp;
    int mx = -9999, div = 10;
    for (int i = 0; i < n; i ++) {
        mx = max(mx, arr[i]);
    }
    while (mx) {
        
        for (int i = 0; i < n; i ++) {
            int temp = arr[i];
            int idx = temp % div;
            idx = idx * 10 / div;
            if (mp.count(idx))
                mp[idx].push_back(arr[i]);
            else
                mp[idx] = {arr[i]};
        }
        int k = 0;
        for (int i = 0; i < 10; i ++) {
            if (mp.count(i)) {
                for (auto ele: mp[i]){
                    arr[k++] = ele;
                }
            }
        }
        mp.clear();
        div *= 10;
        mx /= 10;
    }
    
}
