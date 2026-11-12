class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int comp = nums[0];
        int ind=0;
        int asc =1;
        for(int i=1;i<n;i++){
            if(nums[i]<comp){
                comp = nums[i];
            }else{
                asc = max(asc,i-ind);
                comp = nums[i];
                ind =i;
            }
        }
        asc = max(asc,n-ind);
        comp = nums[0];
        ind =0;
        int desc=1;
        for(int i=1;i<n;i++){
            if(nums[i]>comp){
                comp = nums[i];
            }else{
                desc = max(desc,i-ind);
                comp = nums[i];
                ind =i;
            }
        }
        desc = max(desc,n-ind);
        return max(asc,desc);
    }
};