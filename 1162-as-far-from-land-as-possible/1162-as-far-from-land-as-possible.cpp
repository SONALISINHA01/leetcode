class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                }
            }
        }
        if(q.size()==n*m || q.size()==0) return -1;
        int dist=-1;
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};
        while(!q.empty()){
            int sz = q.size();
            dist++;
            while(sz--){
                auto [i,j]=q.front();
                q.pop();
                for(int k=0;k<4;k++){
                    int nx = i+dx[k], ny = j+dy[k];
                    if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]==0){
                        grid[nx][ny]=1;
                        q.push({nx,ny});
                    }
                }
            }

        }
        return dist;
    }
};