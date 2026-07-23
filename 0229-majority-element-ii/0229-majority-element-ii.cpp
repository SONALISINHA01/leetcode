class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        if(nums.size()==0){
            return {};
        }
        sort(nums.begin(),nums.end());
        vector<int> ans;
        int curr=nums[0];
        int j =0,i=1;
        while(i<nums.size()){
            if(nums[i]!=curr){
                int temp = nums.size()/3;
                if(temp<(i-j)){
                    ans.push_back(curr);
                }
                curr = nums[i];
                j=i;
            }
            i++;
        }
        int temp = nums.size()/3;
        if(temp<(i-j)){
            ans.push_back(curr);
        }
        return ans;
    }
};