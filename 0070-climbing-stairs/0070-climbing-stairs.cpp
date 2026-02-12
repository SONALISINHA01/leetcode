class Solution {
public:
    int climbStairs(int n) {
        vector<int> dparr(n+1,0);
        dparr[0]=1;
        dparr[1]=1;
        for(int i=2;i<=n;i++){
            dparr[i]=dparr[i-1]+dparr[i-2];
        }
        return dparr[n];
    }
};