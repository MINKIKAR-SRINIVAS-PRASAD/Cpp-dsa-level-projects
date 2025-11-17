#include <iostream>
#include <vector>
using namespace std;

void bridgeDFS(vector<vector<int>>& adj, int u, int parent, vector<int>& disc, 
               vector<int>& low, vector<bool>& visited, int& timer, vector<pair<int, int>>& bridges) {
    visited[u] = true;
    disc[u] = low[u] = timer++;
    
    for(int v : adj[u]) {
        if(v == parent) continue;
        
        if(visited[v]) {
            low[u] = min(low[u], disc[v]);
        } else {
            bridgeDFS(adj, v, u, disc, low, visited, timer, bridges);
            low[u] = min(low[u], low[v]);
            
            if(low[v] > disc[u]) {
                bridges.push_back({u, v});
            }
        }
    }
}

vector<pair<int, int>> findBridges(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> disc(n), low(n);
    vector<bool> visited(n, false);
    vector<pair<int, int>> bridges;
    int timer = 0;
    
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            bridgeDFS(adj, i, -1, disc, low, visited, timer, bridges);
        }
    }
    
    return bridges;
}

int main() {
    int n = 5;
    vector<vector<int>> adj(n);
    
    adj[0] = {1, 2};
    adj[1] = {0, 2};
    adj[2] = {0, 1, 3};
    adj[3] = {2, 4};
    adj[4] = {3};
    
    vector<pair<int, int>> bridges = findBridges(adj);
    
    cout << "Bridges in graph:" << endl;
    for(auto [u, v] : bridges) {
        cout << u << " - " << v << endl;
    }
    
    return 0;
}