#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int checkHeight(TreeNode* root, bool& balanced) {
    if(!root) return 0;
    
    int left = checkHeight(root->left, balanced);
    int right = checkHeight(root->right, balanced);
    
    if(abs(left - right) > 1) {
        balanced = false;
    }
    
    return 1 + max(left, right);
}

bool isBalanced(TreeNode* root) {
    bool balanced = true;
    checkHeight(root, balanced);
    return balanced;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    if(isBalanced(root)) {
        cout << "Tree is balanced" << endl;
    } else {
        cout << "Tree is not balanced" << endl;
    }
    
    return 0;
}