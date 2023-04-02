// Question: https://www.geeksforgeeks.org/tug-of-war/

// Tug of War

// Approach: Backtracking
// Two Options -> Either choose the element or leave it
// Also maintain the no of chosen elements as it should be half of array

void tow(vector<int> &arr, vector<bool> &curr, vector<bool> &ans, int currSum, int totalSum, int level, int &currAns, int ind) {
    if (level == 0) {
        // todo
        if (abs(totalSum - (currSum * 2)) < currAns) {
            currAns = abs(totalSum - (currSum * 2));
            for (int i = 0; i < arr.size(); i ++) ans[i] = curr[i];
        }
        return;
    }
    if (ind == arr.size()) return;
    
    // Choose ith element
    curr[ind] = true;
    tow(arr, curr, ans, currSum + arr[ind], totalSum, level - 1, currAns, ind+1);
    curr[ind] = false;
    // Leave ith element
    tow(arr, curr, ans, currSum, totalSum, level, currAns, ind+1);
}

vector<bool> tugOfWar(vector<int> arr) {
    int n = arr.size(), sum = 0, a = INT_MAX;
    for (int ele: arr) sum += ele;
    vector<bool> ans(n,false), curr(n, false);
    tow(arr, curr, ans, 0, sum, n/2, a, 0);
    return ans;
}
