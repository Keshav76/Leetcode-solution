// Question: https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1

// K-th Smallest Element

// Approach: Min heap

int kthSmallest(int arr[], int l, int r, int k) {
        //code here
        priority_queue<int> pq;
        for (int i = l; i <= r; i ++) {
            pq.push(-arr[i]);
        }
        for (int i = 1; i < k; i ++) pq.pop();
        return -pq.top();
    }
