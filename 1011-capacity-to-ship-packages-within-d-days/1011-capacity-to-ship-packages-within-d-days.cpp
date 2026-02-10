class Solution {
public:
    bool checker(vector<int>& arr, int k, int n, int mid){
        int sum=0, target=1;
        for(int i=0;i<n;i++){
            if(arr[i]>mid){
                return false;
            }
            if(sum+arr[i]<=mid){
                sum+=arr[i];
            }else{
                sum=arr[i];
                target++;
            }
        }
       return target <= k;

    }
    int shipWithinDays(vector<int>& nums, int k) {
        int n = nums.size();
        int sm =0;
        for(auto it:nums){
            sm+=it;
        }
        int ub = sm, lb=0;
        int ans = sm;
        while(ub>=lb){
            int mid = (ub +lb)/2;
            if(checker(nums,k,n,mid)){
                ans=min(ans,mid);
                ub=mid-1;
            }else{
                lb=mid+1;
            }
        }
        return ans;

    }
};