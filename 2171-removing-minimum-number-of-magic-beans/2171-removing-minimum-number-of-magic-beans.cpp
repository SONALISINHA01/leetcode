class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        int n = beans.size();
        vector<long long> prefixsum(n,0);
        sort(beans.begin(),beans.end());
        prefixsum[0]=beans[0];
        for(int i =1;i<n;i++){
            prefixsum[i]=prefixsum[i-1]+beans[i];
        }
        long long ans = LLONG_MAX;
        for(int i=0;i<n;i++){
            long long temp=0;
            if(i>0){
                temp+=prefixsum[i-1];
            }
            temp+=abs((prefixsum[n-1]-prefixsum[i])-1LL*beans[i]*(n-1-i));
            ans=min(temp,ans);
        }
        return ans;
    }
};