class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>> dp(n);
        //dp[0].push_back(nums[0]);
        for(int i =0;i<n;i++){
            int curridx=-1;
            for(int j =0;j<=i;j++){
                if(nums[i]%nums[j]==0){
                    if(curridx==-1){
                        curridx=j;
                    }
                    else if(dp[j].size()>dp[curridx].size()){
                        curridx = j;
                    }
                }
            }
            if(curridx!=-1) dp[i]=dp[curridx];
            dp[i].push_back(nums[i]);
        }
        int idx=0;
        for(int i =0;i<n;i++){
            if(dp[idx].size()<dp[i].size()){
                idx= i;
            }
        }
        return dp[idx];
    }
};