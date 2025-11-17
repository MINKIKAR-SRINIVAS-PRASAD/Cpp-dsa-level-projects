#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<vector<int>> verticalTraversal(TreeNode* root) {
    map<int, vector<int>> columnMap;
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});
    
    while(!q.empty()) {
        auto [node, col] = q.front();
        q.pop();
        
        columnMap[col].push_back(node->val);
        
        if(node->left) q.push({node->left, col - 1});
        if(node->right) q.push({node->right, col + 1});
    }
    
    vector<vector<int>> result;
    for(auto& [col, nodes] : columnMap) {
        result.push_back(nodes);
    }
    
    return result;
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    
    vector<vector<int>> result = verticalTraversal(root);
    for(auto& column : result) {
        for(int val : column) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    return 0;
}