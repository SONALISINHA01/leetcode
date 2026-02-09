class Solution {
public:
    void dfs(vector<vector<char>>& grid,int i, int j){
        if(j>=grid[0].size()|| i>=grid.size()||i<0||j<0){
            return;
        }
        if(grid[i][j]=='0'){
            return;
        }
        grid[i][j]='0';
        dfs(grid,i+1,j+0);
        dfs(grid,i-1,j+0);
        dfs(grid,i,j-1);
        dfs(grid,i,j+1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(), m=grid[0].size();
        int dx[]={1,-1,0,0};
        int dy[]={0,0,-1,1};
        int count=0;
        for(int i=0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j]=='1'){
                    count++;
                    for(int k=0;k<4;k++){
                        dfs(grid,i+dx[k],j+dy[k]);
                    }
                }
            }
        }
        return count;
    }
};