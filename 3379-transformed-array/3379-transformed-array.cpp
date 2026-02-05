class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> results(n,0);
        for(int i=0;i<n;i++){
            int m =(i+((nums[i]%n+n)%n))%n;
            
            if(m > n-1){
                m=0;
            }
            results[i]=nums[m];
        }
        return results;
    }
};