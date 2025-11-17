#include <iostream>
#include <vector>
using namespace std;

void reverseArray(vector<int>& arr, int start, int end) {
    while(start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

void rotateArray(vector<int>& arr, int d) {
    int n = arr.size();
    d = d % n;
    reverseArray(arr, 0, d-1);
    reverseArray(arr, d, n-1);
    reverseArray(arr, 0, n-1);
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    int d = 2;
    cout << "Original: ";
    for(int x : arr) cout << x << " ";
    rotateArray(arr, d);
    cout << "\nRotated: ";
    for(int x : arr) cout << x << " ";
    return 0;
}