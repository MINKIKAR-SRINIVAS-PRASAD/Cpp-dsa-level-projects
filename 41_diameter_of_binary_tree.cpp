#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int maxDiameter = 0;

int height(TreeNode* root) {
    if(!root) return 0;
    
    int left = height(root->left);
    int right = height(root->right);
    
    maxDiameter = max(maxDiameter, left + right);
    
    return 1 + max(left, right);
}

int diameterOfBinaryTree(TreeNode* root) {
    maxDiameter = 0;
    height(root);
    return maxDiameter;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    cout << "Diameter: " << diameterOfBinaryTree(root) << endl;
    
    return 0;
}