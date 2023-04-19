// Question: https://www.geeksforgeeks.org/minimum-swap-required-convert-binary-tree-binary-search-tree/

// Minimum swap required to convert binary tree to binary search tree

// Approach: Inorder of a BST is always sorted array
// So we will find inorder of current tree
// And check how many moves required for changing array to sorted one

// For counting swaps => make a vector of pairs with ele and index
// sort the pair array
// Pick the correct element on every index by swapping it with the correct index of that element

#include <bits/stdc++.h> 
void inorder(vector<int> arr, int n, vector<int> &ans, int i = 0) {
	if (i >= n) return;
	inorder(arr, n, ans, 2*i+1);
	ans.push_back(arr[i]);
	inorder(arr, n, ans, 2*i+2);
}
int minimumSwaps(vector<int>&arr, int n) {
	// Finding Inorder of given tree
	vector<int> in; 
	inorder(arr, n, in);
	// Finding no of swaps required to sort it
	vector<pair<int,int>> v;
	for (int i = 0; i < n; i ++) v.push_back({in[i], i});
	sort(v.begin(), v.end());
	int count = 0;
	for (int i = 0; i < n; i ++) {
		if (v[i].second == i) continue;
		swap(v[i], v[v[i].second]);
		if (v[i].second != i) i--;
		count ++;
	}
	return count;
}
