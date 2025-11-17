#include <iostream>
#include <stack>
#include <string>
using namespace std;

int evaluatePostfix(string expr) {
    stack<int> st;
    
    for(char c : expr) {
        if(isdigit(c)) {
            st.push(c - '0');
        } else {
            int val2 = st.top(); st.pop();
            int val1 = st.top(); st.pop();
            
            switch(c) {
                case '+': st.push(val1 + val2); break;
                case '-': st.push(val1 - val2); break;
                case '*': st.push(val1 * val2); break;
                case '/': st.push(val1 / val2); break;
            }
        }
    }
    
    return st.top();
}

int main() {
    string expr = "231*+9-";
    cout << "Result: " << evaluatePostfix(expr) << endl;
    
    return 0;
}