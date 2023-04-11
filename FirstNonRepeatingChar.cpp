// Question: https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1

// First Non-Repeating Character

// Approach: Keep a record of all elements that have not repeated and their first occurence location
// For every element, check the element with least first occurence location
// if an element is repeated: set its occurence to some value that shows => It is already repeated


string FirstNonRepeating(string A){
    // Code here
    vector<int> count(26, INT_MAX);
    string ans = "";
    for (int i = 0; i < A.length(); i ++) {
        int idx = A[i] - 'a';
        if (count[idx] != INT_MAX)
            count[idx] = -1;
        else
            count[idx] = i;
      //  char ele = '#';
        int mn = INT_MAX, loc = -1;
        for (int j = 0; j < 26; j ++) {
            if (count[j] != -1 && mn > count[j]) { 
              //  ele = 'a' + j;
                mn = count[j];
                loc = j;
            }
        }
        if (loc == -1) ans += '#';
        else ans += 'a' + loc;
    }
    return ans;
}
