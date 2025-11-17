#include <iostream>
#include <vector>
using namespace std;

class FenwickTree {
    vector<int> tree;
    int n;
    
public:
    FenwickTree(int size) : n(size) {
        tree.resize(n + 1, 0);
    }
    
    void update(int i, int delta) {
        while(i <= n) {
            tree[i] += delta;
            i += i & (-i);
        }
    }
    
    int query(int i) {
        int sum = 0;
        while(i > 0) {
            sum += tree[i];
            i -= i & (-i);
        }
        return sum;
    }
    
    int rangeQuery(int l, int r) {
        return query(r) - query(l - 1);
    }
};

int main() {
    FenwickTree ft(6);
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    for(int i = 0; i < arr.size(); i++) {
        ft.update(i + 1, arr[i]);
    }
    cout << "Sum [2, 4]: " << ft.rangeQuery(2, 4) << endl;
    return 0;
}