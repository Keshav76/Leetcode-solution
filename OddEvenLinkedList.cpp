// Question: https://leetcode.com/problems/odd-even-linked-list/

// Odd Even Linked List

// Approach: Divide in even and odd list and join at end

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* even = new ListNode(0); 
        ListNode* odd = new ListNode(0); 
        auto temp = head, o = odd, e = even; bool flag = false;
        while (temp) {
            if (flag) {
                o->next = temp;
                temp = temp->next;
                o = o->next;
            }
            else {
                e->next = temp;
                temp = temp->next;
                e = e->next;
                
            }
            flag = !flag;
        }
        e->next = odd->next;
        o->next = NULL;
        return even->next;
    }
};
