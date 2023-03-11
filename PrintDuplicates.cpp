// Question: https://www.geeksforgeeks.org/print-all-the-duplicates-in-the-input-string/

// Print all the duplicates in the input string

// Approach: Map but with bit manipulation

#include <iostream>
using namespace std;

string duplicate(string s) {
    int map=0;       //32 bit: more than enough for 26 letters
    int added = 0;
    string ans = "";
    for (auto ele: s) {
        int loc = ele-'a';
        if ((map & (1 << loc)) != 0) {
            if ((added & (1 << loc)) == 0)
                ans += ele;
            added = added | (1 << loc);
        }
        map = map | (1 << loc);
    }
    return ans;
}

int main()
{
    string s = "geeksforgeeks";
    cout << duplicate(s);
    return 0;
}
