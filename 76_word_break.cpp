#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    int n = s.length();
    vector<bool> dp(n + 1, false);
    dp[0] = true;
    
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < i; j++) {
            if(dp[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[n];
}

int main() {
    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};
    if(wordBreak(s, wordDict)) {
        cout << "String can be segmented" << endl;
    } else {
        cout << "String cannot be segmented" << endl;
    }
    return 0;
}