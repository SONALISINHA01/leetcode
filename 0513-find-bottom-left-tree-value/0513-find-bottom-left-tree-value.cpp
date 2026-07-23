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
    int findBottomLeftValue(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        queue<TreeNode*> q;
        q.push(root);
        int leftval=0;
        while(!q.empty()){
            int sz = q.size();
            bool first = true;
            while(sz--){
                auto* no  = q.front();
                q.pop();
                if( first){
                    leftval = no->val;
                    first = false;
                }
                if(no->left!=nullptr){
                    q.push(no->left);
                }
                if(no->right!=nullptr){
                    q.push(no->right);
                }
            }
        }
        return leftval;
    }
};