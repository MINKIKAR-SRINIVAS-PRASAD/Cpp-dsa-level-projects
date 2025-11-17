#include <iostream>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int maxSum = INT_MIN;

int maxPathSumHelper(TreeNode* root) {
    if(!root) return 0;
    
    int left = max(0, maxPathSumHelper(root->left));
    int right = max(0, maxPathSumHelper(root->right));
    
    maxSum = max(maxSum, left + right + root->val);
    
    return max(left, right) + root->val;
}

int maxPathSum(TreeNode* root) {
    maxSum = INT_MIN;
    maxPathSumHelper(root);
    return maxSum;
}

int main() {
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    
    cout << "Max path sum: " << maxPathSum(root) << endl;
    
    return 0;
}