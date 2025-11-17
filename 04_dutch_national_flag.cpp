#include <iostream>
#include <vector>
using namespace std;

// Sort 0s, 1s, and 2s
void sortColors(vector<int>& arr) {
    int low = 0, mid = 0, high = arr.size() - 1;
    while(mid <= high) {
        if(arr[mid] == 0) {
            swap(arr[low++], arr[mid++]);
        } else if(arr[mid] == 1) {
            mid++;
        } else {
            swap(arr[mid], arr[high--]);
        }
    }
}

int main() {
    vector<int> arr = {2, 0, 2, 1, 1, 0};
    sortColors(arr);
    for(int x : arr) cout << x << " ";
    return 0;
}