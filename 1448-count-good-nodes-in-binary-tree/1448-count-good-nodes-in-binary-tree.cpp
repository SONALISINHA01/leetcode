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
    void lordofmysteries(TreeNode* root, int& cnt){
        if(root == nullptr)return;
        if(root->left){
            if(root->left->val >= root->val){
                cnt++;
            }
            root->left->val = max(root->left->val,root->val);
            lordofmysteries(root->left,cnt);
        }
        if(root->right){
            if(root->right->val >= root->val){
                cnt++;
            }
            root->right->val = max(root->right->val,root->val);
            lordofmysteries(root->right,cnt);
        }
    }
    int goodNodes(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        int cnt=1;
        lordofmysteries(root,cnt);
        return cnt;
    }
};