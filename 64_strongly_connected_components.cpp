#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void DFS1(vector<vector<int>>& adj, int node, vector<bool>& visited, stack<int>& st) {
    visited[node] = true;
    for(int neighbor : adj[node]) {
        if(!visited[neighbor]) {
            DFS1(adj, neighbor, visited, st);
        }
    }
    st.push(node);
}

void DFS2(vector<vector<int>>& adj, int node, vector<bool>& visited, vector<int>& component) {
    visited[node] = true;
    component.push_back(node);
    for(int neighbor : adj[node]) {
        if(!visited[neighbor]) {
            DFS2(adj, neighbor, visited, component);
        }
    }
}

vector<vector<int>> kosaraju(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<bool> visited(n, false);
    stack<int> st;
    
    // First DFS
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            DFS1(adj, i, visited, st);
        }
    }
    
    // Transpose graph
    vector<vector<int>> transpose(n);
    for(int i = 0; i < n; i++) {
        for(int j : adj[i]) {
            transpose[j].push_back(i);
        }
    }
    
    // Second DFS
    fill(visited.begin(), visited.end(), false);
    vector<vector<int>> sccs;
    
    while(!st.empty()) {
        int node = st.top();
        st.pop();
        
        if(!visited[node]) {
            vector<int> component;
            DFS2(transpose, node, visited, component);
            sccs.push_back(component);
        }
    }
    
    return sccs;
}

int main() {
    int n = 5;
    vector<vector<int>> adj(n);
    
    adj[0] = {2, 3};
    adj[1] = {0};
    adj[2] = {1};
    adj[3] = {4};
    
    vector<vector<int>> sccs = kosaraju(adj);
    
    cout << "Strongly Connected Components:" << endl;
    for(auto& scc : sccs) {
        for(int node : scc) {
            cout << node << " ";
        }
        cout << endl;
    }
    
    return 0;
}