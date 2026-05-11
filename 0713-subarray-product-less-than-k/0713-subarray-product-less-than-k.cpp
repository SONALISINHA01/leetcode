class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        int ans=0;
        int mul=1;
        int st =0;
        for(int i=0;i<nums.size();i++){
            mul*=nums[i];
            while(mul>=k){
                mul/=nums[st];
                st++;
            }
            ans+=i-st+1;
        }
        return ans;
    }
};