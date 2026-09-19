class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& inter) {
        int n = inter.size();
        vector<vector<int>> ans;
        sort(inter.begin(),inter.end());
        int x = inter[0][0], y= inter[0][1];
        for(int i =1;i<n;i++){
            if(y>=inter[i][0]){
                x = min(x,inter[i][0]);
                y = max(y,inter[i][1]);
            }else{
                ans.push_back({x,y});
                x = inter[i][0];
                y = inter[i][1];
            }
        }
        ans.push_back({x,y});
        return ans;
    }
};