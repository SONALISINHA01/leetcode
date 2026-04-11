class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        for(int i =0;i<n-2;i++){
            int num=nums[i];
            int count =0;
            for(int j = i+1;j<n;j++){
                if(nums[j]==num){
                    count++;
                }
                if(count==2){
                    ans=min(ans,2*(j-i));
                }
            }
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};