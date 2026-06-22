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
    int dfs(TreeNode* root, long long targetsum, long long currsum, unordered_map<long long, int> &prefix){
        if(!root) return 0;
        currsum += root->val;
        int count=0;
        if(prefix.count(currsum-targetsum)){
            count+=prefix[currsum-targetsum];
        }
        prefix[currsum]++;
        count+=dfs(root->left,targetsum,currsum,prefix);
        count+=dfs(root->right, targetsum,currsum,prefix);
        prefix[currsum]--;
        return count;
    }
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> prefix;
        prefix[0]=1;
        return dfs(root,targetSum,0,prefix);
    }
};