// Question: https://www.geeksforgeeks.org/segregate-even-and-odd-elements-in-a-linked-list/

// Segregate Even and Odd elements in a linked list

// Approach: Make two lists even and odd then join at end

ListNode* oddEvenList(ListNode* head) {
        ListNode* even = new ListNode(0); 
        ListNode* odd = new ListNode(0); 
        auto temp = head, o = odd, e = even;
        while (temp) {
            if (temp->val % 2) {
                o->next = temp;
                temp = temp->next;
                o = o->next;
            }
            else {
                e->next = temp;
                temp = temp->next;
                e = e->next;
            }
        }
        e->next = odd->next;
        o->next = NULL;
        return even->next;
    }
