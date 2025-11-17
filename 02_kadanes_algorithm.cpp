#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Maximum subarray sum - Kadane's algorithm
int maxSubarraySum(vector<int>& nums) {
    int maxSum = INT_MIN;
    int currentSum = 0;
    
    for(int i = 0; i < nums.size(); i++) {
        currentSum += nums[i];
        maxSum = max(maxSum, currentSum);
        if(currentSum < 0) currentSum = 0;
    }
    return maxSum;
}

int main() {
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Maximum subarray sum: " << maxSubarraySum(arr) << endl;
    return 0;
}