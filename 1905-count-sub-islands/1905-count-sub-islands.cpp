class Solution {
public:
    bool dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int n, int m , int i , int j ){
        if(i<0||j<0||i>=n||j>=m){
            return true;
        }
        if(grid2[i][j]==0){
            return true;
        }
        bool issubisland = true;
        if(grid1[i][j]==0){
            issubisland = false;
        }
        grid2[i][j]=0;
        bool one = dfs(grid1,grid2,n,m,i-1,j);
        bool two = dfs(grid1,grid2,n,m,i,j-1);
        bool three = dfs(grid1,grid2,n,m,i,j+1);
        bool four = dfs(grid1,grid2,n,m,i+1,j);
        return issubisland && one && two && three && four;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n =grid1.size();
        int m = grid2.size();
        int count=0;
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid2[i][j]==1){
                    if(dfs(grid1,grid2,n,m,i,j)){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};