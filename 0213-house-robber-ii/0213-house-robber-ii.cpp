class Solution {
public:
    int rob(vector<int>& arr) {
        int n = arr.size();
        if(n==1){
            return arr[0];
        }
        vector<int> dparr1(n),dparr2(n);
        dparr1[0]=arr[0];
        dparr1[1]=max(arr[0],arr[1]);
        // dparr2[0]=arr[1];
        for(int i=2;i<n-1;i++){
            dparr1[i]=max(dparr1[i-1],arr[i]+dparr1[i-2]);
        }
        dparr2[0]=0;
        dparr2[1]=arr[1];
        for(int i=2;i<n;i++){
            dparr2[i]=max(dparr2[i-1],arr[i]+dparr2[i-2]);
        }
        return max(dparr1[n-2],dparr2[n-1]);
    }
};