#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int longestConsecutive(vector<int>& nums) {
    unordered_set<int> numSet(nums.begin(), nums.end());
    int longest = 0;
    
    for(int num : numSet) {
        if(numSet.find(num - 1) == numSet.end()) {
            int currentNum = num;
            int currentStreak = 1;
            
            while(numSet.find(currentNum + 1) != numSet.end()) {
                currentNum++;
                currentStreak++;
            }
            longest = max(longest, currentStreak);
        }
    }
    return longest;
}

int main() {
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << "Longest consecutive sequence: " << longestConsecutive(nums) << endl;
    return 0;
}