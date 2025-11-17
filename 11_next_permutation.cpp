#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void nextPermutation(vector<int>& nums) {
    int i = nums.size() - 2;
    // Find first decreasing element from right
    while(i >= 0 && nums[i] >= nums[i+1]) i--;
    
    if(i >= 0) {
        int j = nums.size() - 1;
        // Find element just larger than nums[i]
        while(nums[j] <= nums[i]) j--;
        swap(nums[i], nums[j]);
    }
    // Reverse the suffix
    reverse(nums.begin() + i + 1, nums.end());
}

int main() {
    vector<int> nums = {1, 2, 3};
    nextPermutation(nums);
    for(int x : nums) cout << x << " ";
    return 0;
}