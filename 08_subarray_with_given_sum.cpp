#include <iostream>
#include <vector>
using namespace std;

vector<int> subarraySum(vector<int>& arr, int target) {
    int currentSum = 0;
    int start = 0;
    
    for(int end = 0; end < arr.size(); end++) {
        currentSum += arr[end];
        
        while(currentSum > target && start < end) {
            currentSum -= arr[start];
            start++;
        }
        
        if(currentSum == target) {
            return {start, end};
        }
    }
    return {-1, -1};
}

int main() {
    vector<int> arr = {1, 4, 20, 3, 10, 5};
    int target = 33;
    vector<int> result = subarraySum(arr, target);
    if(result[0] != -1) {
        cout << "Found between index " << result[0] << " and " << result[1] << endl;
    }
    return 0;
}