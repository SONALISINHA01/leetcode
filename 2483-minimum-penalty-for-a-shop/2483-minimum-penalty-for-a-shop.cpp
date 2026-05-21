class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int> suffixy(n+1,0);
        vector<int> prefixn(n+1,0);
        for(int i =0;i<n;i++){
            prefixn[i+1]=prefixn[i]+(customers[i]=='N');
        }
        for(int i= n-1;i>=0;i--){
            suffixy[i]=suffixy[i+1]+(customers[i]=='Y');
        }
        int ans = INT_MAX;
        int idx;
        for(int i=0;i<=n;i++){
            int penalty= (suffixy[i]+prefixn[i]);
            if(ans>penalty){
                ans = penalty;
                idx = i;
            }
        }
        return idx;
    }
};