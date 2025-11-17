#include <iostream>
#include <vector>
using namespace std;

// Element is leader if it's greater than all elements to its right
vector<int> findLeaders(vector<int>& arr) {
    vector<int> leaders;
    int n = arr.size();
    int maxFromRight = arr[n-1];
    leaders.push_back(maxFromRight);
    
    for(int i = n-2; i >= 0; i--) {
        if(arr[i] > maxFromRight) {
            maxFromRight = arr[i];
            leaders.push_back(maxFromRight);
        }
    }
    reverse(leaders.begin(), leaders.end());
    return leaders;
}

int main() {
    vector<int> arr = {16, 17, 4, 3, 5, 2};
    vector<int> leaders = findLeaders(arr);
    cout << "Leaders: ";
    for(int x : leaders) cout << x << " ";
    return 0;
}