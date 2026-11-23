class Solution {
public:
    int minimumTotal(vector<vector<int>>& tri) {
        int n = tri.size();
        vector<vector<int>> dp;
        dp.push_back({tri[0][0]});
        for(int i =0;i<n-1;i++){
            vector<int> temp(tri[i+1].size(),INT_MAX);
            int m = tri[i].size();
            for(int j =0;j<m;j++){
                temp[j]=min(temp[j],dp[i][j]+tri[i+1][j]);
                temp[j+1]=min(temp[j+1],dp[i][j]+tri[i+1][j+1]);
            }
            dp.push_back(temp);
        }
        int ans=INT_MAX;
        for(int i =0;i<dp.size();i++){
            ans= min(ans,dp[n-1][i]);
        }
        return ans;
    }
};