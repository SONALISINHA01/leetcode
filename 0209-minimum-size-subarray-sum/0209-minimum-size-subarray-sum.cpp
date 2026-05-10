class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int st=0,en=0;
        int n = nums.size();
        int sum=0;
        int ans=INT_MAX;
        bool sumreached= false;
        while(en<n){
            sum+=nums[en];
            en++;
            while(sum>=target){
                sumreached= true;
                ans=min(ans,en-st);
                sum-=nums[st];
                st++;
            }
        }
        if(sumreached)return ans;
        return 0;
    }
};