class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefixsum(n+1,0);
        unordered_map<int,int> mp;
        for(int i =1;i<=n;i++){
            prefixsum[i]=prefixsum[i-1]+nums[i-1];
        }
        mp[0]++;
        int ans =0;
        // unordered_map<int,int> mp;
        for(int i =1;i<n+1;i++){
            if(mp.find(prefixsum[i]-k) != mp.end()){
                ans+=mp[prefixsum[i]-k];
            }
            mp[prefixsum[i]]++;
        }
        return ans;
    }
};