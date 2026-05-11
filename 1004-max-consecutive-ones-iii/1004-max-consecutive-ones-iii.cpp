class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int en=0, st=0;
        int count=k;
        int ans=0;
        while(en<n){
            if(nums[en]==1){
                en++;
            }else{
                if(count>0){
                    count--;
                }else{
                    count--;
                    while(count<0){
                        if(nums[st]==0){
                            count++;
                        }
                        st++;
                    }
                }
                en++;

            }
            ans=max(ans,en-st);
        }
        return ans;
    }
};