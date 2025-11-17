#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Edge {
    int src, dest, weight;
};

vector<int> bellmanFord(int V, vector<Edge>& edges, int src) {
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    
    // Relax all edges V-1 times
    for(int i = 0; i < V - 1; i++) {
        for(auto& e : edges) {
            if(dist[e.src] != INT_MAX && dist[e.src] + e.weight < dist[e.dest]) {
                dist[e.dest] = dist[e.src] + e.weight;
            }
        }
    }
    
    // Check for negative cycles
    for(auto& e : edges) {
        if(dist[e.src] != INT_MAX && dist[e.src] + e.weight < dist[e.dest]) {
            cout << "Graph contains negative weight cycle" << endl;
            return {};
        }
    }
    
    return dist;
}

int main() {
    int V = 5;
    vector<Edge> edges = {
        {0, 1, -1}, {0, 2, 4}, {1, 2, 3},
        {1, 3, 2}, {1, 4, 2}, {3, 2, 5},
        {3, 1, 1}, {4, 3, -3}
    };
    
    vector<int> dist = bellmanFord(V, edges, 0);
    
    cout << "Shortest distances from source 0:" << endl;
    for(int i = 0; i < V; i++) {
        cout << "Node " << i << ": " << dist[i] << endl;
    }
    
    return 0;
}