#include <iostream>
#include <vector>
using namespace std;

int rodCutting(vector<int>& prices, int n) {
    vector<int> dp(n + 1, 0);
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            dp[i] = max(dp[i], prices[j-1] + dp[i-j]);
        }
    }
    return dp[n];
}

int main() {
    vector<int> prices = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = 8;
    cout << "Maximum profit: " << rodCutting(prices, n) << endl;
    return 0;
}