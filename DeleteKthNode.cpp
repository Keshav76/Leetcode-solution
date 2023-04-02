// Question: https://leetcode.com/problems/remove-nth-node-from-end-of-list

// Remove Nth Node From End of List

// Approach: Two Pointers slow and fast
// Move fast pointer k steps while checking if it goes out of bound (in case when first element is to be removed)

// Move fast and slow pointers together until fast reaches end
// delete the slow + 1 value

ListNode* removeNthFromEnd(ListNode* head, int n) {
    auto slow = head, fast = head->next;
    for (int i = 0; i < n; i ++) {
        fast = fast->next;
        if (!fast) return head->next;
    }
    while (fast) {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    return head;
}
