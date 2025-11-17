#include <iostream>
#include <vector>
using namespace std;

void DFSUtil(vector<vector<int>>& adj, int node, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";
    
    for(int neighbor : adj[node]) {
        if(!visited[neighbor]) {
            DFSUtil(adj, neighbor, visited);
        }
    }
}

void DFS(vector<vector<int>>& adj, int start) {
    vector<bool> visited(adj.size(), false);
    DFSUtil(adj, start, visited);
}

int main() {
    int n = 5;
    vector<vector<int>> adj(n);
    
    adj[0] = {1, 2};
    adj[1] = {0, 3, 4};
    adj[2] = {0};
    adj[3] = {1};
    adj[4] = {1};
    
    cout << "DFS traversal: ";
    DFS(adj, 0);
    
    return 0;
}