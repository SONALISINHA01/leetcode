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
    int ans = INT_MAX;
    void finder(TreeNode* root, int parent){
        if(root->left == nullptr && root->right==nullptr){
            ans = min(ans, parent);
            return;
        }
        if(root->left!=nullptr){
           finder(root->left,parent+1);
        }
        if(root->right!=nullptr){
            finder(root->right,parent+1);
        }

    }
    int minDepth(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        if(root->left == nullptr && root->right==nullptr){
            return 1;
        }
        finder(root,1);
        return ans;
    }
};