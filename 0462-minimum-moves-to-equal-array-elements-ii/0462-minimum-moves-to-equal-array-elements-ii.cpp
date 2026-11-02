class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int div;
        if(n%2==1){
            int sz =n/2;
            div = nums[sz];
        }else{
            int sz =n/2;
            int temp =  nums[sz-1]+nums[sz];
            div = temp/2;
        }
        int ans=0;
        for(int i =0;i<n;i++){
            ans+=abs(div-nums[i]);
        }
        return ans;
    }
};