// Question: https://www.geeksforgeeks.org/merge-sort-for-linked-list/

// Merge Sort for Linked List

// Approach: Fast and slow pointer for mid

class Solution {
public:
    ListNode* merge(ListNode* a, ListNode* b) {
        if (!a) return b;
        if (!b) return a;
        if (a->val < b->val) {
            a->next = merge(a->next, b);
            return a;
        }
        b->next = merge(a, b->next);
        return b;
    }
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        auto slow = head, fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        auto right = sortList(slow->next);
        slow->next = NULL;
        auto left = sortList(head);
        return merge(left, right);
    }
};
