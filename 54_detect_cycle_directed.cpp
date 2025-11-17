#include <iostream>
#include <vector>
using namespace std;

bool hasCycleDFS(vector<vector<int>>& adj, int node, vector<bool>& visited, vector<bool>& recStack) {
    visited[node] = true;
    recStack[node] = true;
    
    for(int neighbor : adj[node]) {
        if(!visited[neighbor]) {
            if(hasCycleDFS(adj, neighbor, visited, recStack)) {
                return true;
            }
        } else if(recStack[neighbor]) {
            return true;
        }
    }
    
    recStack[node] = false;
    return false;
}

bool hasCycle(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<bool> visited(n, false);
    vector<bool> recStack(n, false);
    
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            if(hasCycleDFS(adj, i, visited, recStack)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n = 4;
    vector<vector<int>> adj(n);
    
    adj[0] = {1};
    adj[1] = {2};
    adj[2] = {3};
    adj[3] = {1};
    
    if(hasCycle(adj)) {
        cout << "Graph has cycle" << endl;
    } else {
        cout << "Graph has no cycle" << endl;
    }
    
    return 0;
}