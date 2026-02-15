class Solution {
public:
    void maxarea(vector<vector<int>>& grid, int &n, int &m, int i, int j, int& count){
        if(i>=n || j>=m|| i<0 || j<0){
            return;
        }
        if(grid[i][j]==0){
            return ;
        }
        grid[i][j]=0;
        count++;
        maxarea(grid,n,m,i+1,j,count);
        maxarea(grid,n,m,i-1,j,count);
        maxarea(grid,n,m,i,j+1,count);
        maxarea(grid,n,m,i,j-1,count);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans =0;
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                int count =0;
                if(grid[i][j]==1){
                    maxarea(grid,n,m,i,j,count);
                }
                ans = max(ans, count);
            }
        }
        return ans;
    }
};