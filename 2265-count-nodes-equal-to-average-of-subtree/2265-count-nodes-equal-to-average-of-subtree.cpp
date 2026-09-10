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
    int ans=0;
    pair<int,int> helper(TreeNode* root){
        if(root==nullptr){
            return {0,0};
        }
        // if(root->left == nullptr && root->right==nullptr){
        //     return {root->val,1};
        // }
        auto [leftval,leftcount]=helper(root->left);
        auto [rightval,rightcount]=helper(root->right);
        int temp = leftval+rightval+root->val;
        int div = leftcount+rightcount+1;
        if(temp/div == root->val){
            ans++;
        }
        return {temp, div};
    }
    int averageOfSubtree(TreeNode* root) {
        helper(root);
        return ans;
    }
};