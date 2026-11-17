class Solution {
public:
    #define ull unsigned long long
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<ull>> dp(n+1,vector<ull>(amount+1,0));
        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }
        for(int i=0;i<n;i++){
            for(int j =1;j<=amount;j++){
                dp[i+1][j] =dp[i][j];
                if(j-coins[i]>=0){
                    dp[i+1][j]+=dp[i+1][j-coins[i]];
                }
            }
        }
        return dp[n][amount];

    }
};