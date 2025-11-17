#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

bool isPalindrome(string& s, int i, int j) {
    while(i < j) {
        if(s[i] != s[j]) return false;
        i++; j--;
    }
    return true;
}

int minCuts(string s) {
    int n = s.length();
    vector<int> dp(n);
    
    for(int i = 0; i < n; i++) {
        int minCut = i;
        for(int j = 0; j <= i; j++) {
            if(isPalindrome(s, j, i)) {
                minCut = (j == 0) ? 0 : min(minCut, dp[j-1] + 1);
            }
        }
        dp[i] = minCut;
    }
    return dp[n-1];
}

int main() {
    string s = "aab";
    cout << "Minimum cuts: " << minCuts(s) << endl;
    return 0;
}