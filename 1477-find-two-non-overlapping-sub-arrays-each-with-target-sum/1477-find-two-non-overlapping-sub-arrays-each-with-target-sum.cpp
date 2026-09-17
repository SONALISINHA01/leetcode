class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size(),j=0,sum=0;
        vector<int> minbestlentillnow(n,INT_MAX);
        int result =INT_MAX;
        int bestlenmin=INT_MAX;
        for(int i =0;i<n;i++){
            sum+=arr[i];
            while(sum>target){
                sum-=arr[j++];
            }
            if(sum==target){
                int len = i-j+1;
                if(j>0 && minbestlentillnow[j-1]!=INT_MAX){
                    result = min(result,minbestlentillnow[j-1]+len);
                }
                bestlenmin = min(bestlenmin,len);
            }
            minbestlentillnow[i]=bestlenmin;
        }
        return result==INT_MAX? -1 :result;
    }
};