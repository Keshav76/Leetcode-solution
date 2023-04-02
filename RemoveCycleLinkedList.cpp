// Question: https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/

// Remove Cycle in Linked List

// Floyd's Hare and Tortoise Algorithm
// First check if their is a cycle
// from that point, move fast pointer to head and start moving in a single step manner
// when fast.next = slow.next => remove the next of slow

// Edge case when loop is on first index
// Handle it separately

void removeLoop(Node* head){
    auto slow = head, fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break;
    }
    if (!fast || !fast->next) return;
    if (fast == head) {
        while (fast->next != head) fast = fast->next;
        fast->next = NULL;
        return;
    }
    fast = head;
    while (fast->next != slow->next) {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = NULL;
}
