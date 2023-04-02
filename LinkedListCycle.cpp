// Question: https://leetcode.com/problems/linked-list-cycle

// Linked List Cycle

// Approach: Have two pointers slow and fast
// If they evr meet => Loop
// If fast pointer reaches NULL => No loop

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* fast = head, *slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) return true;
        }
        return false;
    }
};
