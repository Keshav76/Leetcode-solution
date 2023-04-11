// Question: https://www.geeksforgeeks.org/design-a-stack-with-find-middle-operation/

// Design a stack with operations on middle element

// Approach: Implement using Doubly Linked List

class DLL {
    public:
        int data;
        DLL* next;
        DLL* prev;
        DLL(){}
        DLL(int a) {
            data = a;
            next = NULL;
            prev = NULL;
        }
};
class Stack{
    public:
        DLL *head, *temp, *mid;
        bool even;
        Stack() {
            head = new DLL(-1);
            temp = head;
            mid = head;
            even = false;
        }
        void push(int a) {
            temp->next = new DLL(a);
            temp->next->prev = temp;
            temp = temp->next;
            even = !even;
            if (even) {
                mid = mid->next;
            }
        }
        void pop() {
            temp = temp->prev;
            temp->next = NULL;
            if (even) {
                mid = mid->prev;
            }
            even = !even;
        }
        int top() {
            return temp->data;
        }
        int middle() {
            return mid->data;
        }
        void delMid() {
            auto curr = mid;
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            mid = curr->prev;
        }
};
