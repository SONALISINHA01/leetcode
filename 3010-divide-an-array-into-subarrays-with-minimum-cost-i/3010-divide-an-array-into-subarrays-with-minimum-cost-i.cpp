class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n= nums.size();
        int one=nums[0];
        int second, third;
        nums[0] = INT_MAX;
        sort(nums.begin(),nums.end());
        second=nums[0];
        third = nums[1];
        return one+second+third;
    }
};