// Question: https://practice.geeksforgeeks.org/problems/quick-sort/

// Quick Sort

// Partition + Pivot

//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// } Driver Code Ends
class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        if (low >= high) return;
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
        return;
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
        int temp = arr[high];
        int pi = low;
        for (int i = low; i <= high; i ++) {
            if (arr[i] < temp) {
                swap(arr[i], arr[pi]);
                pi ++;
            }
        }
        swap(arr[pi], arr[high]);
        return pi;
    }
};


//{ Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      Solution ob;
    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends
