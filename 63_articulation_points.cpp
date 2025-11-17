#include <iostream>
#include <vector>
#include <set>
using namespace std;

void articulationDFS(vector<vector<int>>& adj, int u, int parent, vector<int>& disc,
                     vector<int>& low, vector<bool>& visited, int& timer, set<int>& articulation) {
    visited[u] = true;
    disc[u] = low[u] = timer++;
    int children = 0;
    
    for(int v : adj[u]) {
        if(v == parent) continue;
        
        if(visited[v]) {
            low[u] = min(low[u], disc[v]);
        } else {
            children++;
            articulationDFS(adj, v, u, disc, low, visited, timer, articulation);
            low[u] = min(low[u], low[v]);
            
            if(parent != -1 && low[v] >= disc[u]) {
                articulation.insert(u);
            }
        }
    }
    
    if(parent == -1 && children > 1) {
        articulation.insert(u);
    }
}

set<int> findArticulationPoints(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> disc(n), low(n);
    vector<bool> visited(n, false);
    set<int> articulation;
    int timer = 0;
    
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            articulationDFS(adj, i, -1, disc, low, visited, timer, articulation);
        }
    }
    
    return articulation;
}

int main() {
    int n = 5;
    vector<vector<int>> adj(n);
    
    adj[0] = {1};
    adj[1] = {0, 2, 3};
    adj[2] = {1};
    adj[3] = {1, 4};
    adj[4] = {3};
    
    set<int> points = findArticulationPoints(adj);
    
    cout << "Articulation points: ";
    for(int p : points) {
        cout << p << " ";
    }
    
    return 0;
}