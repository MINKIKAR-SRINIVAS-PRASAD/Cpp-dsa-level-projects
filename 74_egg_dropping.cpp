#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int eggDrop(int eggs, int floors) {
    vector<vector<int>> dp(eggs + 1, vector<int>(floors + 1));
    
    for(int i = 1; i <= eggs; i++) {
        dp[i][0] = 0;
        dp[i][1] = 1;
    }
    for(int j = 1; j <= floors; j++) {
        dp[1][j] = j;
    }
    
    for(int i = 2; i <= eggs; i++) {
        for(int j = 2; j <= floors; j++) {
            dp[i][j] = INT_MAX;
            for(int k = 1; k <= j; k++) {
                int attempts = 1 + max(dp[i-1][k-1], dp[i][j-k]);
                dp[i][j] = min(dp[i][j], attempts);
            }
        }
    }
    return dp[eggs][floors];
}

int main() {
    int eggs = 2, floors = 10;
    cout << "Minimum attempts: " << eggDrop(eggs, floors) << endl;
    return 0;
}