class Solution {
public:
    int climbStairs(int n) {
        vector<int> dparr(n+1,0);
        dparr[1]=1;
        dparr[2]=2;
        for(int i=3;i<=n;i++){
            dparr[i]=dparr[i-1]+dparr[i-2];
        }
        return dparr[n];
    }
};