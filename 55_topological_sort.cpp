#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void topologicalSortUtil(vector<vector<int>>& adj, int node, vector<bool>& visited, stack<int>& st) {
    visited[node] = true;
    
    for(int neighbor : adj[node]) {
        if(!visited[neighbor]) {
            topologicalSortUtil(adj, neighbor, visited, st);
        }
    }
    
    st.push(node);
}

vector<int> topologicalSort(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<bool> visited(n, false);
    stack<int> st;
    
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            topologicalSortUtil(adj, i, visited, st);
        }
    }
    
    vector<int> result;
    while(!st.empty()) {
        result.push_back(st.top());
        st.pop();
    }
    
    return result;
}

int main() {
    int n = 6;
    vector<vector<int>> adj(n);
    
    adj[5] = {2, 0};
    adj[4] = {0, 1};
    adj[2] = {3};
    adj[3] = {1};
    
    vector<int> result = topologicalSort(adj);
    cout << "Topological Sort: ";
    for(int node : result) {
        cout << node << " ";
    }
    
    return 0;
}