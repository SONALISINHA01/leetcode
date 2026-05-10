class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(n,-1);
        dp[0]=0;
        vector<bool> visited(n,false);
        visited[0]=true;
        for(int i =0;i<n;i++){
            if(visited[i]==false){
                continue;
            }
            for(int j = i+1;j<n;j++){
                if(abs(nums[j]-nums[i])<=target){
                    dp[j]=max(dp[j],dp[i]+1);
                    visited[j]=true;
                }
            }
        }
        return dp[n-1];
    }
};