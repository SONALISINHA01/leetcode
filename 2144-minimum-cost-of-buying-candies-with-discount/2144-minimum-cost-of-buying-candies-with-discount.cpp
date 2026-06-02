class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.rbegin(),cost.rend());
        int n = cost.size();
        bool first=false, sec=false;
        int ans=0;
        for(int i=0;i<n;i++){
            if(first&&sec){
                first = false;
                sec= false;
                continue;
            }else{
                ans+=cost[i];
                if(first){
                    sec=true;
                }else{
                    first=true;
                }
            }
        }
        return ans;
    }
};