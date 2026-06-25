class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        int r =0,l =0;
        unordered_map<int,int> mp;
        long long win=0,ans=0;
        while(r<n){
            if(mp.find(nums[r])!=mp.end()){
                win+=mp[nums[r]];
            }
            mp[nums[r]]++;
            while(l<r && win>=k){
                win-=mp[nums[l]]-1;
                ans+=(n-r);
                mp[nums[l]]--;
                l++;
            }
            r++;
        }
        return ans;
    }
};