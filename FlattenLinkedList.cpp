// Question: https://practice.geeksforgeeks.org/problems/flattening-a-linked-list

// Flatten Linked List

// Approach : Recursion : Treat given ll in two parts (1st column and rest of the ll)
// Solve for rest of the ll by recursion
// merge the two linked lists

Node* merge(Node*a, Node*b) {
    if (!a) return b;
    if (!b) return a;
    if (a->data < b->data) {
        a->bottom = merge(a->bottom, b);
        return a;
    }
    b->bottom = merge(a, b->bottom);
    return b;
}
Node *flatten(Node *root)
{
   // Your code here
   if(!root) return NULL;
   Node* rem = flatten(root->next);
   root->next = NULL;
   return merge(rem, root);
}
