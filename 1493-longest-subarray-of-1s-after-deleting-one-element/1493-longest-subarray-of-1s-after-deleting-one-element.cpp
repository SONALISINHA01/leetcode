class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int en =0, st=0;
        int toler = 1;
        while(en<n){
            if(nums[en]!=1){
                toler--;
            }
            while(toler<0){
                if(nums[st]==0){
                    toler++;
                }
                st++;
            }
            ans = max(ans, en-st);
            en++;
        }
        return ans;
    }
};