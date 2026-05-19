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
    bool same = true;
    void equality(TreeNode* proot , TreeNode* qroot){
        if(proot==nullptr && qroot!=nullptr){
            same = false;
            return;
        }
        if(qroot==nullptr && proot!=nullptr){
            same = false;
            return;
        }
        if(qroot == nullptr && proot == nullptr){
            return;
        }
        if(proot->val!=qroot->val){
            same = false;
            return;
        }
        equality(proot->left,qroot->left);
        equality(proot->right, qroot->right);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        equality(p,q);
        return same;
    }
};