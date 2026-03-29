class Solution {
public:
    bool check(vector<int>& nums, int k, int d){
        int n = nums.size();
        int j =0;
        int cnt =0;
        for(int i =0;i<n;i++){
            while(j<n && nums[j]<nums[i]+d)j++;
            cnt+=(j-1)-i;
        }
        if(cnt>=k){
            return true;
        }
        return false;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int l =-1, r=1000001;
        while(l+1<r){
            int mid = (r-l)/2+l;
            if(check(nums,k,mid)){
                r = mid;
            }else{
                l = mid;
            }
        }
        return r-1;
    }
};