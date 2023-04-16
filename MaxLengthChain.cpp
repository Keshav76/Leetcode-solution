// Question: https://practice.geeksforgeeks.org/problems/max-length-chain/

// Max Length Chain

// Approach: Sort on the basis of end time
// 1st element now will 100% be in the chain
// Keep increasing chain (if possible)
// If not possible skip that link and move to next

static bool cmp(val a, val b) {
    return a.second < b.second;
}
int maxChainLen(struct val p[],int n){
    //Your code here
    sort(p, p+n, cmp);
    int curr =  1, mx = 0, last = p[0].second;
    for (int i = 1; i < n; i ++) {
        if (p[i].first > last) { 
            curr++; 
            last = p[i].second;
        }
        mx = max(mx, curr);
    }
    return max(mx, curr);
}
