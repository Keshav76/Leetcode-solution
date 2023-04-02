// Question: https://practice.geeksforgeeks.org/problems/reverse-a-doubly-linked-list

// Reverse Doubly Linked List

// Approach: Prev, Curr, Next

Node* reverseDLL(Node * head)
{
    auto curr = head;
    Node *prev = nullptr;
    while (curr) {
        auto save = curr->next;
        curr->next = prev;
        curr->prev = save;
        prev = curr;
        curr = save;
    }
    return prev;
}
