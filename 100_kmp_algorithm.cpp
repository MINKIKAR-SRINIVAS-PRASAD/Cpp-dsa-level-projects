#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> computeLPS(string pattern) {
    int m = pattern.length();
    vector<int> lps(m, 0);
    int len = 0, i = 1;
    
    while(i < m) {
        if(pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if(len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

vector<int> KMP(string text, string pattern) {
    int n = text.length(), m = pattern.length();
    vector<int> lps = computeLPS(pattern);
    vector<int> result;
    
    int i = 0, j = 0;
    while(i < n) {
        if(text[i] == pattern[j]) {
            i++; j++;
        }
        
        if(j == m) {
            result.push_back(i - j);
            j = lps[j - 1];
        } else if(i < n && text[i] != pattern[j]) {
            if(j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    return result;
}

int main() {
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";
    vector<int> matches = KMP(text, pattern);
    cout << "Pattern found at: ";
    for(int index : matches) cout << index << " ";
    return 0;
}