// Question: https://www.geeksforgeeks.org/linked-list-in-zig-zag-fashion/

// Rearrange a linked list in zigzag pattern

// Approach: If node that should be larger is smaller than next => swap
// If node that should be smaller is larger than next value => swap

Node* zigzag(Node * head) {
    bool flag = true;
    auto temp = head;
    while (temp->next) {
        if (flag) {
            if (temp->data > temp->next->data) {
                swap(temp->data, temp->next->data);
            }
        } else {
            if (temp->data < temp->next->data) {
                swap(temp->data, temp->next->data);
            }
        }
        temp = temp->next;
        flag = !flag;
    }
    return head;
}
