// Question: https://www.geeksforgeeks.org/sort-biotonic-doubly-linked-list/

// Sort the bitonic doubly linked list

// Approach: Find the split point and reverse the Reversed Part. Merge the two parts


Node* merge(Node* a, Node* b) {
    if (!a) return b;
    if (!b) return a;
    if (a->data > b->data) {
        b->next = merge(a, b->next);
        return b;
    }
    else {
        a->next = merge(a->next, b);
        return a;
    }
}
Node* deleteNode(Node *head, int x)
{
    auto temp = head;
    Node* curr;
    while (temp && temp->next) {
        if (temp->data > temp->next->data) break;
        temp = temp->next;
    }
    {curr = temp->next;
    temp->next = NULL;}
    Node* prev = NULL;
    while (curr) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return merge(head, prev);

}
