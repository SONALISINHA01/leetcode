class Solution {
public:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    void converter(vector<vector<int>>& grid,int n, int m, int i, int j){
        if(i<0||j<0||i>=n||j>=m){
            return ;
        }
        if(grid[i][j]==0){
            return;
        }
        grid[i][j]=0;
        for(int k =0;k<4;k++){
            converter(grid,n,m,i+dx[k],j+dy[k]);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for(int j =0;j<m;j++){
            if(grid[0][j]==1){
                converter(grid,n,m,0,j);
            }
            if(grid[n-1][j]==1){
                converter(grid,n,m,n-1,j);
            }
        }
        for(int i =0;i<n;i++){
            if(grid[i][0]==1){
                converter(grid,n,m,i,0);
            }
            if(grid[i][m-1]==1){
                converter(grid,n,m,i,m-1);
            }
        }
        int ans =0;
        for(int i=0;i<n;i++){
            for(int j =0;j<m; j++){
                if(grid[i][j]==1){
                    ans++;
                }
            }
        }
        return ans;

    }
};