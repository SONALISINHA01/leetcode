class Solution {
public:
    int distinctSubseqII(string s) {
        const int mod =1e9+7;
        int n= s.size();
        vector<int> dp(n+1,0);
        dp[0]=1;
        vector<int> cha(26,-1);
        for(int i=1;i<=n;i++){
            dp[i]=(2*dp[i-1])%mod;
            if(cha[s[i-1]-'a']!=-1){
                dp[i]=(dp[i]-dp[cha[s[i-1]-'a']]+mod)%mod;
            }
            cha[s[i-1]-'a']=i-1;
        }
        return (dp[n]-1+mod)%mod;
    }
};