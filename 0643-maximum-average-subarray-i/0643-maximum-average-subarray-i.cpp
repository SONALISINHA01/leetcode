class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans =0.0;
        for(int i =0;i<k;i++){
            ans+=nums[i];
        }
        double finalans = ans/(double)k;
        for(int i =k;i<nums.size();i++){
            ans+=nums[i];
            ans-=nums[i-k];
            finalans = max(finalans,ans/(double)k);
        }
        return finalans;
    }
};