class Solution {
public:
    int count=0;
    bool helper(vector<vector<int>>& grid,vector<vector<int>>&visarray,int n,int m,int i,int j){
        if(i<0 || j <0 || i>=n || j>=m){
            return true;
        }
        if(visarray[i][j]==1){
            return false;
        }
        if(grid[i][j]==0){
            return true;
        }
        visarray[i][j] = 1;
        if(helper(grid,visarray,n,m,i+1,j)){
            count++;
        }
        if(helper(grid,visarray,n,m,i-1,j)){
            count++;
        }
        if(helper(grid,visarray,n,m,i,j+1)){
            count++;
        }
        if(helper(grid,visarray,n,m,i,j-1)){
            count++;
        }
        return false;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int n =grid.size(), m = grid[0].size();
        int a=-1,b=-1;
        vector<vector<int>> visarray(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    a=i,b=j;
                    break;
                }
            }
            if(a!=-1){
                break;
            }
        }
        helper(grid,visarray,n,m,a,b);
        return count;

    }
};