class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dparr(n,INT_MAX);
        dparr[0]=0;
        for(int i =0;i<n;i++){
            int dist = nums[i];
            int j =i+1;
            while(j<n && dist>0){
                dparr[j]=min(dparr[j],dparr[i]+1);
                j++;
                dist--;
            }
        }
        return dparr[n-1];
    }
};