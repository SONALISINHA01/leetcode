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
    bool validate(TreeNode* root, long long mi,long long ma){
        if(root==nullptr)return true;
        if(root->val <=mi || root->val>=ma){
            return false;
        }
        return validate(root->left, mi,root->val) && validate(root->right,root->val,ma);
    }
    bool isValidBST(TreeNode* root) {
        return validate(root, LLONG_MIN,LLONG_MAX);
    }
};