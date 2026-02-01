class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dparr(n+1,0);
        dparr[1]=nums[0];
        for(int i =2;i<=n;i++){
            dparr[i]=max(dparr[i-1], dparr[i-2]+nums[i-1]);
        }
        return dparr[n];
    }
};