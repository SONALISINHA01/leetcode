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
    bool mirror(TreeNode* one, TreeNode* sec){
        if(one == nullptr && sec == nullptr){
            return true;
        }
        if(one==nullptr || sec == nullptr){
            return false;
        }
        if(one->val == sec-> val){
            return mirror(one->left,sec->right) && mirror(one->right,sec->left);
        }
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        return mirror(root->left,root->right);
    }
};