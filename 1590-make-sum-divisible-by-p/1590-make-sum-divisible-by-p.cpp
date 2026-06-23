class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        vector<long long> pref(n,0);
        pref[0]=nums[0];
        for(int i=1;i<n;i++){
            pref[i]=pref[i-1]+nums[i];
        }
        unordered_map<int,int> mp;
        mp[0]=-1;
        int target = pref[n-1]%p;
        if(target==0){
            return 0;
        }
        int ans = INT_MAX;
        for(int i=0;i<n;i++){
            if(mp.find(((pref[i] % p - target) + p) % p)!=mp.end()){
                // cout<<pref[i]%p - target<<endl;
                ans = min(ans,i-mp[((pref[i] % p - target) + p) % p]);
            }
            mp[pref[i]%p]=i;
        }
        if(ans == INT_MAX||ans==n){
            return -1;
        }
        return ans;
    }
};