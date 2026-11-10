class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n+1,INT_MAX);
        dp[0]=0;
        for(int i=0;i<n;i++){
            //  if(dp[i]==INT_MAX)continue;
            int one=i+1,two =i+2,three=i+3;
            if(one <=n){
                dp[one]=min(dp[one],dp[i]+costs[one-1]+(one-i)*(one-i));
            }
            if(two <=n){
                dp[two]=min(dp[two],dp[i]+costs[two-1]+(two-i)*(two-i));
            }
            if(three <=n){
                dp[three]=min(dp[three],dp[i]+costs[three-1]+(three-i)*(three-i));
            }
        }
        return dp[n];
    }
};