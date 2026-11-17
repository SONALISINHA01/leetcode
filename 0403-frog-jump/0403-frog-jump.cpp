class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        unordered_map<int,int> ind;
        for(int i =0;i<n;i++){
            ind[stones[i]]=i;
        }
        vector<unordered_set<int>> dp(n);
        dp[0].insert(0);
        for(int i =0;i<n;i++){
            for(auto pos:dp[i]){
                for(int jump = pos-1;jump<=pos+1 ;jump++){
                    if(jump<=0)continue;
                    int next_pos = stones[i]+jump;
                    if(ind.find(next_pos)!=ind.end()){
                        int idx  = ind[next_pos];
                        dp[idx].insert(jump);
                    }
                }
            }
        }
        if(dp[n-1].size()==0){
            return false;
        }
        return true;
    }
};