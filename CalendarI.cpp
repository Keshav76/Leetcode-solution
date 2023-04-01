// Question: https://leetcode.com/problems/my-calendar-i/

// My Calendar I

// Time Series

class MyCalendar {
public:
    vector<pair<int, int>> arr;
    MyCalendar() {
        arr = {};
    }
    bool book(int start, int end) {
        int i = 0;
        while (i < arr.size() && start > arr[i].first) i ++;
        if (i == 0 && arr.size()>0 && end > arr[0].first) return false; 
        if (i > 0 && arr[i-1].second > start) return false;
        if (i != 0 && i < arr.size() && arr[i].first < end) return false;
        arr.insert(arr.begin() + i, {start, end});
        return true;
    }
};
