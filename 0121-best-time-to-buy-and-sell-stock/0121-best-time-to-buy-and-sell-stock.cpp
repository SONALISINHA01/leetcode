class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> buy(n);
        buy[0]=prices[0];
        for(int i =1;i<n;i++){
            buy[i]=min(buy[i-1],prices[i]);
        }
        vector<int> sell(n);
        sell[n-1]=prices[n-1];
        for(int i=n-2;i>=0;i--){
            sell[i]=max(sell[i+1],prices[i]);
        }
        vector<int> profit(n);
        for(int i=0;i<n;i++){
            if(sell[i]-buy[i]<0){
                profit[i]=0;
            }else{
                profit[i]= sell[i]-buy[i];
            }
        }
        sort(profit.rbegin(),profit.rend());
        return profit[0];
    }
};