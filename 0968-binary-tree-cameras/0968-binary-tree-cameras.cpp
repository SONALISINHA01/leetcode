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
    int result=0;
    void helper(TreeNode* root){
        if(root->left ==nullptr && root->right == nullptr){
            root->val =0;
            return;
        }
        if(root->left!=nullptr)helper(root->left);
        if(root->right!=nullptr)helper(root->right);
        if((root->left !=nullptr && root->left->val == 0 ) || (root->right!=nullptr && root->right->val ==0)){
            root->val = 1;
            result++;
            return;
        }
        if((root->left !=nullptr && root->left->val == 1 ) || (root->right!=nullptr && root->right->val ==1)){
            root->val = 2;
            return;
        }
    }
    int minCameraCover(TreeNode* root) {
        if (root == nullptr) return 0;
        helper(root);
        // if((root->left !=nullptr && root->left->val == 1 ) || (root->right!=nullptr && root->right->val ==1)){
        // }else{
        //     result++;
        // }
        if (root->val == 0) {
            result++;
        }
        return result;
    }
};