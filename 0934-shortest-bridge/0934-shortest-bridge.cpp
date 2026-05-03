class Solution {
public:
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    void dfs(vector<vector<int>>& grid,int &i,int &j){
        int n = grid.size();
        int m = grid.size();
        grid[i][j]=2;
        for(int k=0;k<4;k++){
            int nx= i+dx[k];
            int ny= j+dy[k];
            if(nx>=0&&nx<n&&ny>=0&&ny<m && grid[nx][ny]==1){
                dfs(grid,nx,ny);
            }
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        bool found= false;
        for(int i=0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j]==1){
                    dfs(grid,i,j);
                    found = true;
                    break;
                }
            }
            if(found){
                break;
            }
        }
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        int dist=-1;
        while(!q.empty()){
            int sz=q.size();
            dist++;
            while(sz--){
                auto[i,j]=q.front();
                q.pop();
                for(int k=0;k<4;k++){
                    int nx= i+dx[k];
                    int ny= j+dy[k];
                    if(nx>=0&&nx<n&&ny>=0&&ny<m){
                        if(grid[nx][ny]==1){
                            return dist;
                        }else if(grid[nx][ny]==0){
                            grid[nx][ny]=2;
                            q.push({nx,ny});
                        }
                    }
                }
            }
        }
        return dist;
    }
};