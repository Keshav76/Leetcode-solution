// Question: https://www.geeksforgeeks.org/implement-stack-queue-using-deque/

// stack using deque

class Stack {
    deque<int> dq;
    public: 
    Stack() {}
    void push(int a) {
        dq.push_back(a);
    }
    void pop() {
        dq.pop_back();
    }
    int top() {
        return dq.back();
    }
    bool empty() {
        return dq.empty();
    }
    int size() {
        return dq.size();
    }
};
class Queue {
    deque<int> dq;
    public: 
    Queue() {}
    void push(int a) {
        dq.push_back(a);
    }
    void pop() {
        dq.pop_front();
    }
    int top() {
        return dq.front();
    }
    bool empty() {
        return dq.empty();
    }
    int size() {
        return dq.size();
    }
};
