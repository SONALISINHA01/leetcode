class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        vector<int> ans;
        int n = nums.size();
        vector<int> negfreq(50,0);
        for(int i =0;i<k;i++){
            if(nums[i]<0){
                negfreq[nums[i]+50]++;
            }
        }
        int temp=x;
        bool found = false;
        for(int i=0;i<50;i++){
            temp -=negfreq[i];
            if(temp<=0){
                ans.push_back(i-50);
                found=true;
                break;
            }
        }
        if(!found)ans.push_back(0);

        for(int i=k;i<nums.size();i++){
            if(nums[i-k]<0){
                negfreq[nums[i-k]+50]--;
            }
            if(nums[i]<0){
                negfreq[nums[i]+50]++;
            }
            temp=x;
            found = false;
            for(int j=0;j<50;j++){
                temp -=negfreq[j];
                if(temp<=0){
                    ans.push_back(j-50);
                    found=true;
                    break;
                }
            }
            if(!found)ans.push_back(0);
        }
        return ans;
    }
};