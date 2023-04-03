// Question: https://practice.geeksforgeeks.org/problems/delete-nodes-having-greater-value-on-right/

// Delete Nodes with greater values on the right

// Approach: 
// Reverse the linked list 
// Traverse it and maintain the max found till now
// If element is bigger keep it, else remove it

Node *compute(Node *head) {
        Node *curr = head, *prev = NULL;
        while (curr) {
            auto next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
        int mx = INT_MIN;
        curr = head;
        auto answer = new Node(0);
        auto ans = answer;
        while (curr) {
            if (curr->data >= mx) {
                mx = curr->data;
                ans->next = curr;
                ans = ans->next;
            }
            curr = curr->next;
        }
        ans->next = NULL;
        curr = answer->next;
        prev = NULL;
        while (curr) {
            auto next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
