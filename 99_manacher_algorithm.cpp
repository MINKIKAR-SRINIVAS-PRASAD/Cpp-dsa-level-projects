#include <iostream>
#include <string>
#include <vector>
using namespace std;

string longestPalindrome(string s) {
    string t = "#";
    for(char c : s) {
        t += c;
        t += "#";
    }
    
    int n = t.length();
    vector<int> p(n, 0);
    int center = 0, right = 0;
    
    for(int i = 0; i < n; i++) {
        int mirror = 2 * center - i;
        
        if(i < right) {
            p[i] = min(right - i, p[mirror]);
        }
        
        while(i + p[i] + 1 < n && i - p[i] - 1 >= 0 &&
              t[i + p[i] + 1] == t[i - p[i] - 1]) {
            p[i]++;
        }
        
        if(i + p[i] > right) {
            center = i;
            right = i + p[i];
        }
    }
    
    int maxLen = 0, centerIndex = 0;
    for(int i = 0; i < n; i++) {
        if(p[i] > maxLen) {
            maxLen = p[i];
            centerIndex = i;
        }
    }
    
    int start = (centerIndex - maxLen) / 2;
    return s.substr(start, maxLen);
}

int main() {
    string s = "babad";
    cout << "Longest palindrome: " << longestPalindrome(s) << endl;
    return 0;
}