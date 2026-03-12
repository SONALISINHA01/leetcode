class Solution {
public:
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    int dfs(vector<vector<int>>& matrix, vector<vector<int>> &sequence,int i,int j,int n,int m){
        if(sequence[i][j]!=-1){
            return sequence[i][j];
        }
        int ans =1;
        for(int k=0;k<4;k++){
            int nx = i+dx[k];
            int ny= j+dy[k];
            if(nx<0||ny<0 || nx>=n||ny>=m) continue;
            if(matrix[nx][ny]<=matrix[i][j]) continue;
            ans = max(ans,1+dfs(matrix,sequence,nx,ny,n,m));
        }
        sequence[i][j]=ans;
        return ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> sequence(n, vector<int>(m,-1));
        int ans =0;
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                ans = max(ans,dfs(matrix,sequence,i,j,n,m));
            }
        }
        return ans;
    }
};