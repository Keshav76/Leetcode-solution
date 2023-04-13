// Question: https://www.codingninjas.com/codestudio/problems/n-stacks-in-an-array_1164271?leftPanelTab=1

// N Stacks in an array

// Approach: Store 4 things
// 1-> Actual array (arr)
// 2-> Top Pointers (top) => to save curr top of all stacks
// 3-> First Empty (firstFree) => to store first index that is free at the moment
// 4-> Next Pointers (next) => stores two things
//     a. If arr holds something in ith position than next[i] = location of next element that should be popped from that stack
//     b. If not then it holds location of next free space availble


class NStack
{

private: 
    vector<int> arr;
    vector<int> top;
    vector<int> next;
    int firstFree;
public:
    // Initialize your data structure.

    NStack(int N, int S)
    {
        // Write your code here.
        arr = vector<int>(S, -1);
        top = vector<int>(N, -1);
        next = vector<int>(S);
        for (int i = 0; i < S; i ++) {
            next[i] = i + 1;
        }
        next[S-1] = -1;
        firstFree = 0;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        // Write your code here.
        if (firstFree == -1) return false;
        int index = firstFree;
        firstFree = next[index];
        next[index] = top[m-1];
        top[m-1] = index;
        arr[index] = x;
        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        if (top[m-1] == -1) return -1;
        // Write your code here.
        int index = top[m-1];
        top[m-1] = next[index];
        next[index] = firstFree;
        firstFree = index;
        return arr[index];
    }
};
