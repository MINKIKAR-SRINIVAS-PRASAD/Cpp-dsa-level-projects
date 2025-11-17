#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void levelOrder(TreeNode* root) {
    if(!root) return;
    
    queue<TreeNode*> q;
    q.push(root);
    
    while(!q.empty()) {
        int size = q.size();
        for(int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();
            cout << node->val << " ";
            
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        cout << endl;
    }
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    cout << "Level order traversal:" << endl;
    levelOrder(root);
    
    return 0;
}