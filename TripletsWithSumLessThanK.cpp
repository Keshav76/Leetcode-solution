// Question: https://practice.geeksforgeeks.org/problems/count-triplets-with-sum-smaller-than-x5549/

// Count triplets with sum smaller than X

// Approach: Sort then loop for i then two pointers of j and k
// Similar to 3 sum

// One extra case: consider all numbers in b/w j and k when a triplet is found
// As decreasing k will only reduce the sum

long long countTriplets(long long arr[], int n, long long sum)
	{
	    int count = 0;
	    sort(arr, arr+n);
	    // Your code goes here
	    for (int i = 0; i < n; i ++) {
	        int j = i + 1, k = n - 1;
	        while (j < k) {
	            int curr = arr[i] + arr[j] + arr[k];
	            if (curr < sum) {
	                count += (k-j);
	                j ++;
	               // k --;
	            }
	            else
	                k --;
	        }
	    }
	    return count;
	}
