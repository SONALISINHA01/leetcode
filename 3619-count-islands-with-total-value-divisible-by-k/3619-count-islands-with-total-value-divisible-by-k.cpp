class Solution {
public:
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    void dfs(vector<vector<int>> &grid,vector<vector<bool>> &visited,int x, int y,long long & ans){
        int n = grid.size();
        int m = grid[0].size();
        for(int i =0;i<4;i++){
            if(x+dx[i]>=0 && x+dx[i]<n && y+dy[i]>=0 && y+dy[i]<m && visited[x+dx[i]][y+dy[i]]==false && grid[x+dx[i]][y+dy[i]] !=0){
                visited[x+dx[i]][y+dy[i]] = true;
                ans += grid[x+dx[i]][y+dy[i]];
                dfs(grid,visited, x+dx[i],y+dy[i],ans);
            }
        
        }
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int count=0;
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(visited[i][j]==false && grid[i][j]!=0){
                    long long ans  = grid[i][j];
                    visited[i][j]=true;
                    dfs(grid,visited,i,j,ans);
                    if(ans%k==0){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};