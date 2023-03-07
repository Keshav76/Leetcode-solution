// https://leetcode.com/problems/powx-n

// Pow X-N

// Approach: Divide and Conquer

class Solution {
public:
    double myPow(double x, long n) {
        if (n < 0)
            return myPow(1 / x, -n);
        if (n == 0)
            return 1;
        if (n == 1)
            return x;
        if (n % 2 == 0)
            return myPow(x * x, n / 2);
        return myPow(x * x, n / 2) * x;
    }
    
    double myPow(double x, int n) {
        return myPow(x, (long) n);
    }
};
