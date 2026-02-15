class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        int norottenoranges=0;
        int freshoranges=0;
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                    norottenoranges++;
                }else if(grid[i][j] == 1){
                    freshoranges++;
                }
            }
        }
        if(freshoranges == 0) return 0;
        int initialrotten = norottenoranges;
        int sec =0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto [i,j] = q.front();
                q.pop();
                for(int k =0;k<4;k++){
                    if(i+dx[k]>=0 && j+dy[k]>=0 && i+dx[k]<n && j+dy[k]<m){
                        if(grid[i+dx[k]][j+dy[k]]==1){
                            q.push({i+dx[k], j+dy[k]});
                            grid[i+dx[k]][j+dy[k]] = 2;
                            norottenoranges++;
                        }
                    }
                }
            }
            sec++;
        }
        sec--;
        if(norottenoranges - initialrotten == freshoranges){
            return sec;
        }
        return -1;
    }
};