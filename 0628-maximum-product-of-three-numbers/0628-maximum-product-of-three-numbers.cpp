class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.rbegin(),nums.rend());
        int ans=1;
        int i =0, j = nums.size()-1;
        int ans1=nums[j-1]*nums[j];
        ans1*=nums[i];
        int ans2 = nums[0]*nums[1];
        ans2*=nums[2];
        return (ans1>ans2)?ans1:ans2;
    }
};