class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int counter =0;
        int i=0;
        while(coins>0 && i<costs.size()){
            if(costs[i]<=coins){
                counter++;
            }
            coins-=costs[i];
            i++;
        }
        return counter;
    }
};