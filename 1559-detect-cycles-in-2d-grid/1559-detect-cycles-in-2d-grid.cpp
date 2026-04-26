class Solution {
public:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,1,-1};
    bool cycle(vector<vector<char>> &grid,vector<vector<bool>> &visited,int i, int j,int px, int py,char c){
        visited[i][j]=true;
        for(int k=0;k<4;k++){
            int nx = i + dx[k];
            int ny = j + dy[k];
            if(nx>=0 && ny>=0 && nx<grid.size() && ny<grid[0].size() && grid[nx][ny]==c){
                if(visited[nx][ny] && !(nx==px && ny==py))return true;
                if(!visited[nx][ny]){
                    if(cycle(grid,visited,nx,ny,i,j,c)) return true;
                }
            }
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j]){
                    if(cycle(grid,visited,i,j,-1,-1,grid[i][j]))return true;
                }
            }
        }
        return false;
    }
};