#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    stack<int> st;
    int maxArea = 0;
    int n = heights.size();
    
    for(int i = 0; i < n; i++) {
        while(!st.empty() && heights[st.top()] > heights[i]) {
            int h = heights[st.top()];
            st.pop();
            int w = st.empty() ? i : i - st.top() - 1;
            maxArea = max(maxArea, h * w);
        }
        st.push(i);
    }
    
    while(!st.empty()) {
        int h = heights[st.top()];
        st.pop();
        int w = st.empty() ? n : n - st.top() - 1;
        maxArea = max(maxArea, h * w);
    }
    
    return maxArea;
}

int main() {
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    cout << "Largest rectangle area: " << largestRectangleArea(heights) << endl;
    
    return 0;
}