#include <iostream>
#include <string>
#include <sstream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

string serialize(TreeNode* root) {
    if(!root) return "null";
    return to_string(root->val) + "," + 
           serialize(root->left) + "," + 
           serialize(root->right);
}

TreeNode* deserializeHelper(stringstream& ss) {
    string val;
    getline(ss, val, ',');
    
    if(val == "null") return nullptr;
    
    TreeNode* node = new TreeNode(stoi(val));
    node->left = deserializeHelper(ss);
    node->right = deserializeHelper(ss);
    
    return node;
}

TreeNode* deserialize(string data) {
    stringstream ss(data);
    return deserializeHelper(ss);
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    
    string serialized = serialize(root);
    cout << "Serialized: " << serialized << endl;
    
    TreeNode* deserialized = deserialize(serialized);
    cout << "Deserialized root: " << deserialized->val << endl;
    
    return 0;
}