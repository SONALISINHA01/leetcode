class Solution {
public:
    bool poss(vector<int> &nums,int k,int mid){
        int sum=0;
        int temp=1;
        int i =0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>mid){
                return false;
            }
            if(sum+nums[i]>mid){
                temp++;
                sum=nums[i];
            }else{
                sum+=nums[i];
            }
        }
        return temp<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int sum =0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        int st=0,en=sum;
        int ans=-1;
        while(st<=en){
            int mid = st+(en-st)/2;
            if(poss(nums,k,mid)){
                ans=mid;
                en=mid-1;
            }else{
                st=mid+1;
            }
        }
        return ans;
    }
};