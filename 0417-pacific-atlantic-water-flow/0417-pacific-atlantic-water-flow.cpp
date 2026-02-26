class Solution {
public:
    int dx[4]={0,0,-1,1};
    int dy[4]={-1,1,0,0};
    void dfs(vector<vector<int>> &heights,vector<vector<int>>& visit,int n ,int m , int i, int j, int prev){
        if(i>=n||j>=m||i<0||j<0){
            return;
        }
        if(heights[i][j]<prev){
            return;
        }
        if(visit[i][j]==1){
            return;
        }
        visit[i][j]=1;
        prev = heights[i][j];
        for(int k =0;k<4;k++){
            dfs(heights,visit,n,m,i+dx[k],j+dy[k],prev);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> visitpac(n, vector<int>(m,0));
        vector<vector<int>> visitatl(n, vector<int>(m,0));
        for(int j =0;j<m;j++){
            dfs(heights,visitpac,n,m,0,j,heights[0][j]);
            dfs(heights,visitatl,n,m,n-1,j,heights[n-1][j]);
        }
        for(int i =0;i<n;i++){
            dfs(heights,visitpac,n,m,i,0,heights[i][0]);
            dfs(heights,visitatl,n,m,i,m-1,heights[i][m-1]);
        }
        vector<vector<int>> ans;
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(visitpac[i][j]==1 && visitatl[i][j]==1){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};