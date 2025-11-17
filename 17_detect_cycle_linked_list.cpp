#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

bool hasCycle(Node* head) {
    if(!head) return false;
    
    Node* slow = head;
    Node* fast = head;
    
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        
        if(slow == fast) return true;
    }
    return false;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = head->next; // Creating cycle
    
    if(hasCycle(head)) {
        cout << "Cycle detected!" << endl;
    } else {
        cout << "No cycle" << endl;
    }
    
    return 0;
}