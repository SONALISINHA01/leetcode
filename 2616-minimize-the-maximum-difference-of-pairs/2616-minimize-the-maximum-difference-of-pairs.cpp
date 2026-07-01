class Solution {
public:
    bool poss(int mid,vector<int> &nums,int p){
        int n = nums.size();
        for(int i =0;i<n-1;){
            if(nums[i+1]-nums[i]<=mid){
                p--;
                i+=2;
            }else{
                i++;
            }
            if(p==0){
                return true;
            }
        }
        return false;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int st =0,en=0;
        int n = nums.size();
        int mi =INT_MAX;
        for(int i =0;i<n;i++){
            en = max(nums[i],en);
            mi = min(nums[i],mi);
        }
        int mid;
        int ans =0;
        while(st<=en){
            mid = (en-st)/2 +st;
            if(poss(mid,nums,p)){
                ans =mid;
                en = mid-1;
            }else{
                st= mid+1;
            }
        }
        return ans;
    }
};