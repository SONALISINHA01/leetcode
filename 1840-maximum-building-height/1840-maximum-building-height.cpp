class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& res) {
        res.push_back({1,0});
        res.push_back({n,n-1});
        sort(res.begin(),res.end());
        int m = res.size();
        for(int i=1;i<m;i++){
            res[i][1]=min(res[i][1],res[i-1][1]+(res[i][0]-res[i-1][0]));
        }
        for(int i =m-2;i>=0;i--){
            res[i][1]=min(res[i][1],res[i+1][1]+(res[i+1][0]-res[i][0]));
        }
        int ma =0;
        for(int i=1;i<m;i++){
            int xa = res[i-1][0],ha= res[i-1][1];
            int xb = res[i][0],hb=res[i][1];
            ma= max(ma,(ha+hb+(xb-xa))/2);
        }
        return ma;
    }
};