#include <iostream>
#include <unordered_map>
using namespace std;

class LRUCache {
    struct Node {
        int key, val;
        Node *prev, *next;
        Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
    };
    
    int capacity;
    unordered_map<int, Node*> cache;
    Node *head, *tail;
    
    void addNode(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }
    
    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    
public:
    LRUCache(int cap) : capacity(cap) {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(cache.find(key) == cache.end()) return -1;
        Node* node = cache[key];
        removeNode(node);
        addNode(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()) {
            Node* node = cache[key];
            removeNode(node);
            delete node;
        }
        
        Node* node = new Node(key, value);
        cache[key] = node;
        addNode(node);
        
        if(cache.size() > capacity) {
            Node* lru = tail->prev;
            removeNode(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }
};

int main() {
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl;
    cache.put(3, 3);
    cout << cache.get(2) << endl;
    return 0;
}