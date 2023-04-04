// Question: https://leetcode.com/problems/merge-k-sorted-lists

// Merge K Sorted Linked List

// Approach: Priority Queue to hold all the values that needs to be merged

class Compare {
    public: 
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
        for (auto ele: lists) {
            if (ele)
                pq.push(ele);
        }
        ListNode* answer = new ListNode(-1), *ans = answer;
        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            ans->next = curr;
            ans = ans->next;
            if (curr->next) pq.push(curr->next);
        }
        ans->next = NULL;
        return answer->next;
    }
};
