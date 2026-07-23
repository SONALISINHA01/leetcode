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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(root==nullptr){
            return {};
        }
        vector<vector<int>> val;
        queue<pair<vector<int>,TreeNode*>> q;
        q.push({{0,0},root});
        while(!q.empty()){
            auto node = q.front();
            vector<int> pos = node.first;
            int col = pos[0];
            int row = pos[1];
            TreeNode* no = node.second;
            q.pop();
            val.push_back({col,row,no->val});
            if(no->left!=nullptr){
                q.push({{col-1,row+1},no->left});
            }
            if(no->right!=nullptr){
                q.push({{col+1,row+1},no->right});
            }
        }
        sort(val.begin(),val.end());
        vector<vector<int>> ans;
        vector<int> temp;
        int n = val.size();
        int curr = val[0][0];
        for(int i =0;i<n;i++){
            if(curr==val[i][0]){
                temp.push_back(val[i][2]);
            }else{
                ans.push_back(temp);
                temp.clear();
                curr = val[i][0];
                temp.push_back(val[i][2]);
            }
        }
        ans.push_back(temp);
        return ans;
    }
};