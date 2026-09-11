class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        vector<bool> prime(n+1, true);
        prime[0]=false;
        prime[1]=false;
        for(long long i =2;i<=n;i++){
            if(prime[i]){
                for(long long j = i*i;j<=n;j+=i){
                    prime[j]=false;
                }
            }
        }
        vector<vector<int>> ans;
        for(int i =2;i<=n;i++){
            if(prime[i] && prime[n-i]){
                if(i<=n-i) ans.push_back({i,n-i});
            }
        }
        return ans;
    }
};