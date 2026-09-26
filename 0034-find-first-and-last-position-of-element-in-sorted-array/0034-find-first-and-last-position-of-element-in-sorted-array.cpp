class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start =0,end = nums.size()-1;
        int firstidx=-1;
        while(start<=end){
            int mid = start +(end-start)/2;
            if(nums[mid]==target){
                firstidx=mid;
                end=mid-1;
            }else if(nums[mid]<target){
                start = mid+1;
            }else{
                end = mid-1;
            }
        }
        int lastidx=-1;
        start=0,end=nums.size()-1;
        while(start<=end){
            int mid = start +(end-start)/2;
            if(nums[mid]==target){
                lastidx = mid;
                start = mid+1;
            }else if(nums[mid]>target){
                end=mid-1;
            }else{
                start = mid+1;
            }
        }
        if(lastidx==-1 || firstidx == -1){
            return {-1,-1};
        }
        return {firstidx,lastidx};
    }
};