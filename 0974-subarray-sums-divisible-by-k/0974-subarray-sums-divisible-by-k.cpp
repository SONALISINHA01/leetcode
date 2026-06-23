class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefixsum(n,0);
        prefixsum[0]=nums[0];
        for(int i =1;i<n;i++){
            prefixsum[i]=prefixsum[i-1]+nums[i];
        }
        unordered_map<int,int> count;
        int ans =0;
        count[0]=1;
        for(int i =0;i<n;i++){
            if(prefixsum[i]<0){
                prefixsum[i]=((prefixsum[i]%k)+k)%k;
            }
            if(count.find(prefixsum[i]%k)!=count.end()){
                ans+=count[prefixsum[i]%k];
            }
            count[prefixsum[i]%k]++;
        }
        return ans;
    }
};