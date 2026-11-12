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
    void traverse(TreeNode* root, unordered_map<TreeNode*,TreeNode*> &adj){
        if(root->left !=nullptr){
            adj[root->left] = root;
            traverse (root->left,adj);
        }
        if(root->right !=nullptr){
            adj[root->right]=root;
            traverse(root->right,adj);
        }
    }
    void finder(TreeNode* root,int &start,queue<TreeNode*> &q){
        if(root->val ==start){
            q.push(root);
            return;
        }
        if(root->left!=nullptr){
            finder(root->left,start,q);
        }
        if(root->right!=nullptr){
            finder(root->right,start,q);
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*> adj;
        traverse(root,adj);
        queue<TreeNode*> q;
        finder(root,start,q);
        int ans=0;
        while(!q.empty()){
            int sz=q.size();
            ans++;
            while(sz--){
                auto node = q.front();q.pop();
                if(adj.find(node)!=adj.end() && adj[node]->val!=-1){
                    q.push(adj[node]);
                    auto& n =adj[node];
                    n->val =-1;
                }
                if(node->left!=nullptr && node->left->val!=-1){
                    q.push(node->left);
                    node->left->val =-1;
                }
                if(node->right!=nullptr && node->right->val!=-1){
                    q.push(node->right);
                    node->right->val =-1;
                }
                node->val =-1;
            }
        }
        return --ans;
    }
};