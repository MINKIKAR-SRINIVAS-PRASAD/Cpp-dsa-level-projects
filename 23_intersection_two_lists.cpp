#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

int getLength(Node* head) {
    int len = 0;
    while(head) {
        len++;
        head = head->next;
    }
    return len;
}

Node* getIntersectionNode(Node* headA, Node* headB) {
    int lenA = getLength(headA);
    int lenB = getLength(headB);
    
    // Align both lists
    while(lenA > lenB) {
        headA = headA->next;
        lenA--;
    }
    while(lenB > lenA) {
        headB = headB->next;
        lenB--;
    }
    
    // Find intersection
    while(headA && headB) {
        if(headA == headB) return headA;
        headA = headA->next;
        headB = headB->next;
    }
    
    return nullptr;
}

int main() {
    Node* common = new Node(8);
    common->next = new Node(10);
    
    Node* headA = new Node(3);
    headA->next = new Node(6);
    headA->next->next = common;
    
    Node* headB = new Node(4);
    headB->next = common;
    
    Node* intersection = getIntersectionNode(headA, headB);
    if(intersection) {
        cout << "Intersection at node: " << intersection->data << endl;
    }
    
    return 0;
}