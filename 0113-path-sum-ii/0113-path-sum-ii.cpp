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
    vector<vector<int>> ans;
    void target(TreeNode* root, int targetSum, int temp, vector<int> ans2){
        if(!root){
            return;
        }
        temp = temp+ root->val;
        ans2.push_back(root->val);
        if(root->right == nullptr && root->left == nullptr){
            if(temp== targetSum ){
                ans.push_back(ans2);
            }
        }
        target(root->left,targetSum, temp,ans2);
        target(root->right, targetSum, temp, ans2);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int temp =0;
        vector<int> ans2;
        target(root, targetSum, temp, ans2);
        return ans;
    }
};