#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void findPaths(TreeNode* root, string path, vector<string>& paths) {
    if(!root) return;
    
    path += to_string(root->val);
    
    if(!root->left && !root->right) {
        paths.push_back(path);
    } else {
        path += "->";
        findPaths(root->left, path, paths);
        findPaths(root->right, path, paths);
    }
}

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> paths;
    findPaths(root, "", paths);
    return paths;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    
    vector<string> paths = binaryTreePaths(root);
    for(string& path : paths) {
        cout << path << endl;
    }
    
    return 0;
}