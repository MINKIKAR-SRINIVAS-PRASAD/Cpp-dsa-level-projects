#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* rotateRight(Node* head, int k) {
    if(!head || k == 0) return head;
    
    // Find length and connect tail to head
    int len = 1;
    Node* tail = head;
    while(tail->next) {
        tail = tail->next;
        len++;
    }
    tail->next = head;
    
    // Find new tail
    k = k % len;
    int stepsToNewHead = len - k;
    Node* newTail = head;
    for(int i = 1; i < stepsToNewHead; i++) {
        newTail = newTail->next;
    }
    
    Node* newHead = newTail->next;
    newTail->next = nullptr;
    
    return newHead;
}

void printList(Node* head) {
    while(head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    
    head = rotateRight(head, 2);
    printList(head);
    
    return 0;
}