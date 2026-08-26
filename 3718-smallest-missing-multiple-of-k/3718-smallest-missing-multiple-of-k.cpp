class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int mul = k;
        int j =1;
        sort(nums.begin(),nums.end());
        nums.erase(unique(nums.begin(),nums.end()),nums.end());
        for(int i =0;i<nums.size();i++){
            if(nums[i]%k==0){
                if(nums[i]!=mul){
                    return mul;
                }
                j++;
                mul=k*j;
            }
        }
        return mul;
    }
};