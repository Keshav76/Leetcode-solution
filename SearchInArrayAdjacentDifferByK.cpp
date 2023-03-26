// https://practice.geeksforgeeks.org/problems/searching-in-an-array-where-adjacent-differ-by-at-most-k0456

// Searching in an array where adjacent differ by at most k

// Approach: Linear Search with changed increment value


int search(int arr[], int n, int x, int k)
{
    // Complete the function	
    // return help(arr, n, x, k, 0);
    for (int i = 0; i < n; i += max(1, (arr[i]-x) / k)) 
        if (arr[i] == x) 
            return i;
    return -1;
}    	
