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
    TreeNode* recur(int left, int right, vector<int> &nums){
        int mid = ((right-left)/2) + left;
        if(right<left){
            return nullptr;
        }
        TreeNode* root= new TreeNode(nums[mid]);
        root->left = recur(left, mid-1, nums);
        root->right = recur(mid+1, right, nums);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return recur(0,n-1,nums);
    }
};