#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int primsMST(vector<vector<pair<int, int>>>& adj) {
    int n = adj.size();
    vector<bool> inMST(n, false);
    vector<int> key(n, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    key[0] = 0;
    pq.push({0, 0});
    int mstCost = 0;
    
    while(!pq.empty()) {
        auto [wt, u] = pq.top();
        pq.pop();
        
        if(inMST[u]) continue;
        
        inMST[u] = true;
        mstCost += wt;
        
        for(auto [v, w] : adj[u]) {
            if(!inMST[v] && w < key[v]) {
                key[v] = w;
                pq.push({w, v});
            }
        }
    }
    
    return mstCost;
}

int main() {
    int n = 5;
    vector<vector<pair<int, int>>> adj(n);
    
    adj[0] = {{1, 2}, {3, 6}};
    adj[1] = {{0, 2}, {2, 3}, {3, 8}, {4, 5}};
    adj[2] = {{1, 3}, {4, 7}};
    adj[3] = {{0, 6}, {1, 8}};
    adj[4] = {{1, 5}, {2, 7}};
    
    cout << "MST cost: " << primsMST(adj) << endl;
    
    return 0;
}