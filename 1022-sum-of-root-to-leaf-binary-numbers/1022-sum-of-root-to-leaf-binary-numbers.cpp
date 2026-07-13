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
    vector<string> nums;
    void possibilities(TreeNode* root, string &temp){
        if(root->left == nullptr && root->right == nullptr){
            nums.push_back(temp);
            return;
        }
        if(root->left!=nullptr){
            temp+= root->left->val +'0';
            possibilities(root->left,temp);
            temp.pop_back();
        }

        if(root->right!=nullptr){
            temp+=root->right->val +'0';
            possibilities(root->right,temp);
            temp.pop_back();
        }

    }
    int converter(string s){
        int num = 0;
        for(int i =0;i<s.size();i++){
            num=num*2;
            if(s[i]=='1'){
                num += 1;
            }
        }
        return num;
    }
    int sumRootToLeaf(TreeNode* root) {
        if(root==nullptr)return 0;
        string temp="";
        temp+=root->val + '0';
        possibilities(root,temp);
        int ans =0;
        for(int i =0;i<nums.size();i++){
            ans += converter(nums[i]);
        }
        return ans;
    }
};