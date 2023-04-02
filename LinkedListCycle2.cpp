// Question: https://leetcode.com/problems/linked-list-cycle-ii

// Linked List Cycle 2

// Approach: Flloyd's Hare and Tortoise Algotithm
// Have a fast and slow pointer
// fast += 2; slow ++
// When they meet => fast = head;
// while (slow != fast) fast++, slow++
// return slow

ListNode *detectCycle(ListNode *head) {
    auto slow = head, fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            break;
        }
    }
    if (!fast || !fast->next) return nullptr;
    fast = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}
