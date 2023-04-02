// Question: https://practice.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists

// Intersection Point in Y Shaped Linked Lists

// Approach: delete all the edges in the first linked list  => 
// So common part is no longer connected and will have only one elemnt

// Check the end of second linked list => It will be our result
// Also one eedge case (If their is no common region) => 
// For that check the end of second list at start and if it is matching with our found result
// It means no intersection


int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    if (!head1 || !head2) return -1;
    auto temp = head2;
    while (temp->next) {
        temp = temp->next;
    }
    auto last = temp;
    temp = head1;
    while (temp->next) {
        auto t = temp;
        temp = temp->next;
        t->next = NULL;
    }
    temp = head2;
    while (temp && temp->next) {
        temp = temp->next;
    }
    if (temp == last) return -1;
    return temp->data;
}
