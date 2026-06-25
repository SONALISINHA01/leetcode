class Solution {
public:
    int maxScore(vector<int>& card, int k) {
        int n = card.size();
        int sum=0;
        int rem=n-k;
        vector<int> pre(n,0);
        pre[0]=card[0];
        for(int i =1;i<n;i++){
            pre[i]=pre[i-1]+card[i];
        }
        int ma = INT_MIN;
        if(k==n){
            return pre[n-1];
        }
        int j =-1;
        for(int i=(n-k-1);i<n;i++){
            int tot =0;
            tot+=(pre[n-1]-pre[i]);
            if(j!=-1){
                tot+=pre[j];
            }
            ma = max(ma,tot);
            j++;
        }
        return ma;

    }
};