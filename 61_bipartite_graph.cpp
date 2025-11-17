#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isBipartite(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> color(n, -1);
    
    for(int start = 0; start < n; start++) {
        if(color[start] != -1) continue;
        
        queue<int> q;
        q.push(start);
        color[start] = 0;
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            
            for(int neighbor : adj[node]) {
                if(color[neighbor] == -1) {
                    color[neighbor] = 1 - color[node];
                    q.push(neighbor);
                } else if(color[neighbor] == color[node]) {
                    return false;
                }
            }
        }
    }
    
    return true;
}

int main() {
    int n = 4;
    vector<vector<int>> adj(n);
    
    adj[0] = {1, 3};
    adj[1] = {0, 2};
    adj[2] = {1, 3};
    adj[3] = {0, 2};
    
    if(isBipartite(adj)) {
        cout << "Graph is bipartite" << endl;
    } else {
        cout << "Graph is not bipartite" << endl;
    }
    
    return 0;
}