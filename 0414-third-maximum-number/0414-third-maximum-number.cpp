class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.rbegin(),nums.rend());
        int count=0;
        int prev=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=prev){
                count++;
                prev = nums[i];
            }
            if(count ==3){
                return prev;
            }
        }
        return nums[0];
    }
};