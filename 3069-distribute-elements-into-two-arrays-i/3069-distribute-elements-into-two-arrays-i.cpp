class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1, arr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        for(int i =2 ;i<nums.size();i++){
            int sz1 = arr1.size();
            int sz2 = arr2.size();
            if(arr1[sz1-1]>arr2[sz2-1]){
                arr1.push_back(nums[i]);
            }else{
                arr2.push_back(nums[i]);
            }
        }
        vector<int> ans = arr1;
        for(int i = 0;i<arr2.size();i++){
            ans.push_back(arr2[i]);
        }
        return ans;
    }
};