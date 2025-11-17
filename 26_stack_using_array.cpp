#include <iostream>
#include <vector>
using namespace std;

class Stack {
    vector<int> arr;
    int topIndex;
    
public:
    Stack() : topIndex(-1) {}
    
    void push(int x) {
        arr.push_back(x);
        topIndex++;
    }
    
    int pop() {
        if(isEmpty()) return -1;
        int val = arr[topIndex];
        arr.pop_back();
        topIndex--;
        return val;
    }
    
    int top() {
        if(isEmpty()) return -1;
        return arr[topIndex];
    }
    
    bool isEmpty() {
        return topIndex == -1;
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    
    cout << "Top: " << s.top() << endl;
    cout << "Popped: " << s.pop() << endl;
    cout << "Top: " << s.top() << endl;
    
    return 0;
}