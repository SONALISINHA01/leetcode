class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int sum=0;
        for(int i =0;i<n;i++){
            sum+=nums[i];
        }
        int target= sum-x;
        if(target==0){
            return n;
        }
        int cursum=0,left=0;
        int ans =INT_MIN;
        for(int i =0;i<n;i++){
            cursum +=nums[i];
            while(left<i && cursum>target){
                cursum-=nums[left];
                left++;
            }
            if(cursum==target){
                ans=max(ans,i-left+1);
            }
        }
        if(ans==INT_MIN){
            return -1;
        }
        return (n-ans);
    }
};