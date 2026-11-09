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
    void recur(TreeNode* root,unordered_map<TreeNode*,pair<int,int>> &dp){
        if(root->left==nullptr && root->right ==nullptr){
            dp[root]={root->val,0};
            return;
        }
        if(root->left!=nullptr){
            recur(root->left,dp);
        }
        if(root->right!=nullptr){
            recur(root->right,dp);
        }
        int rob = root->val +dp[root->left].second + dp[root->right].second;
        int notrob = max(dp[root->left].first,dp[root->left].second) +
        max(dp[root->right].first ,dp[root->right].second);
        dp[root]={rob,notrob};
    }
    int rob(TreeNode* root) {
        unordered_map<TreeNode*,pair<int,int>> dp;
        recur(root,dp);
        return max(dp[root].first,dp[root].second);
    }
};