//https://leetcode.com/problems/reorder-list

// Reorder List

// Approach: Reverse second half of array
// Have two list one with first half and other with reversd second half
// Merge them

class Solution {
public:
    ListNode* reverseLL(ListNode* head) {
        ListNode* prev = NULL, *curr = head;
        while (curr) {
            auto next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        auto slow = head, fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        auto t = slow->next;
        slow->next = NULL;
        slow = reverseLL(t);
        // slow = slow->next;
        fast = head;
        while(slow && fast) {
            auto temp = fast->next;
            fast->next = slow;
            slow = slow->next;
            fast->next->next = temp;
            fast = temp;
        }
    }
};
