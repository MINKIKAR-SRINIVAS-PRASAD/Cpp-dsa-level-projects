#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void floydWarshall(vector<vector<int>>& graph) {
    int V = graph.size();
    
    for(int k = 0; k < V; k++) {
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                if(graph[i][k] != INT_MAX && graph[k][j] != INT_MAX &&
                   graph[i][k] + graph[k][j] < graph[i][j]) {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }
}

int main() {
    vector<vector<int>> graph = {
        {0, 5, INT_MAX, 10},
        {INT_MAX, 0, 3, INT_MAX},
        {INT_MAX, INT_MAX, 0, 1},
        {INT_MAX, INT_MAX, INT_MAX, 0}
    };
    
    floydWarshall(graph);
    
    cout << "Shortest distances between all pairs:" << endl;
    for(auto& row : graph) {
        for(int d : row) {
            if(d == INT_MAX) cout << "INF ";
            else cout << d << " ";
        }
        cout << endl;
    }
    
    return 0;
}