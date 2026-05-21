class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        long long totalsum=0;
        for(auto num:nums){
            totalsum+=num;
        }
        long long prefixsum=0;
        for(int i =0;i<n;i++){
            long suffixsum = totalsum - prefixsum - nums[i];
            long left= (1LL)* nums[i]*i - prefixsum;
            long right = suffixsum-(1LL)*nums[i]*(n-i-1);
            ans[i]=(int) (left+right);
            prefixsum+=nums[i];
        }
        return ans;
    }
};