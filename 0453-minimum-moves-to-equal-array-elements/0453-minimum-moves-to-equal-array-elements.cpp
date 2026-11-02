class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int st = nums[0];
        int ans=0;
        for(int i =0;i<n;i++){
            ans += abs(st-nums[i]);
        }
        return ans;
    }
};