#define ll long long 
class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<ll>>> dungeon(n, vector<vector<ll>>(m, vector<ll> (2)));
        dungeon[0][0][0]= grid[0][0];
        dungeon[0][0][1]=grid[0][0];
        for(int i=0;i<n;i++){
            for(int j =0;j<m;j++){
                if(i==0 && j==0)continue;
                ll mx  = INT_MIN, mi = INT_MAX;
                if(i>0){
                    ll a = dungeon[i-1][j][0] *grid[i][j];
                    ll b = dungeon[i-1][j][1] *grid[i][j];
                     
                    mx=max(mx,max(a,b));
                    mi=min(mi,min(a,b));
                }
                if(j>0){
                    ll a = dungeon[i][j-1][0] *grid[i][j];
                    ll b = dungeon[i][j-1][1] *grid[i][j];
                     
                    mx=max(mx,max(a,b));
                    mi=min(mi,min(a,b));
                }
                dungeon[i][j][0]=mx;
                dungeon[i][j][1]=mi;
            }
        }
        if(dungeon[n-1][m-1][0]<0){
            return -1;
        }
        return dungeon[n-1][m-1][0]%1000000007;
    }
};