class Solution {
public:
    int minElement(vector<int>& nums) {
        int n = nums.size();
        int finalans=INT_MAX;
        for(int i=0;i<n;i++){
            string s = to_string(nums[i]);
            int sz = s.size();
            int ans =0;
            for(int j =0;j<sz;j++){
                ans+=s[j]-48;
            }
            finalans=min(finalans, ans);
        }
        return finalans;
    }
};