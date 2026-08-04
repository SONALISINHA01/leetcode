class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        int mi =INT_MAX;
        int ma = INT_MIN;
        int n = nums.size();
        for(int i =0;i<n;i++){
            mi = min(mi, nums[i]);
            ma = max(ma,nums[i]);
        }
        sort(nums.begin(),nums.end());
        int i =0;
         while (mi < ma) {
            while (i < nums.size() && nums[i] < mi)
                i++;

            if (i < nums.size() && nums[i] == mi) {
                mi++;
                i++;
            } else {
                ans.push_back(mi);
                mi++;
            }
        }
        return ans;
    }
};