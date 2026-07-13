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
    vector<int> allval;
    void form(TreeNode* root){
        if(root==nullptr){
            return;
        }
        allval.push_back(root->val);
        form(root->left);
        form(root->right);
    }
    int findSecondMinimumValue(TreeNode* root) {
        form(root);
        sort(allval.begin(),allval.end());
        allval.erase(unique(allval.begin(),allval.end()),allval.end());
        if(allval.size()<2){
            return -1;
        }
        return allval[1];
    }
};