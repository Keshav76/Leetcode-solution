// Question: https://www.geeksforgeeks.org/sum-of-two-linked-lists/

// Add two numbers represented by linked lists 

// Approach: Recursion along with a carry value

class Solution {
public:
    ListNode* sum(ListNode* a, ListNode* b, int carry) {
        if (!a && !b) {
            if (carry == 0) return NULL;
            return new ListNode(carry);
        }
        int aval = 0, bval = 0;
        ListNode* anext = NULL, *bnext = NULL;
        if (a) {
            aval = a->val;
            anext = a->next;
        }
        if (b) {
            bval = b->val;
            bnext = b->next;
        }
        int res = (aval + bval + carry);
        int newCarry = res / 10;
        res = res % 10;
        return new ListNode(res, sum(anext, bnext, newCarry));
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return sum(l1, l2, 0); // 0 carry at begining
    }
};
