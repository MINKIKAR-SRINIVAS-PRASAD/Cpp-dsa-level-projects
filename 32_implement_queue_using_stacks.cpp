#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
    stack<int> s1, s2;
    
    void transfer() {
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
    }
    
public:
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if(s2.empty()) transfer();
        int val = s2.top();
        s2.pop();
        return val;
    }
    
    int peek() {
        if(s2.empty()) transfer();
        return s2.top();
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

int main() {
    MyQueue q;
    q.push(1);
    q.push(2);
    cout << "Peek: " << q.peek() << endl;
    cout << "Pop: " << q.pop() << endl;
    
    return 0;
}