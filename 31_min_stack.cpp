#include <iostream>
#include <stack>
using namespace std;

class MinStack {
    stack<int> st;
    stack<int> minSt;
    
public:
    void push(int x) {
        st.push(x);
        if(minSt.empty() || x <= minSt.top()) {
            minSt.push(x);
        }
    }
    
    void pop() {
        if(st.top() == minSt.top()) {
            minSt.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};

int main() {
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    
    cout << "Min: " << minStack.getMin() << endl;
    minStack.pop();
    cout << "Top: " << minStack.top() << endl;
    cout << "Min: " << minStack.getMin() << endl;
    
    return 0;
}