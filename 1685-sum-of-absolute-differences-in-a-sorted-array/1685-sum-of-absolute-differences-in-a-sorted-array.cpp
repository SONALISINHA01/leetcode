class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int > left(n),right(n);
        left[n-1]=0;
        for(int i = n-2;i>=0;i--){
            left[i]=left[i+1]+nums[i+1];
        }
        right[0]=0;
        for(int i =1;i<n;i++){
            right[i]= right[i-1]+nums[i-1];
        }
        vector<int> ans(n);
        for(int i =0;i<n;i++){
            ans[i]=abs(right[i]-(i)*nums[i])+(left[i]-(n-i-1)*nums[i]);
        }
        return ans;
    }
};