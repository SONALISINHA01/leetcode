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
    bool target(TreeNode* root, int targetSum, int temp){
        if(!root){
            return false;
        }
       // ~~~
        // if(((root->val)+ temp )== targetSum){
        //     temp += root->val;
        //     return true;
        // }
        // if(root->val + temp > targetSum){
        //     return false;
        // }
       // ~~~ this is wrong because we are supposed to check the sum at leaf and we never updated the sum of temp in this manner only added when it hit the targetsum . very wrong . 
       
        temp = temp+ root->val;
        if(root->right == nullptr && root->left == nullptr){
            if(temp== targetSum ){
                return true;
            }else{
                return false;
            }
        }
        if(target(root->left,targetSum, temp)){
            return true;
        }
        if(target(root->right, targetSum, temp)){
            return true;
        }
        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int temp =0;
        if(target(root, targetSum, temp)){
            return true;
        }
        return false;
    }
};