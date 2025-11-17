#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* bottom;
    Node(int val) : data(val), next(nullptr), bottom(nullptr) {}
};

Node* mergeLists(Node* a, Node* b) {
    if(!a) return b;
    if(!b) return a;
    
    Node* result;
    if(a->data < b->data) {
        result = a;
        result->bottom = mergeLists(a->bottom, b);
    } else {
        result = b;
        result->bottom = mergeLists(a, b->bottom);
    }
    return result;
}

Node* flatten(Node* root) {
    if(!root || !root->next) return root;
    
    root->next = flatten(root->next);
    root = mergeLists(root, root->next);
    
    return root;
}

void printList(Node* head) {
    while(head) {
        cout << head->data << " ";
        head = head->bottom;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(5);
    head->bottom = new Node(7);
    head->bottom->bottom = new Node(8);
    head->bottom->bottom->bottom = new Node(30);
    
    head->next = new Node(10);
    head->next->bottom = new Node(20);
    
    head = flatten(head);
    printList(head);
    
    return 0;
}