#include <iostream>
#include <vector>
using namespace std;

bool hasCycleDFS(vector<vector<int>>& adj, int node, int parent, vector<bool>& visited) {
    visited[node] = true;
    
    for(int neighbor : adj[node]) {
        if(!visited[neighbor]) {
            if(hasCycleDFS(adj, neighbor, node, visited)) {
                return true;
            }
        } else if(neighbor != parent) {
            return true;
        }
    }
    return false;
}

bool hasCycle(vector<vector<int>>& adj) {
    vector<bool> visited(adj.size(), false);
    
    for(int i = 0; i < adj.size(); i++) {
        if(!visited[i]) {
            if(hasCycleDFS(adj, i, -1, visited)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n = 5;
    vector<vector<int>> adj(n);
    
    adj[0] = {1};
    adj[1] = {0, 2, 4};
    adj[2] = {1, 3};
    adj[3] = {2, 4};
    adj[4] = {1, 3};
    
    if(hasCycle(adj)) {
        cout << "Graph has cycle" << endl;
    } else {
        cout << "Graph has no cycle" << endl;
    }
    
    return 0;
}