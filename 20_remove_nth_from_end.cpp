#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* removeNthFromEnd(Node* head, int n) {
    Node dummy(0);
    dummy.next = head;
    Node* first = &dummy;
    Node* second = &dummy;
    
    // Move first pointer n+1 steps ahead
    for(int i = 0; i <= n; i++) {
        first = first->next;
    }
    
    // Move both pointers until first reaches end
    while(first) {
        first = first->next;
        second = second->next;
    }
    
    // Remove the node
    Node* temp = second->next;
    second->next = second->next->next;
    delete temp;
    
    return dummy.next;
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
    
    head = removeNthFromEnd(head, 2);
    printList(head);
    
    return 0;
}