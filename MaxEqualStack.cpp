// Question: https://practice.geeksforgeeks.org/problems/find-maximum-equal-sum-of-three-stacks/

// Maximum Equal Sum of three stacks

// Approach: Pop from stack which has higher sum

int maxEqualSum(int n1,int n2,int n3,vector<int> A,vector<int> B,vector<int> C){
    int i = 0, j = 0, k = 0, s1 = 0, s2 = 0, s3 =0;
    for (auto ele : A) s1 += ele;
    for (auto ele : B) s2 += ele;
    for (auto ele : C) s3 += ele;
    while (true) {
        if (s1 == s2 && s2 == s3) {
            return s1;
        }
        else if (s1 > s2 || s1 > s3) {
            s1 -= A[i];
            i ++;
            if (i == n1) return 0;
        }
        else if (s2 > s3 || s2 > s1) {
            s2 -= B[j];
            j ++;
            if (j == n2) return 0;
        }
        else if (s3 > s1 || s3 > s2) {
            s3 -= C[k];
            k ++;
            if (k == n3) return 0;
        }
    }
    return 0;
}
