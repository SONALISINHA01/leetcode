class Solution {
public:
    vector<vector<int>> ans;
    void helper(vector<int>& nums,int n , int i,vector<int>& temp){
        if(i>=n){
            ans.push_back(temp);
            return;
        }
        helper(nums,n,i+1,temp);
        temp.push_back(nums[i]);
        helper(nums,n,i+1,temp);
        temp.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        // for(int i =0;i<n;i++){
            helper(nums,n,0,temp);
        // }
        return ans;
    }
};