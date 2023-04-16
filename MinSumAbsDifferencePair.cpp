// Question: https://practice.geeksforgeeks.org/problems/minimum-sum-of-absolute-differences-of-pairs/

// Minimum Sum of Absolute Differences of Pairs

// Approach: Sort


long long findMinSum(vector<int> &A,vector<int> &B,int N){
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    long long ans = 0;
    for (int i = 0; i < N; i ++) {
        ans += abs(A[i] - B[i]);
    }
    return ans;
}
