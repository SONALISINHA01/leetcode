class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        bool incre1=false,decre = false,incre2 = false;
        int n = nums.size();
        int i=1;
        if(i>=n){
            return false;
        }
        incre1 = nums[1]>nums[0];
        if(incre1 == false){
            return false;
        }
        while(i<n && nums[i]>nums[i-1]){
            i++;
        }
        if(i>=n){
            return false;
        }
        decre = nums[i]<nums[i-1];
        if(decre == false){
            return false;
        }
        while(i<n && nums[i]<nums[i-1]){
            i++;
        }
        if(i>=n){
            return false;
        }
        incre2 = nums[i]>nums[i-1];
        if(incre2 == false){
            return false;
        }
        
        while(i<n && nums[i]>nums[i-1]){
            i++;
        }
        if(i!=n){
            return false;
        }
        if(incre1 && decre && incre2){
            return true;
        }
        return false;
    }
};