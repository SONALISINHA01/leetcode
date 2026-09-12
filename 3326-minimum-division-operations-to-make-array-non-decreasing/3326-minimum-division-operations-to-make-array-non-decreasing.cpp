class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        int n=nums.size();
        int num=nums[n-1];
        
        int cnt=0;
        for(int i=n-2;i>=0;i--){
            if(nums[i]>num){
                for(int j=2;j*j<=nums[i];j++){
                    if(nums[i]%j==0){
                        nums[i]=j;
                        cnt++;
                        break;
                    }
                }
            }

            if(nums[i]>num){
                return -1;
            }
            num=nums[i];
        }

        return cnt;
    }
};