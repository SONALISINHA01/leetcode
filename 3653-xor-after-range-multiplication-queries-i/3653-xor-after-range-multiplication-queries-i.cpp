class Solution {
public:
    const long long mod = 1e9 + 7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int q =queries.size();
        for(int i =0;i<q;i++){
            int idx = queries[i][0];
            int r = queries[i][1];
            while(idx<=r){
                nums[idx] = ((long long)nums[idx] * queries[i][3]) % mod;
                idx+=queries[i][2];
            }
        }
        int ans= nums[0];
        int n = nums.size();
        for(int i =1;i<n;i++){
            ans^=nums[i];
        }
        return ans;
    }
};