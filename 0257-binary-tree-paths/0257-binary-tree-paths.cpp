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
    void findpath(TreeNode* root, vector<string> &ans,string s){
        if(root->left ==nullptr && root->right==nullptr){
            ans.push_back(s);
            return;
        }
        if(root->left!=nullptr){
            findpath(root->left, ans, s+"->"+to_string(root->left->val));
        }
        if(root->right!=nullptr){
            findpath(root->right, ans, s+"->"+to_string(root->right->val));
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string s=to_string(root->val);
        findpath(root, ans, s);
        return ans;
    }
};