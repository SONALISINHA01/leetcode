class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int mod = 1000000007;
        int n = s.size();
        vector<long long> prefixsum(n+1,0),prefixnum(n+1),numcount(n+1,0);
        for(int i =1;i<=n;i++){
            prefixsum[i]=(prefixsum[i-1]+s[i-1]-'0')%mod;
            numcount[i]=numcount[i-1];
            prefixnum[i]=prefixnum[i-1];
            if(s[i-1]!='0'){
                numcount[i]++;
                prefixnum[i]=(prefixnum[i]*10 +(s[i-1]-'0'))%mod;
            }
        }
        vector<long long> power10(n+1, 1);
        for(int i = 1; i <= n; i++){
            power10[i] = (power10[i-1] * 10) % mod;
        }
        int m = queries.size();
        vector<int> ans;
        for(int i=0;i<m;i++){
            int y = queries[i][1], x = queries[i][0];
            int sum = prefixsum[y+1]-prefixsum[x];
            int mul=1;
            int cnt = numcount[y+1] - numcount[x];
            mul = (prefixnum[y+1] - 1LL * prefixnum[x] * power10[cnt] % mod + mod) % mod;
            ans.push_back((1LL*mul*sum)%mod);
        }
        return ans;
    }
};