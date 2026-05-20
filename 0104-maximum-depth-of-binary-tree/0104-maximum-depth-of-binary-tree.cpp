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
    int ans =0;
    void help(TreeNode* root , int parent){
        ans = max(ans, parent);
        if(root==nullptr){
            return;
        }
        // max = max(ans, parent);
        help(root->left,parent+1);
        help(root->right,parent+1);
    }
    int maxDepth(TreeNode* root) {
        help(root,0);
        return ans;
    }
};