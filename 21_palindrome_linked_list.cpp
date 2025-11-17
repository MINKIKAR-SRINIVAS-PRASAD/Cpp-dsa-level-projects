#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* reverseList(Node* head) {
    Node* prev = nullptr;
    while(head) {
        Node* next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

bool isPalindrome(Node* head) {
    if(!head || !head->next) return true;
    
    // Find middle
    Node* slow = head;
    Node* fast = head;
    while(fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // Reverse second half
    slow->next = reverseList(slow->next);
    slow = slow->next;
    
    // Compare
    Node* p1 = head;
    Node* p2 = slow;
    while(p2) {
        if(p1->data != p2->data) return false;
        p1 = p1->next;
        p2 = p2->next;
    }
    return true;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(2);
    head->next->next->next = new Node(1);
    
    if(isPalindrome(head)) {
        cout << "List is palindrome" << endl;
    } else {
        cout << "List is not palindrome" << endl;
    }
    
    return 0;
}