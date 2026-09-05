class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> largest(n,LLONG_MIN),smallest(n,LLONG_MAX);
        largest[0]=nums[0];
        smallest[n-1]=nums[n-1];
        int idx=-1;
        for(int i =1;i<n;i++){
            largest[i]=max(largest[i-1],1LL*nums[i]);
        }
        for(int i =n-2;i>=0;i--){
            smallest[i]=min(smallest[i+1],1LL*nums[i]);
        }
        for(int i=0;i<n;i++){
            long long compa = largest[i]-smallest[i];
            if(compa<=k){
                return i;
                // if(idx!=-1){
                //     if(compa<(largest[idx]-smallest[idx])){
                //         idx = i;
                //     }
                // }else{
                //     idx=i;
                // }
            }
        }
        return idx;
    }
};