#include <iostream>
#include <queue>
using namespace std;

class MyStack {
    queue<int> q1, q2;
    
public:
    void push(int x) {
        q2.push(x);
        while(!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }
    
    int pop() {
        int val = q1.front();
        q1.pop();
        return val;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};

int main() {
    MyStack s;
    s.push(1);
    s.push(2);
    cout << "Top: " << s.top() << endl;
    cout << "Pop: " << s.pop() << endl;
    
    return 0;
}