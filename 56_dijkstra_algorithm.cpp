#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

vector<int> dijkstra(vector<vector<pair<int, int>>>& adj, int src) {
    int n = adj.size();
    vector<int> dist(n, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    dist[src] = 0;
    pq.push({0, src});
    
    while(!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        
        if(d > dist[u]) continue;
        
        for(auto [v, w] : adj[u]) {
            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    
    return dist;
}

int main() {
    int n = 5;
    vector<vector<pair<int, int>>> adj(n);
    
    adj[0] = {{1, 4}, {2, 1}};
    adj[1] = {{3, 1}};
    adj[2] = {{1, 2}, {3, 5}};
    adj[3] = {{4, 3}};
    
    vector<int> dist = dijkstra(adj, 0);
    
    cout << "Shortest distances from source 0:" << endl;
    for(int i = 0; i < n; i++) {
        cout << "Node " << i << ": " << dist[i] << endl;
    }
    
    return 0;
}