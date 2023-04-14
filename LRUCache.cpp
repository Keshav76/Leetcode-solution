// Question: https://leetcode.com/problems/lru-cache/

// LRU Cache

// Approach: Use Doubly Linked List to show priority and HashMap to have O(1) access
// Linked List used for O(1) deletion from middle and insertion at most recently used end
// Evict from other end

class Node {
    public:
    int key, val;
    Node* prev, *next;
    Node(int key = -1, int val = -1, Node* next = NULL, Node* prev = NULL) {
        this->key = key;
        this->val = val;
        this->prev = prev;
        this->next = next;
    }
};

class LRUCache {
public:
    int size;
    unordered_map<int, Node*> mp;
    Node* lru = new Node();
    Node* mru = new Node();
    LRUCache(int capacity) {
        size = capacity;
        mru->prev = lru;
        lru->next = mru;
    }

    void insert(Node* curr) {
        // at prev of mru
        mru->prev->next = curr;
        curr->prev = mru->prev;
        curr->next = mru;
        mru->prev = curr;
        mp[curr->key] = curr;
    }
    void remove(Node* curr) {
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        mp.erase(curr->key);
    }
    
    int get(int key) {
        if (mp.count(key)) {
            auto ans = mp[key];
            remove(ans);
            insert(ans);
            return ans->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        Node* ans;
        if (mp.count(key)) {
            ans = mp[key];
            remove(ans);
            ans->val = value;
        }
        else {
            ans = new Node(key, value);
        }
        insert(ans);
        if (mp.size() > size) {
            auto toRem = lru->next;
            remove(toRem);
        }
    }
};
