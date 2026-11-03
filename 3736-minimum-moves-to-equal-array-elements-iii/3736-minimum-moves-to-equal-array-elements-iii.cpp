class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.rbegin(),nums.rend());
        int ans=0;
        int n = nums.size();
        for(int i=1;i<n;i++){
            ans += (nums[0]-nums[i]);
        }
        return ans;
    }
};