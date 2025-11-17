#include <iostream>
#include <vector>
using namespace std;

int unboundedKnapsack(vector<int>& weights, vector<int>& values, int W) {
    vector<int> dp(W + 1, 0);
    
    for(int w = 0; w <= W; w++) {
        for(int i = 0; i < weights.size(); i++) {
            if(weights[i] <= w) {
                dp[w] = max(dp[w], dp[w - weights[i]] + values[i]);
            }
        }
    }
    return dp[W];
}

int main() {
    vector<int> weights = {1, 3, 4};
    vector<int> values = {15, 50, 60};
    int W = 8;
    cout << "Maximum value: " << unboundedKnapsack(weights, values, W) << endl;
    return 0;
}