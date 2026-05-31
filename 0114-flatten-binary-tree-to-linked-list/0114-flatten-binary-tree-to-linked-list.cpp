/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root)return;
        flatten(root->left);
        flatten(root->right);
        TreeNode* le = root->left;
        TreeNode* ri = root->right;
        root->left=nullptr;
        root->right= le;
        TreeNode* curr= root;
        while(curr->right){
            curr=curr->right;
        }
        curr->right=ri;
    }
};