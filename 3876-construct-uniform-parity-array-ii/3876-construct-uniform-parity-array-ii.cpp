class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int n= nums.size();
        sort(nums.begin(),nums.end());
        bool eve =false;

        if(nums[0]%2==0){
            eve= true;
        }
        int sm=nums[0];
        for(int i=1;i<n;i++){
            if(eve){
                if(nums[i]%2!=0){
                    //if(sm>nums[i])return false;
                    int temp = nums[i]-sm;
                    if(temp%2!=0){
                        return false;
                    }
                }else{
                    sm = min(sm,nums[i]);
                }
            }else{
                if(nums[i]%2==0){
                    //if(sm>nums[i])return false;
                    int temp = nums[i]-sm;
                    if(temp%2==0){
                        return false;
                    }
                }else{
                    sm = min(sm,nums[i]);
                }
            }
        }
        return true;
    }
};