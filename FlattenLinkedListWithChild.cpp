// Question: https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list

// 430. Flatten a Multilevel Doubly Linked List

// Approach: Recursion + Use a helper function to return head as well as tail to make less computation

pair<Node*, Node*> flat(Node* head) {
    if (!head) return {nullptr, NULL};
    auto temp = head;
    while(temp->next) {
        if (temp->child) {
            auto t = temp->next;
            auto ans = flat(temp->child);
            temp->child = NULL;
            ans.first->prev = temp;
            temp->next = ans.first;
            ans.second->next = t;
            t->prev = ans.second;
            temp = t;
            continue;
        }
        temp = temp->next;
    }
    if (temp->child) {
        auto ans = flat(temp->child);
        temp->child = NULL;
        temp->next = ans.first;
        ans.first->prev = temp;
        return {head, ans.second};
    }
    return {head, temp};
}
Node* flatten(Node* head) {
    return flat(head).first;
}
