class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(mp.find(nums[i])!=mp.end()){
                int idx = mp[nums[i]];
                if(abs(i-idx)<=k){
                    return true;
                }
            }
            mp[nums[i]]=i;
        }
        return false;
    }
};