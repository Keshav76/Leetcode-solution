// Question: https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620

// Merge without extra space 

// Approach: Try to get all smaller elements to first array
// then sort both array

// for moving smaller elements to first array: 
// Have two pointers one for last ele of arr1 and one for first index of arr2
// swap if upper arr has higher value
// i--, j++

void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            int i = n - 1, j = 0;
            while (i >= 0 && j < m) {
                if (arr1[i] > arr2[j]) {
                    swap(arr1[i], arr2[j]);
                }
                i --;
                j ++;
            }
            sort(arr1, arr1+n);
            sort(arr2, arr2+m);
        } 
