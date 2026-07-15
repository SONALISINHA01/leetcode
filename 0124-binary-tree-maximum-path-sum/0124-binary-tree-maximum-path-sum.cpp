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
    int ans;
    int idkgodcode(TreeNode* root){
        if(root->left==nullptr && root->right==nullptr){
            ans=max(ans,root->val);
            if(root->val<0){
                return 0;
            }else{
                return root->val;
            }
        }
        if(root->left!=nullptr && root->right!=nullptr){
            int l = idkgodcode(root->left);
            if(l <0){
                l=0;
            }
            int r = idkgodcode(root->right);
            if(r<0){
                r=0;
            }
            ans = max(ans,(l+r+root->val));
            return root->val + max(l,r);
        }
        if(root->left!=nullptr){
            int l = idkgodcode(root->left);
            if(l<0){
                l=0;
            }
            ans = max(ans,(l+root->val));
            return root->val+l;
        }
        if(root->right != nullptr){
            int r = idkgodcode(root->right);
            if(r<0){
                r=0;
            }
            ans = max(ans,(r+root->val));
            return root->val+r;
        }
        return ans;
    }
    int maxPathSum(TreeNode* root) {
        ans=INT_MIN;
        idkgodcode(root);
        return ans;
    }
};