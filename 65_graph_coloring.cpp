#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>>& adj, vector<int>& color, int node, int c) {
    for(int neighbor : adj[node]) {
        if(color[neighbor] == c) {
            return false;
        }
    }
    return true;
}

bool graphColoringUtil(vector<vector<int>>& adj, int m, vector<int>& color, int node) {
    int n = adj.size();
    if(node == n) return true;
    
    for(int c = 1; c <= m; c++) {
        if(isSafe(adj, color, node, c)) {
            color[node] = c;
            if(graphColoringUtil(adj, m, color, node + 1)) {
                return true;
            }
            color[node] = 0;
        }
    }
    
    return false;
}

bool graphColoring(vector<vector<int>>& adj, int m) {
    int n = adj.size();
    vector<int> color(n, 0);
    return graphColoringUtil(adj, m, color, 0);
}

int main() {
    int n = 4;
    vector<vector<int>> adj(n);
    
    adj[0] = {1, 2, 3};
    adj[1] = {0, 2};
    adj[2] = {0, 1, 3};
    adj[3] = {0, 2};
    
    int m = 3;
    if(graphColoring(adj, m)) {
        cout << "Graph can be colored with " << m << " colors" << endl;
    } else {
        cout << "Graph cannot be colored with " << m << " colors" << endl;
    }
    
    return 0;
}