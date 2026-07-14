/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    queue<TreeNode*> q;
    void findpr(TreeNode* root,map<TreeNode*,TreeNode*> &mp,map<TreeNode*,bool> &visited){
        if(root==nullptr){
            return;
        }
        visited[root]=false;
        if(root->left!=nullptr){
            mp[root->left]=root;
            findpr(root->left,mp,visited);
        }
        if(root->right!=nullptr){
            mp[root->right]=root;
            findpr(root->right,mp,visited);
        }
    }
    void distance(TreeNode* target,int& k,map<TreeNode*,TreeNode*> &mp,map<TreeNode*,bool> &visited){
        q.push(target);
        visited[target]=true;
        while(!q.empty()){
            int sz = q.size();
            if(k==0){
                return;
            }
            while(sz--){
                TreeNode* onduty = q.front();
                q.pop();
                if(mp.find(onduty)!=mp.end() && visited[mp[onduty]]==false){
                    q.push(mp[onduty]);
                    visited[mp[onduty]]=true;
                }
                if(onduty->left!=nullptr && visited[onduty->left]==false){
                    q.push(onduty->left);
                    visited[onduty->left]=true;
                }
                if(onduty->right!=nullptr && visited[onduty->right]==false){
                    q.push(onduty->right);
                    visited[onduty->right]=true;
                }
            }
            k--;
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(root==nullptr){
            return {};
        }
        map<TreeNode*,TreeNode*> parent;
        map<TreeNode*,bool> visited;
        findpr(root,parent,visited);
        distance(target,k,parent,visited);
        vector<int> ans;
        int sz = q.size();
        while(sz--){
            TreeNode* curr = q.front();
            q.pop();
            ans.push_back(curr->val);
        }
        return ans;
    }
};