// Question: https://www.geeksforgeeks.org/convert-sentence-equivalent-mobile-numeric-keypad-sequence/

//Convert a sentence into its equivalent mobile numeric keypad sequence


#include<bits/stdc++.h>
using namespace std;

string convertToMobileNumber(string s) {
    string ans = "";
    string nums[] = { "2",   "22",  "222", "3", "33", "333", "4", "44",  "444", "5",   "55",  "555",  "6",   "66", "666", "7",   "77",  "777", "7777", "8", "88", "888", "9",   "99",  "999", "9999" };
    for (auto ele: s) {
        if (isupper(ele))
        ans += nums[ele-'A'];
    }
    return ans;
}

int main() {
    cout << convertToMobileNumber("HELLO WORLD");
}
